#include "lcd-target.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include <linux/fb.h>

#include <sys/ioctl.h>
#include <sys/mman.h>

#include "panic.h"

static int fd = -1;
static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;

fb_data *framebuffer = NULL;

#define FBDEV_PATH "/dev/fb0"

static FORCE_INLINE void set_pixel(fb_data* dst, int x, int y, fb_data data) {
    dst[(LCD_WIDTH - x) * LCD_HEIGHT + y] = data;
}

static void lcd_full_update(void)
{
    int buf_idx = 0;
    int status = -1;

    status = ioctl(fd, _IOW('F', 0x60, int), &buf_idx);
    if(status < 0) {
        panicf("Failed to swap buffers");
    }

    fb_data* dst = framebuffer + ((finfo.smem_len / (2 * sizeof(fb_data))) * buf_idx);

    for(int y = 0; y < LCD_HEIGHT; ++y) {
        for(int x = 0; x < LCD_WIDTH; ++x) {
            set_pixel(dst, x, y, *FBADDR(x, y));
        }
    }

    status = ioctl(fd, _IOW('F', 0x61, int), 0);
    if(status < 0) {
        panicf("Failed to wait for vblank");
    }
}

void lcd_init_device(void)
{
    fd = open(FBDEV_PATH, O_RDWR | O_CLOEXEC);

    if(fd < 0)
    {
        panicf("Cannot open framebuffer: %s\n", FBDEV_PATH);
    }

    if(ioctl(fd, FBIOGET_FSCREENINFO, &finfo) < 0)
    {
        panicf("Cannot read framebuffer fixed information");
    }

    if (finfo.smem_len < FRAMEBUFFER_SIZE * 2)
    {
        panicf("FRAMEBUFFER_SIZE too large for hardware? (%u vs %u)", FRAMEBUFFER_SIZE, finfo.smem_len);
    }

    if(ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0)
    {
        panicf("Cannot read framebuffer variable information");
    }

    framebuffer = mmap(NULL, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if(framebuffer == MAP_FAILED)
    {
        panicf("Cannot map framebuffer");
    }

    memset(framebuffer, 0, finfo.smem_len);
}

void lcd_update(void)
{
    if(fd < 0)
    {
        return;
    }

    lcd_full_update();
}

void lcd_update_rect(int x, int y, int width, int height)
{
    if(fd < 0)
    {
        return;
    }

    printf("%s: x=%d y=%d w=%d h=%d\r\n", __FUNCTION__, x, y, width, height);
    // TODO: Implement partial update
    lcd_full_update();
}
