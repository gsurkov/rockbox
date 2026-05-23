#include <linux/input.h>

#include "backlight.h"
#include "button-target.h"

int button_map(int keycode)
{
    switch(keycode) {
    case KEY_LEFT:
        return BUTTON_VOL_DOWN;
    case KEY_RIGHT:
        return BUTTON_VOL_UP;
    case KEY_PLAYPAUSE:
        return BUTTON_PLAY;
    case KEY_NEXTSONG:
        return BUTTON_NEXT;
    case KEY_PREVIOUSSONG:
        return BUTTON_PREV;
    case KEY_POWER:
        return BUTTON_POWER;
    case BTN_TOUCH:
        if(is_backlight_on(true))
        {
            return BUTTON_TOUCH;
        }
        return 0;
    default:
        return 0;
    }
}
