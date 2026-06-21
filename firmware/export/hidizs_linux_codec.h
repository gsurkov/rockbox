#ifndef _HIDIZS_LINUX_CODEC_
#define _HIDIZS_LINUX_CODEC_

#define AUDIOHW_CAPS (FILTER_ROLL_OFF_CAP)
/* Hidizs AP80 Pro-X uses dual ES9219, but filter settings are the same */
#define AUDIOHW_HAVE_ES9218_ROLL_OFF

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
    VOLUME,\
    VOLUME_UNITS,\
    VOLUME_EXPONENT,\
    VOLUME_STEP_CB,\
    VOLUME_MIN_CB,\
    VOLUME_MAX_CB,\
    VOLUME_DEFAULT_CB)

#define FILTER_ROLL_OFF_UNITS    ""
#define FILTER_ROLL_OFF_EXPONENT 0
#define FILTER_ROLL_OFF_STEP     1
#define FILTER_ROLL_OFF_MIN      0
#define FILTER_ROLL_OFF_MAX      7
#define FILTER_ROLL_OFF_DEFAULT  0

AUDIOHW_SETTING(\
    FILTER_ROLL_OFF,\
    FILTER_ROLL_OFF_UNITS,\
    FILTER_ROLL_OFF_EXPONENT,\
    FILTER_ROLL_OFF_STEP,\
    FILTER_ROLL_OFF_MIN,\
    FILTER_ROLL_OFF_MAX,\
    FILTER_ROLL_OFF_DEFAULT)

#endif /* _HIDIZS_LINUX_CODEC_ */
