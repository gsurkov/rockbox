#ifndef _HIDIZS_LINUX_CODEC_
#define _HIDIZS_LINUX_CODEC_

/* 1 dB = 10 cB (centibels) */
#define DB_TO_CB(db) ((db) * 10)

/* No influence on volume */
#define VOLUME_UNITS      "dB"
/* The number of digits - 1 of the volume value */
#define VOLUME_EXPONENT   1
/* Volume step in centibels */
#define VOLUME_STEP_CB    5
/* Maximum volume in centibels */
#define VOLUME_MAX_CB     DB_TO_CB(0)
/* Minimum volume in centibels */
#define VOLUME_MIN_CB     DB_TO_CB(-102)
/* Default volume in centibels */
#define VOLUME_DEFAULT_CB DB_TO_CB(-30)

AUDIOHW_SETTING(\
    VOLUME, \
    VOLUME_UNITS, \
    VOLUME_EXPONENT, \
    VOLUME_STEP_CB, \
    VOLUME_MIN_CB, \
    VOLUME_MAX_CB, \
    VOLUME_DEFAULT_CB)

#define AUDIOHW_NEEDS_INITIAL_UNMUTE

void audiohw_mute(int mute);

#endif /* _HIDIZS_LINUX_CODEC_ */
