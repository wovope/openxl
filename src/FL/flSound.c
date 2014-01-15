#include "XL/FL/xlflut.h"
#include "XL/xl.h"

#define AVCODEC_MAX_AUDIO_FRAME_SIZE 1024

void
av_pq_init(AVPacketQueue *pq)
{
	memset(pq, 0, sizeof(AVPacketQueue));
}

void
av_pq_free(AVPacketQueue *pq)
{
	AVPacketList *pkl, *p;
	for(pkl = pq->first; pkl; pkl = p)
	{
		p = pkl->next;
		av_free_packet(&pkl->pkt);
		av_freep(&pkl);
	}
	pq->last = pq->first = NULL;
}

void
av_pq_put(AVPacketQueue *pq, AVPacket *pkt)
{
	AVPacketList *pkl;
	av_dup_packet(pkt);
	pkl = (AVPacketList *) av_malloc(sizeof(AVPacketList));
	pkl->pkt = *pkt;
	pkl->next = NULL;
	if(!pq->last) pq->first = pkl;
	else pq->last->next = pkl;
	pq->last = pkl;
}

int
av_pq_get(AVPacketQueue *pq, AVPacket *pkt)
{
	AVPacketList *pkl;
	pkl = pq->first;
	if(pkl)
	{
		pq->first = pkl->next;
		if(!pq->first) pq->last = NULL;
		*pkt = pkl->pkt;
		av_free(pkl);
		return 1;
	}
	else
		return 0;
}

void
av_init(void)
{
	avcodec_register_all();
	av_register_all();
	av_log_set_level(AV_LOG_QUIET);
}

int
av_pq_bufget(FLsound *sound, AVPacketQueue *pq, AVPacket *pkt)
{
	int ret;
	while(!(ret = av_pq_get(pq, pkt)) && !(sound->end = (av_read_frame(sound->fc, pkt) < 0)))
	{
		if(pkt->stream_index == sound->audio.sti) av_pq_put(&sound->audio.pq, pkt);
		else av_free_packet(pkt);
	}
	return ret;
}

static
int
my_audio_get_buffer(struct AVCodecContext *cc, AVFrame *frm)
{
	int ret;
	ret = avcodec_default_get_buffer(cc, frm);
	frm->opaque = av_malloc(sizeof(double));
	* (uint64_t *) frm->opaque = ((FLsound *) cc->opaque)->audio.pktprc.pts;
	return ret;
}

static
void
my_release_buffer(struct AVCodecContext *cc, AVFrame *frm)
{
	if(frm) av_freep(&frm->opaque);
	avcodec_default_release_buffer(cc, frm);
}

static
AVSampleFormat
av_alSampleFormat(unsigned int format)
{
	switch(format)
	{
		case AL_FORMAT_MONO8:
		case AL_FORMAT_STEREO8:
#ifdef AL_EXT_MCFORMATS
		case AL_FORMAT_QUAD8:
		case AL_FORMAT_51CHN8:
		case AL_FORMAT_61CHN8:
		case AL_FORMAT_71CHN8:
#endif
			return AV_SAMPLE_FMT_U8;
			break;
		case AL_FORMAT_MONO16:
		case AL_FORMAT_STEREO16:
#ifdef AL_EXT_MCFORMATS
		case AL_FORMAT_QUAD16:
		case AL_FORMAT_51CHN16:
		case AL_FORMAT_61CHN16:
		case AL_FORMAT_71CHN16:
#endif
		default:
			return AV_SAMPLE_FMT_S16;
			break;
#if defined(AL_EXT_float32) || defined(AL_EXT_MCFORMATS) || defined(AL_EXT_double)
#ifdef AL_EXT_float32
		case AL_FORMAT_MONO_FLOAT32:
		case AL_FORMAT_STEREO_FLOAT32:
#endif
#ifdef AL_EXT_MCFORMATS
		case AL_FORMAT_QUAD32:
		case AL_FORMAT_51CHN32:
		case AL_FORMAT_61CHN32:
		case AL_FORMAT_71CHN32:
#endif
			return AV_SAMPLE_FMT_FLT;
			break;
#ifdef AL_EXT_double
		case AL_FORMAT_MONO_DOUBLE_EXT:
		case AL_FORMAT_STEREO_DOUBLE_EXT:
#endif
			return AV_SAMPLE_FMT_DBL;
			break;
#endif
	}
}

static
int
av_alChannelLayout(unsigned int format)
{
	switch(format)
	{
		case AL_FORMAT_MONO8:
		case AL_FORMAT_MONO16:
#ifdef AL_EXT_float32
		case AL_FORMAT_MONO_FLOAT32:
#endif
#ifdef AL_EXT_double
		case AL_FORMAT_MONO_DOUBLE_EXT:
#endif
			return AV_CH_LAYOUT_MONO;
			break;
		case AL_FORMAT_STEREO8:
		case AL_FORMAT_STEREO16:
#ifdef AL_EXT_float32
		case AL_FORMAT_STEREO_FLOAT32:
#endif
#ifdef AL_EXT_double
		case AL_FORMAT_STEREO_DOUBLE_EXT:
#endif
		default:
			return AV_CH_LAYOUT_STEREO;
			break;
#ifdef AL_EXT_MCFORMATS
		case AL_FORMAT_QUAD8:
		case AL_FORMAT_QUAD16:
		case AL_FORMAT_QUAD32:
			return AV_CH_LAYOUT_QUAD;
			break;
		case AL_FORMAT_51CHN8:
		case AL_FORMAT_51CHN16:
		case AL_FORMAT_51CHN32:
			return AV_CH_LAYOUT_5POINT1;
			break;
		case AL_FORMAT_61CHN8:
		case AL_FORMAT_61CHN16:
		case AL_FORMAT_61CHN32:
			return AV_CH_LAYOUT_6POINT1;
			break;
		case AL_FORMAT_71CHN8:
		case AL_FORMAT_71CHN16:
		case AL_FORMAT_71CHN32:
			return AV_CH_LAYOUT_7POINT1;
		break;
#endif
	}
}

static
int
alChannels(unsigned int format)
{
	switch(format)
	{
		case AL_FORMAT_MONO8:
		case AL_FORMAT_MONO16:
#ifdef AL_EXT_float32
		case AL_FORMAT_MONO_FLOAT32:
#endif
#ifdef AL_EXT_double
		case AL_FORMAT_MONO_DOUBLE_EXT:
#endif
			return 1;
			break;
		case AL_FORMAT_STEREO8:
		case AL_FORMAT_STEREO16:
#ifdef AL_EXT_float32
		case AL_FORMAT_STEREO_FLOAT32:
#endif
#ifdef AL_EXT_double
		case AL_FORMAT_STEREO_DOUBLE_EXT:
#endif
		default:
			return 2;
			break;
#ifdef AL_EXT_MCFORMATS
		case AL_FORMAT_QUAD8:
		case AL_FORMAT_QUAD16:
		case AL_FORMAT_QUAD32:
			return 4;
			break;
		case AL_FORMAT_51CHN8:
		case AL_FORMAT_51CHN16:
		case AL_FORMAT_51CHN32:
			return 6;
			break;
		case AL_FORMAT_61CHN8:
		case AL_FORMAT_61CHN16:
		case AL_FORMAT_61CHN32:
			return 7;
			break;
		case AL_FORMAT_71CHN8:
		case AL_FORMAT_71CHN16:
		case AL_FORMAT_71CHN32:
			return 8;
			break;
#endif
	}
}

static
unsigned int
al_av_get_format(AVSampleFormat format, unsigned int channels)
{
	switch(format)
	{
		case AV_SAMPLE_FMT_U8:
			switch(channels)
			{
				case 1:
					return AL_FORMAT_MONO8;
					break;
				case 2:
				default:
					return AL_FORMAT_STEREO8;
					break;
#ifdef AL_EXT_MCFORMATS
				case 4:
					return AL_FORMAT_QUAD8;
					break;
				case 6:
					return AL_FORMAT_51CHN8;
					break;
				case 7:
					return AL_FORMAT_61CHN8;
					break;
				case 8:
					return AL_FORMAT_71CHN8;
					break;
#endif
			}
			break;
		case AV_SAMPLE_FMT_S16:
		default:
			switch(channels)
			{
				case 1:
					return AL_FORMAT_MONO16;
					break;
				case 2:
				default:
					return AL_FORMAT_STEREO16;
					break;
#ifdef AL_EXT_MCFORMATS
				case 4:
					return AL_FORMAT_QUAD16;
					break;
				case 6:
					return AL_FORMAT_51CHN16;
					break;
				case 7:
					return AL_FORMAT_61CHN16;
					break;
				case 8:
					return AL_FORMAT_71CHN16;
					break;
#endif
			}
			break;
#if defined(AL_EXT_float32) || defined(AL_EXT_MCFORMATS)
		case AV_SAMPLE_FMT_FLT:
			switch(channels)
			{
#ifdef AL_EXT_float32
				case 1:
					return AL_FORMAT_MONO_FLOAT32;
					break;
				case 2:
				default:
					return AL_FORMAT_STEREO_FLOAT32;
					break;
#endif
#ifdef AL_EXT_MCFORMATS
				case 4:
					return AL_FORMAT_QUAD32;
					break;
				case 6:
					return AL_FORMAT_51CHN32;
					break;
				case 7:
					return AL_FORMAT_61CHN32;
					break;
				case 8:
					return AL_FORMAT_71CHN32;
					break;
#endif
			}
			break;
#endif
#ifdef AL_EXT_double
		case AV_SAMPLE_FMT_DBL:
			switch(channels)
			{
				case 1:
					return AL_FORMAT_MONO_DOUBLE_EXT;
					break;
				case 2:
				default:
					return AL_FORMAT_STEREO_DOUBLE_EXT;
					break;
			}
			break;
#endif
	}
	return 0;
}

void
flSoundLoad(FLsound *sound, int wanted, int related, const char *filepath)
{
	sound->fc = NULL;
	avformat_open_input(&sound->fc, filepath, NULL, NULL);
	avformat_find_stream_info(sound->fc, NULL);
	sound->audio.sti = av_find_best_stream(sound->fc, AVMEDIA_TYPE_AUDIO, wanted, related, NULL, 0);
	sound->audio.cc = sound->fc->streams[sound->audio.sti]->codec;
	sound->audio.codec = avcodec_find_decoder(sound->audio.cc->codec_id);
	avcodec_open2(sound->audio.cc, sound->audio.codec, NULL);
	sound->audio.frm = avcodec_alloc_frame();
	sound->audio.rc = NULL;
	sound->audio.size = av_samples_get_buffer_size(NULL, sound->audio.cc->channels, sound->fc->streams[sound->audio.sti]->duration * av_q2d(sound->fc->streams[sound->audio.sti]->time_base) * 1000000.0, sound->audio.cc->sample_fmt, 1);
	memset(&sound->audio.pktprc, 0, sizeof(AVPacket));
	av_pq_init(&sound->audio.pq);
	sound->audio.cc->opaque = (void *) sound;
	sound->audio.cc->get_buffer = my_audio_get_buffer;
	sound->audio.cc->release_buffer = my_release_buffer;
	sound->audio.bfrsmp = 0;
	sound->audio.rdy = 0;
	sound->audio.end = 0;
	sound->end = 0;

	sound->audio.format = al_av_get_format(sound->audio.cc->sample_fmt, sound->audio.cc->channels);
	sound->audio.freq = sound->audio.cc->sample_rate;
}

void
flSoundLoadDefault(FLsound *sound, const char *filepath)
{
	flSoundLoad(sound, -1, -1, filepath);
}

void
flSoundInform(FLsound *sound, ALenum *format, ALsizei *freq)
{
	if(format) *format = sound->audio.format;
	if(freq) *freq = sound->audio.freq;
}

void
flSoundConvert(FLsound *sound, ALenum format, ALsizei freq)
{
	sound->audio.format = format;
	sound->audio.freq = freq;

	sound->audio.rc = swr_alloc_set_opts(NULL, av_alChannelLayout(sound->audio.format), av_alSampleFormat(sound->audio.format), sound->audio.freq, sound->audio.cc->channel_layout, sound->audio.cc->sample_fmt, sound->audio.cc->sample_rate, 0, NULL);
	swr_init(sound->audio.rc);
}

void
flSoundUnload(FLsound *sound)
{
	av_pq_free(&sound->audio.pq);
	swr_free(&sound->audio.rc);
	av_free(sound->audio.frm);
	avcodec_close(sound->audio.cc);
	avformat_close_input(&sound->fc);
}

unsigned int
flSoundFrequency(FLsound *sound)
{
	return sound->audio.cc->sample_rate;
}

unsigned int
flSoundChannels(FLsound *sound)
{
	return sound->audio.cc->channels;
}

unsigned int
flSoundSize(FLsound *sound)
{
	return sound->audio.size;
}

unsigned int
flSoundSampleSize(FLsound *sound)
{
	return av_get_bytes_per_sample(sound->audio.cc->sample_fmt);
}

float
flSoundDuration(FLsound *sound)
{
	return sound->fc->streams[sound->audio.sti]->duration * av_q2d(sound->fc->streams[sound->audio.sti]->time_base);
}

unsigned int
flSoundSamples(FLsound *sound)
{
	return ((uint64_t) (sound->audio.cc->sample_rate * (sound->fc->streams[sound->audio.sti]->duration * av_q2d(sound->fc->streams[sound->audio.sti]->time_base))));
}


unsigned int
flSoundFormat(FLsound *sound)
{
	return al_av_get_format(sound->audio.cc->sample_fmt, sound->audio.cc->channels);
}

unsigned int
flSoundReadSamples(FLsound *sound, uint8_t *buffer)
{
	return flSoundReadChunk(sound, sound->audio.size, buffer);
}

void
flSoundBufferData(FLsound *sound, ALuint bfr)
{
	flSoundBufferChunk(sound, sound->audio.size, bfr);
}

void
flSoundConvertBufferData(FLsound *sound, ALuint bfr)
{
	flSoundConvertBufferChunk(sound, sound->audio.size, bfr);
}

unsigned int
flSoundEnd(FLsound *sound)
{
	return sound->audio.end;
}

unsigned int
flSoundReadChunk(FLsound *sound, unsigned int size, uint8_t *buffer)
{
	int smp, len, chunk;
	
	chunk = 0;
	smp = size / (av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels);
	sound->audio.bfrsmp = 0;
	sound->audio.buffer = buffer; //av_malloc(size + AVCODEC_MAX_AUDIO_FRAME_SIZE);
	while(!chunk && !(sound->audio.end = !(sound->audio.pktprc.size || av_pq_bufget(sound, &sound->audio.pq, &sound->audio.pkt))))
	{
		if(!sound->audio.pktprc.size) sound->audio.pktprc = sound->audio.pkt;
		len = avcodec_decode_audio4(sound->audio.cc, sound->audio.frm, &sound->audio.rdy, &sound->audio.pktprc);
		if(len > 0) { sound->audio.pktprc.data += len; sound->audio.pktprc.size -= len; }
		if(len < 0 || !sound->audio.pktprc.size) { av_free_packet(&sound->audio.pkt); memset(&sound->audio.pktprc, 0, sizeof(AVPacket)); }
		if(sound->audio.rdy)
		{
			sound->audio.frms++;
			if(!sound->audio.bfrsmp)
			{
				if(sound->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) sound->audio.frm->opaque != AV_NOPTS_VALUE) sound->audio.pts = * (uint64_t *) sound->audio.frm->opaque;
				else if(sound->audio.frm->pts != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->pts;
				else sound->audio.pts = sound->audio.frms;
			}
			memcpy(sound->audio.buffer + sound->audio.bfrsmp * av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels, sound->audio.frm->data[0], sound->audio.frm->nb_samples * av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels);
			sound->audio.bfrsmp += sound->audio.frm->nb_samples;
			if(sound->audio.bfrsmp >= smp)
				chunk = 1;
			sound->audio.rdy = 0;
		}
	}
	//alBufferData(bfr, sound->audio.format, sound->audio.buffer, sound->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(sound->audio.format)) * alChannels(sound->audio.format), sound->audio.freq);
	//av_free(sound->audio.buffer);
	return sound->audio.bfrsmp;
}

unsigned int
flSoundBufferChunk(FLsound *sound, unsigned int size, ALuint bfr)
{
	int smp, len, chunk;
	
	chunk = 0;
	smp = size / (av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels);
	sound->audio.bfrsmp = 0;
	sound->audio.buffer = av_malloc(size + AVCODEC_MAX_AUDIO_FRAME_SIZE);
	while(!chunk && !(sound->audio.end = !(sound->audio.pktprc.size || av_pq_bufget(sound, &sound->audio.pq, &sound->audio.pkt))))
	{
		if(!sound->audio.pktprc.size) sound->audio.pktprc = sound->audio.pkt;
		len = avcodec_decode_audio4(sound->audio.cc, sound->audio.frm, &sound->audio.rdy, &sound->audio.pktprc);
		if(len > 0) { sound->audio.pktprc.data += len; sound->audio.pktprc.size -= len; }
		if(len < 0 || !sound->audio.pktprc.size) { av_free_packet(&sound->audio.pkt); memset(&sound->audio.pktprc, 0, sizeof(AVPacket)); }
		if(sound->audio.rdy)
		{
			sound->audio.frms++;
			if(!sound->audio.bfrsmp)
			{
				if(sound->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) sound->audio.frm->opaque != AV_NOPTS_VALUE) sound->audio.pts = * (uint64_t *) sound->audio.frm->opaque;
				else if(sound->audio.frm->pts != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->pts;
				else sound->audio.pts = sound->audio.frms;
			}
			memcpy(sound->audio.buffer + sound->audio.bfrsmp * av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels, sound->audio.frm->data[0], sound->audio.frm->nb_samples * av_get_bytes_per_sample(sound->audio.cc->sample_fmt) * sound->audio.cc->channels);
			sound->audio.bfrsmp += sound->audio.frm->nb_samples;
			if(sound->audio.bfrsmp >= smp)
				chunk = 1;
			sound->audio.rdy = 0;
		}
	}
	alBufferData(bfr, sound->audio.format, sound->audio.buffer, sound->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(sound->audio.format)) * alChannels(sound->audio.format), sound->audio.freq);
	av_free(sound->audio.buffer);
	return sound->audio.bfrsmp;
}

unsigned int
flSoundConvertBufferChunk(FLsound *sound, unsigned int size, ALuint bfr)
{
	int smp, len, chunk;

	chunk = 0;
	smp = size / (av_get_bytes_per_sample(av_alSampleFormat(sound->audio.format)) * alChannels(sound->audio.format));
	sound->audio.bfrsmp = 0;
	sound->audio.buffer = av_malloc((size + AVCODEC_MAX_AUDIO_FRAME_SIZE));
	while(!chunk && !(sound->audio.end = !(sound->audio.pktprc.size || av_pq_bufget(sound, &sound->audio.pq, &sound->audio.pkt))))
	{
		if(!sound->audio.pktprc.size) sound->audio.pktprc = sound->audio.pkt;
		len = avcodec_decode_audio4(sound->audio.cc, sound->audio.frm, &sound->audio.rdy, &sound->audio.pktprc);
		if(len > 0) { sound->audio.pktprc.data += len; sound->audio.pktprc.size -= len; }
		if(len < 0 || !sound->audio.pktprc.size) { av_free_packet(&sound->audio.pkt); memset(&sound->audio.pktprc, 0, sizeof(AVPacket)); }
		if(sound->audio.rdy)
		{
			const uint8_t *in[] = { sound->audio.frm->data[0] };
			uint8_t *out[] = { sound->audio.buffer + sound->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(sound->audio.format)) * alChannels(sound->audio.format) };
			sound->audio.frms++;
			if(!sound->audio.bfrsmp)
			{
				if(sound->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) sound->audio.frm->opaque != AV_NOPTS_VALUE) sound->audio.pts = * (uint64_t *) sound->audio.frm->opaque;
				else if(sound->audio.frm->pts != AV_NOPTS_VALUE) sound->audio.pts = sound->audio.frm->pts;
				else sound->audio.pts = sound->audio.frms;
			}
			len = swr_convert(sound->audio.rc, out, smp, in, sound->audio.frm->nb_samples);
			if(len > 0) sound->audio.bfrsmp += len;
			//if(av_samples_get_buffer_size(NULL, alChannels(sound->audio.format), sound->audio.bfrsmp, av_alSampleFormat(sound->audio.format), 1) >= size)
			if(sound->audio.bfrsmp >= smp)
				chunk = 1;
			sound->audio.rdy = 0;
		}
	}
	alBufferData(bfr, sound->audio.format, sound->audio.buffer, sound->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(sound->audio.format)) * alChannels(sound->audio.format), sound->audio.freq);
	av_free(sound->audio.buffer);
	return sound->audio.bfrsmp;
}

int
flSoundSeek(FLsound *sound, unsigned int seek)
{
	if(av_seek_frame(sound->fc, -1, (uint64_t) seek * AV_TIME_BASE / 1000,  0) >= 0)
	{
		avcodec_flush_buffers(sound->audio.cc);
		if(sound->audio.pktprc.size) { av_free_packet(&sound->audio.pkt); } memset(&sound->audio.pktprc, 0, sizeof(AVPacket));
		av_pq_free(&sound->audio.pq);
		av_pq_init(&sound->audio.pq);
		sound->audio.pts = 0;
		sound->audio.frms = (uint64_t) seek / (av_q2d(sound->fc->streams[sound->audio.sti]->time_base) * 1000.0);
		sound->audio.bfrsmp = 0;
		sound->audio.rdy = 0;
		sound->audio.end = 0;
		sound->end = 0;
		return 1;
	}
	else
		return 0;
}
