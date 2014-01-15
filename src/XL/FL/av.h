#ifndef AV_H
#define AV_H

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
#include <libavutil/imgutils.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

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
} FStream;

void
fStreamLoad(FStream *stream, int wanted, int related, const char *filepath);

void
fStreamLoadDefault(FStream *stream, const char *filepath);

void
fStreamInform(FStream *stream, ALenum *format, ALsizei *freq);

void
fStreamConvert(FStream *stream, ALenum format, ALsizei freq);

void
fStreamUnload(FStream *stream);

unsigned int
fStreamFrequency(FStream *stream);

unsigned int
fStreamChannels(FStream *stream);

unsigned int
fStreamSize(FStream *stream);

unsigned int
fStreamSampleSize(FStream *stream);

float
fStreamDuration(FStream *stream);

unsigned int
fStreamSamples(FStream *stream);

unsigned int
fStreamFormat(FStream *stream);

unsigned int
fStreamReadSamples(FStream *stream, uint8_t *buffer);

void
fStreamBufferData(FStream *stream, ALuint bfr);

void
fStreamConvertBufferData(FStream *stream, ALuint bfr);

unsigned int
fStreamEnd(FStream *stream);

unsigned int
fStreamReadChunk(FStream *stream, unsigned int size, uint8_t *buffer);

unsigned int
fStreamBufferChunk(FStream *stream, unsigned int size, ALuint bfr);

unsigned int
fStreamConvertBufferChunk(FStream *stream, unsigned int size, ALuint bfr);

int
fStreamSeek(FStream *stream, unsigned int seek);

#endif
