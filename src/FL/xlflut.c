#include "XL/FL/xlflut.h"
#include "XL/xl.h"

void
flInit(void)
{
	avcodec_register_all();
	av_register_all();
	av_log_set_level(AV_LOG_QUIET);
}
