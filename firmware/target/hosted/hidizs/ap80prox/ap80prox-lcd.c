#include "lcd-target.h"

#include <fcntl.h>
#include <string.h>

#include <linux/fb.h>

#include <sys/ioctl.h>
#include <sys/mman.h>

#include "panic.h"
#include "debug.h"

#define FBDEV_PATH "/dev/fb0"

/* Undocumented jz-fb ioctls, discovered via strace */
#define JZFBIO_SWAP (_IOW('F', 0x60, __u32))
#define JZFBIO_SYNC (_IOW('F', 0x61, __u32))

static int fd = -1;
static int fb_plane = 0;

static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;

fb_data *framebuffer = NULL;
fb_data *fb_planes[2];

/*
 * Despite the display reporting the right (360x480) resolution, the display
 * is actually a 480x360 one rotated 90 degrees clockwise.
 *
 * Its address space therefore starts at (360, 0) and is not contigious.
 *
 * Using a standard copy_buffer_rect() function would result in a completely garbled image,
 * hence this function that replaces columns with rows on a pixel-by-pixel basis.
 *
 * NOTE: At the time of writing, the author is not aware of any way of doing this in hardware.
 */
static FORCE_INLINE void set_pixel(fb_data* dst, int x, int y, fb_data data) {
    dst[(LCD_WIDTH - x) * LCD_HEIGHT + y] = data;
}

static void lcd_full_update(void)
{
    for(int y = 0; y < LCD_HEIGHT; ++y) {
        for(int x = 0; x < LCD_WIDTH; ++x) {
            set_pixel(fb_planes[fb_plane], x, y, *FBADDR(x, y));
        }
    }

    if(ioctl(fd, JZFBIO_SWAP, &fb_plane) < 0) {
        panicf("Failed to swap buffers");
    }

    if(ioctl(fd, JZFBIO_SYNC, NULL) < 0) {
        DEBUGF("Failed to wait for vblank\n");
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

    fb_planes[0] = framebuffer;
    fb_planes[1] = framebuffer + (finfo.smem_len / (FB_DATA_SZ * 2));
}

void lcd_update(void)
{
    lcd_full_update();
}

void lcd_update_rect(int x, int y, int width, int height)
{
    // TODO: Implement partial update
    lcd_full_update();
}
