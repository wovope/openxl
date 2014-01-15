#include "XL/xlImage.h"
#include "XL/xl.h"

static
unsigned int
alFormat(unsigned int bps, unsigned int channels)
{
	switch(bps)
	{
		case 1:
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
		case 2:
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
		case 4:
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
		case 8:
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
xlSndGenBuffer(void)
{
	XLsound *bind = xlGetSound();

	alGenBuffers(1, &bind->runtime.buffer);

	alBufferData(bind->runtime.buffer, alFormat(bind->header.bps, bind->header.channels), bind->body.samples, bind->header.length * bind->header.bps * bind->header.channels, bind->header.frequency);
	//alDebug(__FILE__, __LINE__);
}

void
xlSndDeleteBuffer(void)
{
	XLsound *bind = xlGetSound();

	alDeleteBuffers(1, &bind->runtime.buffer);

	//alDebug(__FILE__, __LINE__);
}

void
xlSndGenSource(void)
{
	XLsound *bind = xlGetSound();

	alGenSources(1, &bind->runtime.source);

	alSourcei(bind->runtime.source, AL_BUFFER, bind->runtime.buffer);

	//alDebug(__FILE__, __LINE__);
}

void
xlSndDeleteSource(void)
{
	XLsound *bind = xlGetSound();

	alSourcei(bind->runtime.source, AL_BUFFER, 0);
	alDeleteSources(1, &bind->runtime.source);

	//alDebug(__FILE__, __LINE__);
}

void
xlSndPlay(void)
{
	XLsound *bind = xlGetSound();

	alSourcePlay(bind->runtime.source);

	//alDebug(__FILE__, __LINE__);
}

void
xlSndStop(void)
{
	XLsound *bind = xlGetSound();

	alSourceStop(bind->runtime.source);

	//alDebug(__FILE__, __LINE__);
}
