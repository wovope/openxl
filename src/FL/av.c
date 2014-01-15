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
av_pq_bufget(FStream *stream, AVPacketQueue *pq, AVPacket *pkt)
{
	int ret;
	while(!(ret = av_pq_get(pq, pkt)) && !(stream->end = (av_read_frame(stream->fc, pkt) < 0)))
	{
		if(pkt->stream_index == stream->audio.sti) av_pq_put(&stream->audio.pq, pkt);
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
	* (uint64_t *) frm->opaque = ((FStream *) cc->opaque)->audio.pktprc.pts;
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
fStreamLoad(FStream *stream, int wanted, int related, const char *filepath)
{
	stream->fc = NULL;
	avformat_open_input(&stream->fc, filepath, NULL, NULL);
	avformat_find_stream_info(stream->fc, NULL);
	stream->audio.sti = av_find_best_stream(stream->fc, AVMEDIA_TYPE_AUDIO, wanted, related, NULL, 0);
	stream->audio.cc = stream->fc->streams[stream->audio.sti]->codec;
	stream->audio.codec = avcodec_find_decoder(stream->audio.cc->codec_id);
	avcodec_open2(stream->audio.cc, stream->audio.codec, NULL);
	stream->audio.frm = avcodec_alloc_frame();
	stream->audio.rc = NULL;
	stream->audio.size = av_samples_get_buffer_size(NULL, stream->audio.cc->channels, stream->fc->streams[stream->audio.sti]->duration * av_q2d(stream->fc->streams[stream->audio.sti]->time_base) * 1000000.0, stream->audio.cc->sample_fmt, 1);
	memset(&stream->audio.pktprc, 0, sizeof(AVPacket));
	av_pq_init(&stream->audio.pq);
	stream->audio.cc->opaque = (void *) stream;
	stream->audio.cc->get_buffer = my_audio_get_buffer;
	stream->audio.cc->release_buffer = my_release_buffer;
	stream->audio.bfrsmp = 0;
	stream->audio.rdy = 0;
	stream->audio.end = 0;
	stream->end = 0;

	stream->audio.format = al_av_get_format(stream->audio.cc->sample_fmt, stream->audio.cc->channels);
	stream->audio.freq = stream->audio.cc->sample_rate;
}

void
fStreamLoadDefault(FStream *stream, const char *filepath)
{
	fStreamLoad(stream, -1, -1, filepath);
}

void
fStreamInform(FStream *stream, ALenum *format, ALsizei *freq)
{
	if(format) *format = stream->audio.format;
	if(freq) *freq = stream->audio.freq;
}

void
fStreamConvert(FStream *stream, ALenum format, ALsizei freq)
{
	stream->audio.format = format;
	stream->audio.freq = freq;

	stream->audio.rc = swr_alloc_set_opts(NULL, av_alChannelLayout(stream->audio.format), av_alSampleFormat(stream->audio.format), stream->audio.freq, stream->audio.cc->channel_layout, stream->audio.cc->sample_fmt, stream->audio.cc->sample_rate, 0, NULL);
	swr_init(stream->audio.rc);
}

void
fStreamUnload(FStream *stream)
{
	av_pq_free(&stream->audio.pq);
	swr_free(&stream->audio.rc);
	av_free(stream->audio.frm);
	avcodec_close(stream->audio.cc);
	avformat_close_input(&stream->fc);
}

unsigned int
fStreamFrequency(FStream *stream)
{
	return stream->audio.cc->sample_rate;
}

unsigned int
fStreamChannels(FStream *stream)
{
	return stream->audio.cc->channels;
}

unsigned int
fStreamSize(FStream *stream)
{
	return stream->audio.size;
}

unsigned int
fStreamSampleSize(FStream *stream)
{
	return av_get_bytes_per_sample(stream->audio.cc->sample_fmt);
}

float
fStreamDuration(FStream *stream)
{
	return stream->fc->streams[stream->audio.sti]->duration * av_q2d(stream->fc->streams[stream->audio.sti]->time_base);
}

unsigned int
fStreamSamples(FStream *stream)
{
	return ((uint64_t) (stream->audio.cc->sample_rate * (stream->fc->streams[stream->audio.sti]->duration * av_q2d(stream->fc->streams[stream->audio.sti]->time_base))));
}


unsigned int
fStreamFormat(FStream *stream)
{
	return al_av_get_format(stream->audio.cc->sample_fmt, stream->audio.cc->channels);
}

unsigned int
fStreamReadSamples(FStream *stream, uint8_t *buffer)
{
	return fStreamReadChunk(stream, stream->audio.size, buffer);
}

void
fStreamBufferData(FStream *stream, ALuint bfr)
{
	fStreamBufferChunk(stream, stream->audio.size, bfr);
}

void
fStreamConvertBufferData(FStream *stream, ALuint bfr)
{
	fStreamConvertBufferChunk(stream, stream->audio.size, bfr);
}

unsigned int
fStreamEnd(FStream *stream)
{
	return stream->audio.end;
}

unsigned int
fStreamReadChunk(FStream *stream, unsigned int size, uint8_t *buffer)
{
	int smp, len, chunk;
	
	chunk = 0;
	smp = size / (av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels);
	stream->audio.bfrsmp = 0;
	stream->audio.buffer = buffer; //av_malloc(size + AVCODEC_MAX_AUDIO_FRAME_SIZE);
	while(!chunk && !(stream->audio.end = !(stream->audio.pktprc.size || av_pq_bufget(stream, &stream->audio.pq, &stream->audio.pkt))))
	{
		if(!stream->audio.pktprc.size) stream->audio.pktprc = stream->audio.pkt;
		len = avcodec_decode_audio4(stream->audio.cc, stream->audio.frm, &stream->audio.rdy, &stream->audio.pktprc);
		if(len > 0) { stream->audio.pktprc.data += len; stream->audio.pktprc.size -= len; }
		if(len < 0 || !stream->audio.pktprc.size) { av_free_packet(&stream->audio.pkt); memset(&stream->audio.pktprc, 0, sizeof(AVPacket)); }
		if(stream->audio.rdy)
		{
			stream->audio.frms++;
			if(!stream->audio.bfrsmp)
			{
				if(stream->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) stream->audio.frm->opaque != AV_NOPTS_VALUE) stream->audio.pts = * (uint64_t *) stream->audio.frm->opaque;
				else if(stream->audio.frm->pts != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->pts;
				else stream->audio.pts = stream->audio.frms;
			}
			memcpy(stream->audio.buffer + stream->audio.bfrsmp * av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels, stream->audio.frm->data[0], stream->audio.frm->nb_samples * av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels);
			stream->audio.bfrsmp += stream->audio.frm->nb_samples;
			if(stream->audio.bfrsmp >= smp)
				chunk = 1;
			stream->audio.rdy = 0;
		}
	}
	//alBufferData(bfr, stream->audio.format, stream->audio.buffer, stream->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(stream->audio.format)) * alChannels(stream->audio.format), stream->audio.freq);
	//av_free(stream->audio.buffer);
	return stream->audio.bfrsmp;
}

unsigned int
fStreamBufferChunk(FStream *stream, unsigned int size, ALuint bfr)
{
	int smp, len, chunk;
	
	chunk = 0;
	smp = size / (av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels);
	stream->audio.bfrsmp = 0;
	stream->audio.buffer = av_malloc(size + AVCODEC_MAX_AUDIO_FRAME_SIZE);
	while(!chunk && !(stream->audio.end = !(stream->audio.pktprc.size || av_pq_bufget(stream, &stream->audio.pq, &stream->audio.pkt))))
	{
		if(!stream->audio.pktprc.size) stream->audio.pktprc = stream->audio.pkt;
		len = avcodec_decode_audio4(stream->audio.cc, stream->audio.frm, &stream->audio.rdy, &stream->audio.pktprc);
		if(len > 0) { stream->audio.pktprc.data += len; stream->audio.pktprc.size -= len; }
		if(len < 0 || !stream->audio.pktprc.size) { av_free_packet(&stream->audio.pkt); memset(&stream->audio.pktprc, 0, sizeof(AVPacket)); }
		if(stream->audio.rdy)
		{
			stream->audio.frms++;
			if(!stream->audio.bfrsmp)
			{
				if(stream->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) stream->audio.frm->opaque != AV_NOPTS_VALUE) stream->audio.pts = * (uint64_t *) stream->audio.frm->opaque;
				else if(stream->audio.frm->pts != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->pts;
				else stream->audio.pts = stream->audio.frms;
			}
			memcpy(stream->audio.buffer + stream->audio.bfrsmp * av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels, stream->audio.frm->data[0], stream->audio.frm->nb_samples * av_get_bytes_per_sample(stream->audio.cc->sample_fmt) * stream->audio.cc->channels);
			stream->audio.bfrsmp += stream->audio.frm->nb_samples;
			if(stream->audio.bfrsmp >= smp)
				chunk = 1;
			stream->audio.rdy = 0;
		}
	}
	alBufferData(bfr, stream->audio.format, stream->audio.buffer, stream->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(stream->audio.format)) * alChannels(stream->audio.format), stream->audio.freq);
	av_free(stream->audio.buffer);
	return stream->audio.bfrsmp;
}

unsigned int
fStreamConvertBufferChunk(FStream *stream, unsigned int size, ALuint bfr)
{
	int smp, len, chunk;

	chunk = 0;
	smp = size / (av_get_bytes_per_sample(av_alSampleFormat(stream->audio.format)) * alChannels(stream->audio.format));
	stream->audio.bfrsmp = 0;
	stream->audio.buffer = av_malloc((size + AVCODEC_MAX_AUDIO_FRAME_SIZE));
	while(!chunk && !(stream->audio.end = !(stream->audio.pktprc.size || av_pq_bufget(stream, &stream->audio.pq, &stream->audio.pkt))))
	{
		if(!stream->audio.pktprc.size) stream->audio.pktprc = stream->audio.pkt;
		len = avcodec_decode_audio4(stream->audio.cc, stream->audio.frm, &stream->audio.rdy, &stream->audio.pktprc);
		if(len > 0) { stream->audio.pktprc.data += len; stream->audio.pktprc.size -= len; }
		if(len < 0 || !stream->audio.pktprc.size) { av_free_packet(&stream->audio.pkt); memset(&stream->audio.pktprc, 0, sizeof(AVPacket)); }
		if(stream->audio.rdy)
		{
			const uint8_t *in[] = { stream->audio.frm->data[0] };
			uint8_t *out[] = { stream->audio.buffer + stream->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(stream->audio.format)) * alChannels(stream->audio.format) };
			stream->audio.frms++;
			if(!stream->audio.bfrsmp)
			{
				if(stream->audio.frm->best_effort_timestamp != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->best_effort_timestamp;
				else if(* (uint64_t *) stream->audio.frm->opaque != AV_NOPTS_VALUE) stream->audio.pts = * (uint64_t *) stream->audio.frm->opaque;
				else if(stream->audio.frm->pts != AV_NOPTS_VALUE) stream->audio.pts = stream->audio.frm->pts;
				else stream->audio.pts = stream->audio.frms;
			}
			len = swr_convert(stream->audio.rc, out, smp, in, stream->audio.frm->nb_samples);
			if(len > 0) stream->audio.bfrsmp += len;
			//if(av_samples_get_buffer_size(NULL, alChannels(stream->audio.format), stream->audio.bfrsmp, av_alSampleFormat(stream->audio.format), 1) >= size)
			if(stream->audio.bfrsmp >= smp)
				chunk = 1;
			stream->audio.rdy = 0;
		}
	}
	alBufferData(bfr, stream->audio.format, stream->audio.buffer, stream->audio.bfrsmp * av_get_bytes_per_sample(av_alSampleFormat(stream->audio.format)) * alChannels(stream->audio.format), stream->audio.freq);
	av_free(stream->audio.buffer);
	return stream->audio.bfrsmp;
}

int
fStreamSeek(FStream *stream, unsigned int seek)
{
	if(av_seek_frame(stream->fc, -1, (uint64_t) seek * AV_TIME_BASE / 1000,  0) >= 0)
	{
		avcodec_flush_buffers(stream->audio.cc);
		if(stream->audio.pktprc.size) { av_free_packet(&stream->audio.pkt); } memset(&stream->audio.pktprc, 0, sizeof(AVPacket));
		av_pq_free(&stream->audio.pq);
		av_pq_init(&stream->audio.pq);
		stream->audio.pts = 0;
		stream->audio.frms = (uint64_t) seek / (av_q2d(stream->fc->streams[stream->audio.sti]->time_base) * 1000.0);
		stream->audio.bfrsmp = 0;
		stream->audio.rdy = 0;
		stream->audio.end = 0;
		stream->end = 0;
		return 1;
	}
	else
		return 0;
}
