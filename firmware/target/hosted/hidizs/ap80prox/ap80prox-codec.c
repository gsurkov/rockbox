#include "audiohw.h"
#include "alsa-controls.h"

#include "debug.h"

#define CONTROL_DEFAULT "default"

#define CONTROL_LEFT  "Left Playback Volume"
#define CONTROL_RIGHT "Right Playback Volume"
#define CONTROL_PORT  "Output Port Switch"
#define CONTROL_MUTE  "Hardware Mute"

#define HW_VOLUME_MAX (255)

static int cb_to_volume(int cb) {
    return cb / (VOLUME_MIN_CB / HW_VOLUME_MAX);
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

void audiohw_mute(int mute) {
    alsa_controls_set_bool(CONTROL_MUTE, !!mute);
}

void audiohw_set_volume(int vol_l, int vol_r)
{
    long l = cb_to_volume(vol_l);
    long r = cb_to_volume(vol_r);

    alsa_controls_set_ints(CONTROL_LEFT, 1, &l);
    alsa_controls_set_ints(CONTROL_RIGHT, 1, &r);
}
