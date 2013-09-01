/*
       Graphic User Interface v1.0
	   meteroi
*/
#include <stdio.h>

#include "Point_font.h"
#include "GUI.h"

#define BUFFER_SIZE 512

const	char Arrow_up[2] = {0x7f,0x00};
const	char Arrow_down[2] = {0x80,0x00};
const	char Temp_C[2] = {0x81,0x00};

/* Private defines -----------------------------------------------------------*/

#define abs(X) ( ( (X) < 0 ) ? -(X) : (X) )
#define sgn(X) ( ( (X) < 0 ) ? -1 : 1 )
   
/*******************************************************************************
* Function Name  :   GUI_DrawGrid()
* Description    :   Draw a grid into the LCD, with an start point (x,y), 
*                    the height and width of the elements of the Grid, 
                     the color of the grid and the color to fill the grid
* Input          :   u8 x Grid x position
                     u8 y Grid y position
                     u8 Element_Height Height of each rectangle of the grid
                     u8 Element_Width Width of each rectangle of the grid
                     u8 Height Number of rectangles in the height grid
                     u8 Width Number of erctangles in width grid
                     u16 Color Line color the grid
                     u16 Fill_Color Background color of the grid 
                     int Fill Defines if the grid is filled
                     int Grid  Defines if the grid is drawn
* Return         :   None
*******************************************************************************/

void GUI_DrawGrid(uint16_t x , uint16_t y, uint16_t Element_Width, uint16_t Element_Height, uint16_t Width, uint16_t Height, uint16_t Color, uint16_t Fill_Color, int Fill, int Grid)
{
   int i,j;
   for(i=0;i<Height;i++)
      for (j=0;j<Width;j++){
         if(Grid)
         GUI_DrawRect ( x+(j*(Element_Width-1)), y+(i*(Element_Height-1)), Element_Width, Element_Height, Color , 0);
        
         if(Fill)
         GUI_DrawBox ( x+(j*(Element_Width-1))+1, y+(i*(Element_Height-1))+1,  Element_Width-2, Element_Height-2, Fill_Color);
      }
}


/*******************************************************************************
* Function Name  :   GUI_DrawLine()
* Description    :   Implementation of Bresenham's line algorithm
* Input          :   u8 START_x Start x position
                     u8 START_y Start y position
                     u8 END_x End x position
                     u8 END_y End y position
                     u16 Color Color of the lines of the grid
* Return         :   None
*******************************************************************************/

void GUI_DrawLine(uint16_t START_x, uint16_t START_y, uint16_t END_x, uint16_t END_y, uint16_t Color)
{
   int i;
   int16_t x,y;
   int16_t  DELTA_x,DELTA_y,ABS_DELTA_x,ABS_DELTA_y, PARALEL_Step_x, PARALEL_Step_y, DIAGONAL_Step_x, DIAGONAL_Step_y, ERROR_Step_Fast, ERROR_Step_Slow;
   int16_t  SIG_DELTA_x, SIG_DELTA_y;
   float error;
   DELTA_x = END_x-START_x;
   DELTA_y = END_y-START_y;
   ERROR_Step_Fast=ABS_DELTA_x = abs(DELTA_x);
   ERROR_Step_Slow=ABS_DELTA_y = abs(DELTA_y); 
   SIG_DELTA_x = sgn(DELTA_x); 
   PARALEL_Step_y=SIG_DELTA_y = sgn(DELTA_y); 
   PARALEL_Step_x = 0;
   if( ABS_DELTA_x > ABS_DELTA_y ){
     PARALEL_Step_x = SIG_DELTA_x;
     PARALEL_Step_y = 0;
     ERROR_Step_Fast  = ABS_DELTA_y;
     ERROR_Step_Slow  = ABS_DELTA_x; 
   }
   DIAGONAL_Step_x = SIG_DELTA_x;
   DIAGONAL_Step_y = SIG_DELTA_y; 
   x = START_x;
   y = START_y;
   GUI_DrawPixel(x,y,Color); 
   error = ERROR_Step_Slow>>1; 
   for(i=1;i<=ERROR_Step_Slow;i++){        
      error = error - ERROR_Step_Fast;
      if( error < 0 ){
         error = error + ERROR_Step_Slow; 
         x = x + DIAGONAL_Step_x;
         y = y + DIAGONAL_Step_y; 
      }
      else {
         x = x + PARALEL_Step_x;
         y = y + PARALEL_Step_y; 
      }
      GUI_DrawPixel(x,y,Color);
    }
}

void GUI_DrawRect(uint16_t START_x, uint16_t START_y, uint16_t lengh, uint16_t height, uint16_t Color , int Fill)
{
	if(Fill)
		GUI_DrawBox(START_x,START_y,lengh,height,Color);	
	else
	{
		GUI_DrawLine(START_x,START_y,START_x+lengh,START_y,Color);
		GUI_DrawLine(START_x+lengh,START_y,START_x+lengh,START_y+height,Color);
		GUI_DrawLine(START_x,START_y,START_x,START_y+height,Color);	
		GUI_DrawLine(START_x,START_y+height,START_x+lengh,START_y+height,Color);
	}
	
}

/*******************************************************************************
* Function Name  :   GUI_DrawCircle()
* Description    :   Implementation of Bresenham's Circle variant algorithm
* Input          :   u8 CENTER_x Circle Center x position
                     u8 CENTER_y Circle Center y position
                     u8 RADIUS_r Circle Radius
                     u16 Color Line color of the Circle
                     u16 Fill_Color Background of the Circle
                     int Fill Defines if the circle is filled
                     int Circle Defines if the circle is drawn
* Return         :   None
*******************************************************************************/

void GUI_DrawCircle(uint16_t CENTER_x, uint16_t CENTER_y,uint16_t RADIUS_r, uint16_t Color, uint16_t Fill_Color, int Fill, int Circle)
{
   int ERROR = 1 - RADIUS_r;
   int ddF_x = 0;
   int ddF_y = -2 * RADIUS_r;
   int x = 0;
   int y = RADIUS_r;
   if(Fill)
      if(Circle){
         Fill=FALSE;
         GUI_DrawCircle(CENTER_x, CENTER_y, RADIUS_r,Color,Fill_Color, TRUE,FALSE );
      }
    if(Fill){  
      GUI_DrawLine(CENTER_x + RADIUS_r, CENTER_y,CENTER_x - RADIUS_r,CENTER_y, Fill_Color );
      GUI_DrawLine(CENTER_x , CENTER_y - RADIUS_r,CENTER_x,CENTER_y+ RADIUS_r,Fill_Color);
    }
   if(Circle){
      GUI_DrawPixel(CENTER_x, CENTER_y + RADIUS_r,Color);
      GUI_DrawPixel(CENTER_x, CENTER_y - RADIUS_r,Color);
      GUI_DrawPixel(CENTER_x + RADIUS_r, CENTER_y,Color);
      GUI_DrawPixel(CENTER_x - RADIUS_r, CENTER_y,Color);
   }
   while(x < y) 
   {
      if(ERROR >= 0) 
      {
       y--;
       ddF_y += 2;
       ERROR += ddF_y;
      }
      x++;
      ddF_x += 2;
      ERROR += ddF_x + 1; 
      if(Fill){
         GUI_DrawLine(CENTER_x + x, CENTER_y + y, CENTER_x + x, CENTER_y - y, Fill_Color );
         GUI_DrawLine(CENTER_x - x, CENTER_y + y, CENTER_x - x, CENTER_y - y, Fill_Color );
         GUI_DrawLine(CENTER_x + y, CENTER_y + x, CENTER_x + y, CENTER_y - x, Fill_Color );
         GUI_DrawLine(CENTER_x - y, CENTER_y + x, CENTER_x - y, CENTER_y - x, Fill_Color );
         }
      if(Circle){
         GUI_DrawPixel(CENTER_x + x, CENTER_y + y,Color);
         GUI_DrawPixel(CENTER_x - x, CENTER_y + y,Color);
         GUI_DrawPixel(CENTER_x + x, CENTER_y - y,Color);
         GUI_DrawPixel(CENTER_x - x, CENTER_y - y,Color);
         GUI_DrawPixel(CENTER_x + y, CENTER_y + x,Color);
         GUI_DrawPixel(CENTER_x - y, CENTER_y + x,Color);
         GUI_DrawPixel(CENTER_x + y, CENTER_y - x,Color);
         GUI_DrawPixel(CENTER_x - y, CENTER_y - x,Color);
         }
   } 
 }

/*******************************************************************************
* Function Name  :   GUI_DrawEllipse()
* Description    :   This function draw an Ellipse
* Input          :   u8 CENTER_x Ellipse Center x position
                     u8 CENTER_y Ellipse Center y position
                     u8 RADIUS_a Ellipse Radius a
                     u8 RADIUS_b Ellipse Radius b
                     u16 Color Line color of the Circle
                     u16 Fill_Color Background of the Circle
                     int Fill Defines if the Ellipse is filled
                     int Ellipse Defines if the Ellipse is drawn
* Return         :   None
*******************************************************************************/

void GUI_DrawEllipse( uint16_t CENTER_x, uint16_t CENTER_y, uint16_t RADIUS_a, uint16_t RADIUS_b, uint16_t Color, uint16_t Fill_Color, int Fill, int Ellipse)
{
   int X, Y;
   int XChange, YChange;
   int EllipseError;
   int TwoASquare, TwoBSquare;
   int StoppingX, StoppingY;
   TwoASquare = 2*RADIUS_a*RADIUS_a;
   TwoBSquare = 2*RADIUS_b*RADIUS_b;
   X = RADIUS_a;
   Y = 0;
   XChange =RADIUS_b*RADIUS_b*(1-2*RADIUS_a);
   YChange = RADIUS_a*RADIUS_a;
   EllipseError = 0;
   StoppingX = TwoBSquare*RADIUS_a;
   StoppingY = 0;
   if(Fill)
      if(Ellipse){
         Fill=FALSE;
         GUI_DrawEllipse( CENTER_x, CENTER_y, RADIUS_a, RADIUS_b, Color, Fill_Color, TRUE,FALSE);
      }
   while ( StoppingX >= StoppingY ) {
      if(Fill){
         GUI_DrawLine(CENTER_x+ X, CENTER_y+Y, CENTER_x-X , CENTER_y+Y, Fill_Color);
         GUI_DrawLine(CENTER_x- X, CENTER_y-Y, CENTER_x+X , CENTER_y-Y,Fill_Color);
      }
      if(Ellipse){
         GUI_DrawPixel(CENTER_x+X, CENTER_y+Y,Color); 
         GUI_DrawPixel(CENTER_x-X, CENTER_y+Y,Color); 
         GUI_DrawPixel(CENTER_x-X, CENTER_y-Y,Color); 
         GUI_DrawPixel(CENTER_x+X, CENTER_y-Y,Color); 
      }
      Y++;
      StoppingY+= TwoASquare;
      EllipseError+= YChange;
      YChange+= TwoASquare;
      if ((2*EllipseError + XChange) > 0 ) {
         X--;
         StoppingX-=TwoBSquare;
         EllipseError+= XChange;
         XChange+=TwoBSquare;
      }
   }
   X = 0;
   Y = RADIUS_b;
   XChange = RADIUS_b*RADIUS_b;
   YChange = RADIUS_a*RADIUS_a*(1-2*RADIUS_b);
   EllipseError = 0;
   StoppingX = 0;
   StoppingY = TwoASquare*RADIUS_b;
   while ( StoppingX <= StoppingY ) {
      if(Fill){
         GUI_DrawLine(CENTER_x+ X, CENTER_y+Y, CENTER_x-X , CENTER_y+Y, Fill_Color);
         GUI_DrawLine(CENTER_x- X, CENTER_y-Y, CENTER_x+X , CENTER_y-Y, Fill_Color);
      }
      if(Ellipse){
         GUI_DrawPixel(CENTER_x+X, CENTER_y+Y,Color); 
         GUI_DrawPixel(CENTER_x-X, CENTER_y+Y,Color); 
         GUI_DrawPixel(CENTER_x-X, CENTER_y-Y,Color); 
         GUI_DrawPixel(CENTER_x+X, CENTER_y-Y,Color); 
      }
      X++;
      StoppingX+= TwoBSquare;
      EllipseError+= XChange;
      XChange+=TwoBSquare;
      if ((2*EllipseError + YChange) > 0 ){
         Y--;
         StoppingY-= TwoASquare;
         EllipseError+= YChange;
         YChange+=TwoASquare;
      }
   }
}
  

/*******************************************************************************
* Function Name  :   GUI_DrawPolygon()
* Description    :   Function to draw a polygon with the given points
* Input          :   A pointer to the points of the polygon, the number of points, 
                     and the color of the line.
* Return         :   None
*******************************************************************************/
void GUI_DrawPolygon(uint16_t *points, uint16_t NUM_Points, uint16_t Line_Color)
{
   int i=1;
   for(i=1;i<NUM_Points>>1;i++){
      GUI_DrawLine(points[(i-1)*2], points[1+(i-1)*2], points[(i)*2], points[1+(i)*2], Line_Color);
   }
   GUI_DrawLine(points[(i-1)*2], points[1+(i-1)*2],points[0],points[1] , Line_Color);
}



void GUI_showchar(uint16_t x,uint16_t y,uint16_t charColor,const GUI_CHARINFO* c)
{
	uint16_t i=0;
	uint16_t j=0;
	uint16_t x_size=0;
	const unsigned char* p;
	char tmp_char;
    x_size   = c->XSize;
	p        = c->pData;
	for (i=0;i<13;i++)
    {	
		tmp_char = *p;	   
    	for (j=0;j<x_size;j++)
	    {
			if(j==8)		                          // д��8��λ������һ�ֽ�
			{
			 	p++;
				tmp_char = *p;
			}	
			if ( (tmp_char >> 7-j%8) & 0x01 == 0x01)
	        {
	        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
	        }
        }
		p++;	
    }	
}

void GUI_putchar_vw(uint16_t x,uint16_t y,uint16_t charColor,char c)
{
	GUI_showchar(x,y,charColor,&GUI_Font13HB_ASCII_CharInfo[c-0x20]);
}

void GUI_puts_vw(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	const GUI_CHARINFO* p;
	uint16_t x_size;
	while(*c!='\0')
	{
		p = &GUI_Font13HB_ASCII_CharInfo[*c-0x20];
		x_size = p->XSize;
		GUI_showchar(x,y,charColor,p);
		x+=x_size;
		c++;
	}
}

void GUI_showchar_24(uint16_t x,uint16_t y,uint16_t charColor,const GUI_CHARINFO* c)
{
	uint16_t i=0;
	uint16_t j=0;
	uint16_t x_size=0;
	const unsigned char* p;
	char tmp_char;
    x_size   = c->XSize;
	p        = c->pData;
	for (i=0;i<24;i++)
    {	
		tmp_char = *p;	   
    	for (j=0;j<x_size;j++)
	    {
			if(j==8||j==16)		                          // д��8��λ������һ�ֽ�
			{
			 	p++;
				tmp_char = *p;
			}	
			if ( (tmp_char >> 7-j%8) & 0x01 == 0x01)
	        {
	        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
	        }
        }
		p++;	
    }	
}

void GUI_putchar_vw_24(uint16_t x,uint16_t y,uint16_t charColor,char c)
{
	GUI_showchar_24(x,y,charColor,&CharInfo24B_ASCII[c-0x20]);
}

void GUI_puts_vw_24(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	const GUI_CHARINFO* p;
	uint16_t x_size;
	while(*c!='\0')
	{
		p = &CharInfo24B_ASCII[*c-0x20];
		x_size = p->XSize;
		GUI_showchar_24(x,y,charColor,p);
		x+=x_size;
		c++;
	}
}

void GUI_showchar_32(uint16_t x,uint16_t y,uint16_t charColor,const GUI_CHARINFO* c)
{
	uint16_t i=0;
	uint16_t j=0;
	uint16_t x_size=0;
	const unsigned char* p;
	char tmp_char;
    x_size   = c->XSize;
	p        = c->pData;
	for (i=0;i<32;i++)
    {	
		tmp_char = *p;	   
    	for (j=0;j<x_size;j++)
	    {
			if(j==8||j==16)		                          // д��8��λ������һ�ֽ�
			{
			 	p++;
				tmp_char = *p;
			}	
			if ( (tmp_char >> 7-j%8) & 0x01 == 0x01)
	        {
	        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
	        }
        }
		p++;	
    }	
}

void GUI_putchar_vw_32(uint16_t x,uint16_t y,uint16_t charColor,char c)
{
	GUI_showchar_32(x,y,charColor,&GUI_Font32_ASCII_CharInfo[c-0x20]);
}

void GUI_puts_vw_32(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	const GUI_CHARINFO* p;
	uint16_t x_size;
	while(*c!='\0')
	{
		p = &GUI_Font32_ASCII_CharInfo[*c-0x20];
		x_size = p->XSize;
		GUI_showchar_32(x,y,charColor,p);
		x+=x_size;
		c++;
	}
}



/****************************************************************************
* ��    �ƣ�void ili9320_PutChar(uint16_t x,uint16_t y,u8 c,uint16_t charColor,uint16_t bkColor)
* ��    �ܣ���ָ�������ʾһ��8x16�����ascii�ַ�
* ��ڲ���x          �����
*           y          �����
*           charColor  �ַ����ɫ
*           bkColor    �ַ���ɫ
* ���ڲ�����
* ˵    ������ʾ��Χ�޶�Ϊ����ʾ��ascii��
* ���÷�����ili9320_PutChar(10,10,'a',0x0000,0xffff);
****************************************************************************/
void GUI_putchar_16_8(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c)
{
	uint16_t i=0;
	uint16_t j=0;
  
	uint8_t tmp_char=0;

	for (i=0;i<16;i++)
    {		   
    	tmp_char=fixedsys_font[((c-0x20)*16)+i];
    	for (j=0;j<8;j++)
    	{
		if ( (tmp_char >> 7-j) & 0x01 == 0x01)
        {
        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
        }
    }
  }
}

void GUI_puts_16_8(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	while(*c!='\0')
	{
		GUI_putchar_16_8(x,y,charColor,*c);
		x+=8;
		c++;
	}
}

void GUI_putchar_6_4(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c)
{
	uint16_t i=0;
	uint16_t j=0;
  
	uint8_t tmp_char=0;

	for (i=0;i<6;i++)
    {		   
    	tmp_char=acFont4x6[(c-0x20)][i];
    	for (j=0;j<8;j++)
    	{
		if ( (tmp_char >> 7-j) & 0x01 == 0x01)
        {
        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
        }
    }
  }
}

void GUI_puts_6_4(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	while(*c!='\0')
	{
		GUI_putchar_6_4(x,y,charColor,*c);
		x+=4;
		c++;
	}
}


void GUI_putchar_8_6(uint16_t x,uint16_t y,uint16_t charColor,uint8_t c)
{
	uint16_t i=0;
	uint16_t j=0;
  
	uint8_t tmp_char=0;

	for (i=0;i<8;i++)
    {		   
    	tmp_char=GUI_acFont6x8[(c-0x20)][i];
    	for (j=0;j<8;j++)
    	{
		if ( (tmp_char >> 7-j) & 0x01 == 0x01)
        {
        	GUI_DrawPixel(x+j,y+i,charColor);  // �ַ���ɫ
        }
    }
  }
}

void GUI_puts_8_6(uint16_t x,uint16_t y,uint16_t charColor,const char* c)
{
	while(*c!='\0')
	{
		GUI_putchar_8_6(x,y,charColor,*c);
		x+=6;
		c++;
	}
}


/*******************************************************************************
* Function Name  :   GUI_printf()
* Description    :   Standard format output function for GUI
* Input          :   x,y: Position of words 
					 charColor: the color of words
                     format: standard format string like which is used in printf					 
* Return         :   Number of char displayed
*******************************************************************************/

int GUI_printf(uint16_t x,uint16_t y,uint16_t charColor,uint16_t font,const char* format,...)
{
	char        obuffer[BUFFER_SIZE];
	int         chars;
	va_list		ap;
	va_start( ap, format );
	chars = vsprintf(obuffer,format,ap);
	GUI_puts(x,y,charColor,font,obuffer);
	va_end( ap );
	return chars;
}

#ifdef Chinese_Support

void GetChineseCode(u8* pBuffer,u16 ChineseCode)
{
  
  u8 High8bit,Low8bit,i;
  u16 temp;
  
  temp=ChineseCode-0xA0A0;//���������λ��
  temp=ChineseCode;
  High8bit=(temp>>8);
  Low8bit=(temp&0x00FF);
  
  for(i=0;i<32;i++)
     	*(pBuffer+i)= *(HzLib + 32*((High8bit-0xb0)*94+Low8bit-0xa1) + i);

}
/****************************************************************
������  Lcdд1�����ĺ���
��ڲ���x,������꣬�����ҷֱ���0~15
          y,������꣬���ϵ��·ֱ�Ϊ0~19
          CharColaor,�ַ����ɫ 
          CharBackColor,�ַ���ɫ 
          ASCIICode,��Ӧ���ĵı���


*****************************************************************/
void GUI_putchar_chinese(uint16_t x,uint16_t y,uint16_t CharColor,uint16_t ChineseCode)
{
	uint8_t ByteCounter,BitCounter;
	uint8_t *ChinesePointer;
	uint8_t ChineseBuffer[32];
	uint16_t x_t=x,y_t=y;
	GetChineseCode(ChineseBuffer,ChineseCode);
	ChinesePointer=ChineseBuffer;
	
	for(ByteCounter=0; ByteCounter<32; ByteCounter++)
	{ 
		for(BitCounter=0;BitCounter<8;BitCounter++)
		{
			if((*ChinesePointer & (0x80 >> BitCounter)) != 0x00)
		    GUI_DrawPixel(x_t,y_t,CharColor);
			x_t++;
			if(x_t-x>15)
			{
				y_t++;
				x_t=x;
			}
		}
		ChinesePointer++;
	}
}

void GUI_puts_chinese(uint16_t x,uint16_t y,u16 CharColor,const char* s)
{
   char databuffer;
   uint16_t ChineseCode;
   do
   {
       databuffer=*s++;
       ChineseCode=databuffer<<8;
       ChineseCode=ChineseCode|*s++;
       GUI_putchar_chinese(x,y,CharColor,ChineseCode);
       x+=16;

   }while(*s!=0);

}
#endif
     

/****************************************************************************
* ��    �ƣ�void GUI_Drawdotted_line(uint16_t START_x,uint16_t START_y, uint16_t length, uint16_t gap, u16 Color , axis)
* ��    �ܣ���һ������
* ��ڲ���START_x    ��ʼ��x���
			START_y    ��ʼ��y���
*           length     ���ȣ���ĸ���
*           gap		   ��϶
*           Color      ��ɫ
*			xy  	   ����0Ϊx��1Ϊy����
* ���ڲ�����
* ˵    ������һ��x����y���������
* ���÷�����GUI_Drawdotted line(100,100,50, 5,Color ,0)
****************************************************************************/
void GUI_DrawDotted_Line(uint16_t START_x,uint16_t START_y, uint16_t length, uint16_t gap, uint16_t Color ,int xy)
{
	uint16_t i,j;
	gap++;
	if(xy)
	{
		j=START_y;
		for(i=0;i<length;i++)
		{
			GUI_DrawPixel(START_x,j,Color);
			j+=gap;
		}
	}
	else
	{
		j=START_x;
		for(i=0;i<length;i++)
		{
			GUI_DrawPixel(j,START_y,Color);
			j+=gap;
		}
	}		  	
}

/****************************************************************************
* ��    �ƣ�void GUI_DrawRounded_Rect(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height, u16 Color , int Fill)
* ��    �ܣ���һ��Բ�Ǿ���
* ��ڲ���START_x    ��ʼ��x���
			START_y    ��ʼ��y���
*           length     ����
*           height	   �߶�
*           Color      ��ɫ
*			Fill  	   �Ƿ���䣬1Ϊ��䣻0Ϊ���ģ�
* ���ڲ�����
* ˵    ������һ����Ϊheight������Ϊlength��Բ�Ǿ��Σ�
* ���÷�����GUI_DrawRounded_Rect(0, 0, 100, 100, Color ,0)
****************************************************************************/
void GUI_DrawRounded_Rect(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height, uint16_t Color , int Fill)
{
		GUI_DrawLine(START_x+1,START_y,START_x+length-2,START_y,Color);
		GUI_DrawLine(START_x,START_y+1,START_x,START_y+height-2,Color);	
		GUI_DrawLine(START_x+length-1,START_y+1,START_x+length-1,START_y+height-2,Color);	
		GUI_DrawLine(START_x+1,START_y+height-1,START_x+length-2,START_y+height-1,Color);
	if(Fill)
	{
		GUI_DrawBox(START_x+1,START_y+1,length-2,height-2,Color);		  		
	}
	else
	{
		GUI_DrawPixel(START_x+1,START_y+1,Color);
		GUI_DrawPixel(START_x+length-2,START_y+1,Color);
		GUI_DrawPixel(START_x+1,START_y+height-2,Color);
		GUI_DrawPixel(START_x+length-2,START_y+height-2,Color);
	}	   	
}
/****************************************************************************
* ��    �ƣ�void GUI_DrawSoft_Key(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height)
* ��    �ܣ���һ���?��
* ��ڲ���START_x    ��ʼ��x���
			START_y    ��ʼ��y���
*           length     ����
*           height	   �߶�
*			selected   �Ƿ�Ϊѡ�а���ѡ��Ϊ1����ѡ��Ϊ0
* ���ڲ�����
* ˵    ������һ��ָ����С���?��
* ���÷�����GUI_DrawSoft_Key(0,19,100,63,0);
****************************************************************************/
void GUI_DrawSoft_Key(uint16_t START_x, uint16_t START_y, uint16_t length, uint16_t height, int selected)
{
	
	GUI_DrawRounded_Rect(START_x,START_y,length,height,RGBto16bit(122,122,122),0);
	GUI_DrawRounded_Rect(START_x+1,START_y+1,length-2,height-2,RGBto16bit(252,252,252),0);
	if(selected)
		GUI_DrawRounded_Rect(START_x+2,START_y+2,length-4,height-4,RGBto16bit(189,184,176),1);	
	else
		GUI_DrawRounded_Rect(START_x+2,START_y+2,length-4,height-4,RGBto16bit(30,50,64),1);
}

