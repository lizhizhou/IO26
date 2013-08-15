#ifndef __GUI_H
#define __GUI_H

#ifdef __cplusplus
 extern "C" {
#endif
#include <stdint.h>
#include <stdarg.h>
#include "lcd.h"
//#define Chinese_Support 				//open or close the chinese words support

 static __inline uint16_t RGBto16bit(uint8_t red,uint8_t green,uint8_t blue)
 {
 	uint8_t r = red   & 0xf8;
 	uint8_t g = green & 0xfc;
 	uint8_t b = blue  & 0xf8;
 	return (r << 8) + (g << 3) + (b >> 3);
 }

#define TRUE  1
#define FALSE 0

#define Fixed_Font_6_4       1			//6*4  points fixed font
#define Fixed_Font_8_6       2			//8*4  points fixed font
#define Fixed_Font_16_8      3		    //16*8 points fixed font
#define Variational_Front_13 4 		    //13   points height variational width font
#define Variational_Front_24 5			//24   points height variational width font
#define Variational_Front_32 6			//32   points height variational width font

extern const	char Arrow_up[2];
extern const	char Arrow_down[2];

extern void GUI_putchar_vw(uint16_t x,uint16_t y,uint16_t charColor,char c);
extern void GUI_puts_vw(uint16_t x,uint16_t y,uint16_t charColor,const char* c);
extern void GUI_putchar_vw_24(uint16_t x,uint16_t y,uint16_t charColor,char c);
extern void GUI_puts_vw_24(uint16_t x,uint16_t y,uint16_t charColor,const char* c);
extern void GUI_putchar_vw_32(uint16_t x,uint16_t y,uint16_t charColor,char c);
extern void GUI_puts_vw_32(uint16_t x,uint16_t y,uint16_t charColor,const char* c);
extern void GUI_putchar_16_8(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c);
extern void GUI_puts_16_8(uint16_t x,uint16_t y,uint16_t charColor,const char* c);
extern void GUI_putchar_6_4(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c);
extern void GUI_puts_6_4(uint16_t x,uint16_t y,uint16_t charColor,const char* c);
extern void GUI_putchar_8_6(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c);
extern void GUI_puts_8_6(uint16_t x,uint16_t y,uint16_t charColor,const char* c);


void GUI_DrawGrid(uint16_t x , uint16_t y, uint16_t Element_Height, uint16_t Element_Width, uint16_t Height, uint16_t Width, uint16_t Color, uint16_t Fill_Color, int Fill, int Grid);
void GUI_DrawLine(uint16_t START_x, uint16_t START_y, uint16_t END_x, uint16_t END_y, uint16_t Color);
void GUI_DrawRect(uint16_t START_x, uint16_t START_y, uint16_t lengh, uint16_t height, uint16_t Color , int Fill);
void GUI_DrawCircle(uint16_t CENTER_x, uint16_t CENTER_y,uint16_t RADIUS_r, uint16_t Color, uint16_t Fill_Color, int Fill, int Circle);
void GUI_DrawDotted_Line(uint16_t START_x,uint16_t START_y, uint16_t length, uint16_t gap, uint16_t Color ,int xy);
void GUI_DrawRounded_Rect(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height, uint16_t Color , int Fill);
void GUI_DrawSoft_Key(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height, int selected);
void GUI_DrawEllipse( uint16_t CENTER_x, uint16_t CENTER_y, uint16_t RADIUS_a, uint16_t RADIUS_b, uint16_t Color, uint16_t Fill_Color, int Fill, int Ellipse);
void GUI_DrawPolygon(uint16_t *points, uint16_t NUM_Points, uint16_t Line_Color);

static __inline void GUI_DrawPixel(uint16_t x,uint16_t y,uint16_t Color)
{
	lcd_set_point(x, y, (Color>>8)&0xf8, (Color>>3)&0xfc, (Color<<3)&0xf8);
}

static __inline void GUI_ShowBmp(uint16_t x_star,uint16_t y_star,uint16_t length,uint16_t height,const unsigned short *buf)
{
//	ILI9481_ShowBmp(x_star,y_star,length,height,buf);
//  SSD1963_ShowBmp(x_star,y_star,length,height,buf);
}

static __inline void GUI_DrawBox(uint16_t x,uint16_t y,uint16_t length, uint16_t height,uint16_t color)
{
	//SSD1963_ClearBox(x,y,x+length,y+height,color);
//	SSD1963_ClearBox(x,y,length,height,color);
}

static __inline void GUI_putchar(uint16_t x,uint16_t y,uint16_t charColor,uint16_t font,uint8_t c)
{
	switch(font)
	{
		case Fixed_Font_6_4:
			GUI_putchar_6_4(x,y,charColor,c);
			break;
		case Fixed_Font_8_6:
			GUI_putchar_8_6(x,y,charColor,c);
			break;
		case Fixed_Font_16_8:
			GUI_putchar_16_8(x,y,charColor,c);
			break;
		case Variational_Front_13:
			GUI_putchar_vw(x,y,charColor,c);
			break;
		case Variational_Front_24:
			GUI_putchar_vw_24(x,y,charColor,c);
			break;
		case Variational_Front_32:
			GUI_putchar_vw_32(x,y,charColor,c);
			break;
		default:
			GUI_putchar_vw(x,y,charColor,c);
			break;
	}
	
}

static __inline void GUI_puts(uint16_t x,uint16_t y,uint16_t charColor,uint16_t font,const char* c)
{
	switch(font)
	{
		case Fixed_Font_6_4:
			GUI_puts_6_4(x,y,charColor,c);
			break;
		case Fixed_Font_8_6:
			GUI_puts_8_6(x,y,charColor,c);
			break;
		case Fixed_Font_16_8:
			GUI_puts_16_8(x,y,charColor,c);
			break;
		case Variational_Front_13:
			GUI_puts_vw(x,y,charColor,c);
			break;
		case Variational_Front_24:
			GUI_puts_vw_24(x,y,charColor,c);
			break;
	   	case Variational_Front_32:
			GUI_puts_vw_32(x,y,charColor,c);
			break;
		default:
			GUI_puts_vw(x,y,charColor,c);
			break;
	}
	
}

int  GUI_printf(uint16_t x,uint16_t y,uint16_t charColor,uint16_t font,const char* format,...);
void GUI_putchar_chinese(uint16_t x,uint16_t y,uint16_t CharColor,uint16_t ChineseCode);
void GUI_puts_chinese(uint16_t x,uint16_t y,uint16_t CharColor,const char* s);



#ifdef __cplusplus
}
#endif
#endif
