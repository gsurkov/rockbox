#ifndef __LCD_TARGET_H__
#define __LCD_TARGET_H__

#define LCD_OPTIMIZED_UPDATE
#define LCD_OPTIMIZED_UPDATE_RECT

#include "lcd.h"

extern fb_data *framebuffer;

#define LCD_FRAMEBUF_ADDR(col, row) NULL /* Does nothing */

#endif /* __LCD_TARGET_H__ */
