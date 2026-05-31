#include "audiohw.h"
#include "alsa-controls.h"

#include "debug.h"

#define CONTROL_DEFAULT "default"

#define CONTROL_LEFT  "Left Playback Volume"
#define CONTROL_RIGHT "Right Playback Volume"
#define CONTROL_PORT  "Output Port Switch"
#define CONTROL_MUTE  "Hardware Mute"

#define HW_VOLUME_MAX (255)

/*
 * NOTE: Hidizs AP80 ALSA card (quite counter-intuitively)
 * treats 0 as the maximum volume and 255 as the minium volume.
 *
 * Thus, VOLUME_MIN_CB was chosen so that
 * it would be evenly divisible by HW_VOLUME_MAX.
 */
static int centibel_to_hw_volume(int vol_cb) {
    return vol_cb / (VOLUME_MIN_CB / HW_VOLUME_MAX);
}

void audiohw_preinit(void)
{
    alsa_controls_init(CONTROL_DEFAULT);

    long out = 2; /* TODO: implement port switching */
    alsa_controls_set_ints(CONTROL_PORT, 1, &out);
}

void audiohw_postinit(void)
{
}

void audiohw_close(void)
{
    alsa_controls_close();
}

void audiohw_set_volume(int vol_l, int vol_r)
{
    long l = centibel_to_hw_volume(vol_l);
    long r = centibel_to_hw_volume(vol_r);

    alsa_controls_set_ints(CONTROL_LEFT, 1, &l);
    alsa_controls_set_ints(CONTROL_RIGHT, 1, &r);
}
