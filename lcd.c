/*
 * lcd.c
 *
 *  Created on: Aug 10, 2013
 *      Author: zhizhouli
 */
#include <linux/fb.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "lcd.h"
int fbfd = 0;
char* fbp;
long int screensize = 0;
void lcd_init(void)
{
	int i;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;

	/*打开设备文件*/
	fbfd = open("/dev/fb0", O_RDWR);
	/*取得屏幕相关参数*/
	ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
	ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
	/*计算屏幕缓冲区大小*/
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	/*映射屏幕缓冲区到用户地址空间*/
	printf("screensize %d", screensize);
	fbp = (char*) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd,
			0);
	for(i = 0; i< screensize; i++)
	{
		*(fbp+i) = 0xff;
	}
	/*下面可通过 fbp指针读写缓冲区*/
	//clear the lcd
	for(i = 0; i< 200; i++) {
		lcd_set_point(i,i,0,255,0);
	}
}

void lcd_set_point(int x, int y, char red, char green, char blue)
{
	char *point;
	x = 480 - x;
	y = 270 - y;
	point = fbp + x*4 + 480 * y * 4;
	*(point++) = blue;
	*(point++) = green;
	*point = red;
}

void lcd_close()
{
	/*释放缓冲区，关闭设备*/
	munmap(fbp, screensize);

	close(fbfd);
}
