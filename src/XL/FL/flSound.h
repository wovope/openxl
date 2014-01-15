#ifndef AV_H
#define AV_H

#include <XL/AL/xlalut.h>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <libavutil/imgutils.h>

typedef struct SwrContext SwrContext;
typedef struct SwsContext SwsContext;
typedef enum AVSampleFormat AVSampleFormat;
typedef enum PixelFormat PixelFormat;

typedef struct
{
	AVPacketList *first, *last;
} AVPacketQueue;

void
av_pq_init(AVPacketQueue *pq);

void
av_pq_free(AVPacketQueue *pq);

void
av_pq_put(AVPacketQueue *pq, AVPacket *pkt);

int
av_pq_get(AVPacketQueue *pq, AVPacket *pkt);

typedef struct
{
	AVFormatContext *fc;
	int end;
	struct
	{
		ALenum format;
		ALsizei freq;
		AVCodecContext *cc;
		AVCodec *codec;
		int sti;
		uint64_t size;
		uint8_t *buffer;
		int bfrsmp;
		AVFrame *frm;
		AVPacketQueue pq;
		AVPacket pkt, pktprc;
		SwrContext *rc;
		uint64_t pts, frms;
		int rdy, end;
	} audio;
} FLsound;

void
flSoundLoad(FLsound *sound, int wanted, int related, const char *filepath);

void
flSoundLoadDefault(FLsound *sound, const char *filepath);

void
flSoundInform(FLsound *sound, ALenum *format, ALsizei *freq);

void
flSoundConvert(FLsound *sound, ALenum format, ALsizei freq);

void
flSoundUnload(FLsound *sound);

unsigned int
flSoundFrequency(FLsound *sound);

unsigned int
flSoundChannels(FLsound *sound);

unsigned int
flSoundSize(FLsound *sound);

unsigned int
flSoundSampleSize(FLsound *sound);

float
flSoundDuration(FLsound *sound);

unsigned int
flSoundSamples(FLsound *sound);

unsigned int
flSoundFormat(FLsound *sound);

unsigned int
flSoundReadSamples(FLsound *sound, uint8_t *buffer);

void
flSoundBufferData(FLsound *sound, ALuint bfr);

void
flSoundConvertBufferData(FLsound *sound, ALuint bfr);

unsigned int
flSoundEnd(FLsound *sound);

unsigned int
flSoundReadChunk(FLsound *sound, unsigned int size, uint8_t *buffer);

unsigned int
flSoundBufferChunk(FLsound *sound, unsigned int size, ALuint bfr);

unsigned int
flSoundConvertBufferChunk(FLsound *sound, unsigned int size, ALuint bfr);

int
flSoundSeek(FLsound *sound, unsigned int seek);

#endif
