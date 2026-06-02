#ifndef _BUTTON_TARGET_H_
#define _BUTTON_TARGET_H_

#define BUTTON_POWER       (1 << 0)
#define BUTTON_PREV        (1 << 1)
#define BUTTON_NEXT        (1 << 2)
#define BUTTON_PLAY        (1 << 3)
#define BUTTON_SCROLL_FWD  (1 << 4)
#define BUTTON_SCROLL_BACK (1 << 5)
#define BUTTON_TOUCH       (1 << 6)

#define BUTTON_MAIN (\
    BUTTON_POWER      | BUTTON_PREV \
    BUTTON_NEXT       | BUTTON_PLAY \
    BUTTON_SCROLL_FWD | BUTTON_SCROLL_BACK)

#define BUTTON_TOPLEFT      (1 << 12)
#define BUTTON_TOPMIDDLE    (1 << 13)
#define BUTTON_TOPRIGHT     (1 << 14)
#define BUTTON_MIDLEFT      (1 << 15)
#define BUTTON_CENTER       (1 << 16)
#define BUTTON_MIDRIGHT     (1 << 17)
#define BUTTON_BOTTOMLEFT   (1 << 18)
#define BUTTON_BOTTOMMIDDLE (1 << 19)
#define BUTTON_BOTTOMRIGHT  (1 << 20)

#define BUTTON_LEFT  BUTTON_NEXT
#define BUTTON_RIGHT BUTTON_PREV

int button_map(int keycode);

#endif /* _BUTTON_TARGET_H_ */
