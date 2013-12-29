/*
 * panel.c
 *
 *  Created on: Dec 1, 2013
 *      Author: zhizhouli
 */
#include <stdio.h>
#include <stropts.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/netdevice.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "platform.h"
#include "GUI.h"
#include "led.h"
#include "lcd.h"
#include "shell.h"
#include "sht1x.h"
#include "keybroad.h"
#include "microscope.h"
int get_host_addresses(const int domain, char* ip_address)
{
  int s;
  struct ifconf ifconf;
  struct ifreq ifr[50];
  int ifs;
  int i;

  s = socket(domain, SOCK_STREAM, 0);
  if (s < 0) {
    perror("socket");
    return 0;
  }

  ifconf.ifc_buf = (char *) ifr;
  ifconf.ifc_len = sizeof ifr;

  if (ioctl(s, SIOCGIFCONF, &ifconf) == -1) {
    return 0;
  }

  ifs = ifconf.ifc_len / sizeof(ifr[0]);
  for (i = 1; i < ifs; i++) {
    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in *s_in = (struct sockaddr_in *) &ifr[i].ifr_addr;

    if (!inet_ntop(domain, &s_in->sin_addr, ip, sizeof(ip))) {
      perror("inet_ntop");
      return 0;
    }

    sprintf(ip_address, "%s",ip);
  }

  close(s);

  return 1;
}

/****************************************************************************
* 名    称：void FuncCell_set(uint16_t number,const char* c,uint16_t offset,int selected)
* 功    能：软按键内容
* 入口参数：number	按键号码
* 			char* c	打印字符串
* 			offset	偏移量
* 			selected是否被选中，选中为1，反色
* 出口参数：无
* 说    明：显示软按键的内容
* 调用方法：FuncCell_set(4,"Return",20,0);
****************************************************************************/
void FuncCell_set(uint16_t number,const char* c,uint16_t offset,int selected)
{
	switch(number)
	{
		case 1:
			{
				if(selected) GUI_printf(offset,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset,242,0xffff,Variational_Front_13,c);
					break;
			}
		case 2:
			{
				if(selected) GUI_printf(offset+80,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset+80,242,0xffff,Variational_Front_13,c);
					break;
			}
		case 3:
			{
				if(selected) GUI_printf(offset+160,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset+160,242,0xffff,Variational_Front_13,c);
					break;
			}
		case 4:
			{
				if(selected) GUI_printf(offset+240,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset+240,242,0xffff,Variational_Front_13,c);
					break;
			}
		case 5:
			{
				if(selected) GUI_printf(offset+320,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset+320,242,0xffff,Variational_Front_13,c);
					break;
			}
		case 6:
			{
				if(selected) GUI_printf(offset+400,242,0x0000,Variational_Front_13,c);
					else GUI_printf(offset+400,242,0xffff,Variational_Front_13,c);
					break;
			}
		default:break;
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

void GUI_DrawCircle_Limit(uint16_t CENTER_x, uint16_t CENTER_y,uint16_t RADIUS_r, uint16_t Color, uint16_t Fill_Color, int Fill, int Circle)
{
   int ERROR = 1 - RADIUS_r;
   int ddF_x = 0;
   int ddF_y = -2 * RADIUS_r;
   int x = 0;
   int y = RADIUS_r;
   if(Fill)
      if(Circle){
         Fill=FALSE;
         GUI_DrawCircle_Limit(CENTER_x, CENTER_y, RADIUS_r,Color,Fill_Color, TRUE,FALSE );
      }
    if(Fill){
      GUI_DrawLine(479, CENTER_y,CENTER_x - RADIUS_r,CENTER_y, Fill_Color );
    }
   if(Circle){
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
         if((CENTER_x - x)<480)
        	 GUI_DrawLine(CENTER_x - x, CENTER_y + y, CENTER_x - x, CENTER_y - y, Fill_Color );
         if((CENTER_x - y)<480)
        	 GUI_DrawLine(CENTER_x - y, CENTER_y + x, CENTER_x - y, CENTER_y - x, Fill_Color );
         }
      if(Circle){
    	  if((CENTER_x - x)<480) {
    		  GUI_DrawPixel(CENTER_x - x, CENTER_y + y,Color);
    		  GUI_DrawPixel(CENTER_x - x, CENTER_y - y,Color);
    	  }
    	  if((CENTER_x - y)<480) {
    		  GUI_DrawPixel(CENTER_x - y, CENTER_y + x,Color);
    		  GUI_DrawPixel(CENTER_x - y, CENTER_y - x,Color);
    	  }
         }
   }
 }

/****************************************************************************
* 名    称：Window_Start()
* 功    能：标题栏
* 入口参数：无
* 出口参数：无
* 说    明：start window
* 调用方法：Window_Start();
****************************************************************************/

void Window_Start()
{
	char ip[30]= "10.235.6.197";
	lcd_clear(0,0,0);
	GUI_DrawLine(0,27,479,27,RGBto16bit(252,252,252));	   //亮x线
	GUI_DrawLine(0,26,479,26,RGBto16bit(180,175,160));  //暗x线
	GUI_printf(5,5,0xffff,Variational_Front_13,"IN:  Temp:");
	GUI_DrawDotted_Line(135,0,13,1,RGBto16bit(252,252,252),1);
	GUI_printf(145,5,0xffff,Variational_Front_13,"Hum:");
	GUI_DrawLine(235,0,235,26,RGBto16bit(252,252,252));  //亮y线
	GUI_DrawLine(236,0,236,26,RGBto16bit(252,252,252));  //亮y线
	GUI_printf(245,5,0xffff,Variational_Front_13,"OUT:  Temp:");
	GUI_DrawDotted_Line(375,0,13,1,RGBto16bit(252,252,252),1);
	GUI_printf(385,5,0xffff,Variational_Front_13,"Hum:");

	GUI_DrawCircle_Limit(560,120,120,0x0000,RGBto16bit(30,50,64),1,0);  // Draw circle

	GUI_DrawSoft_Key(0,227,80,45,0);	 //软按键1
	GUI_DrawSoft_Key(80,227,80,45,0);	 //软按键2
	GUI_DrawSoft_Key(160,227,80,45,0);	 //软按键3
	GUI_DrawSoft_Key(240,227,80,45,0);	 //软按键4
	GUI_DrawSoft_Key(320,227,80,45,0);	 //软按键5
	GUI_DrawSoft_Key(400,227,80,45,0);	 //软按键6
	FuncCell_set(1,"< Syrng",13,0);		 //软按键区域内容  << Syringe
	FuncCell_set(2,"Syrng >",15,0);	 	//软按键区域内容  Syringe >>
	FuncCell_set(3,"LED +",25,0);		 //软按键区域内容  light
	FuncCell_set(4,"LED -",25,0);		 //软按键区域内容  User
	FuncCell_set(5,"Exit",28,0);		 //软按键区域内容  Exit
	FuncCell_set(6,"IP Addr.",15,0);	 //软按键区域内容  Ip Address

	GUI_printf(70,70,0xffff,Variational_Front_13,"Rotary knob :    Ajust the focus");
	GUI_printf(70,120,0xffff,Variational_Front_13,"Direction keys:    Move the image");
	//GUI_printf(70,130,0xffff,Variational_Front_13,"F1 F2:Move the Syringe");
	//GUI_printf(70,170,0xffff,Variational_Front_13,"F3 F4:Change the light of LED");
	GUI_printf(70,170,0xffff,Variational_Front_13,"IP Address:");
	//GUI_printf(70,70,0xffff,Variational_Front_32,"IP Address:");
	get_host_addresses(AF_INET,ip);
	GUI_printf(170,160,0xffff,Variational_Front_32,ip);

}

void* pannel_task(void* arg)
{
	int color = 0;
	char delta1, delta2;
	key_value key;
	float temp1  =0;
	float temp2  =0;
	float moist1 =0;
	float moist2 =0;
	Window_Start();
	while(1) {
    	temp1 = sht1x_get_temperature(SHT1X_0);
    	temp2 = sht1x_get_temperature(SHT1X_1);
    	moist1 = sht1x_get_moisture(SHT1X_0);
    	moist2 = sht1x_get_moisture(SHT1X_1);
    	key = return_key();
		if(key == KEY_F1){
			syringe_forward_step(200);
		} else if(key == KEY_F2){
			syringe_back_step(200);
		} else if(key == KEY_F3){

		} else if(key == KEY_F4){

		} else if(key == KEY_F5){
			exit(1);
		} else if(key == KEY_F6){

		} else if(key == KEY_UP){
			microscope_y_plus(200);
		} else if(key == KEY_DOWN){
			microscope_y_minus(200);
		} else if(key == KEY_LEFT){
			microscope_x_minus(200);
		} else if(key == KEY_RIGHT){
			microscope_x_plus(200);
		}
    	//pthread_mutex_lock(&mutex);
		delta1 = get_encoder_delta1();
		delta2 = get_encoder_delta2();
		if(delta1 > 0)
			microscope_z_plus(delta1);
		else
			microscope_z_minus(-delta1);
		if(delta2 > 0)
			microscope_z_plus(delta2 * 100);
		else
			microscope_z_minus(-delta2 * 100);
        //pthread_mutex_unlock(&mutex);
		GUI_printf(79,5,RGBto16bit(255,255,0),Variational_Front_13,"%0.1f\x81",temp2);
		GUI_printf(324,5,RGBto16bit(255,255,0),Variational_Front_13,"%0.1f\x81",temp1);
		GUI_printf(185,5,RGBto16bit(255,255,0),Variational_Front_13,"%0.1f%%",moist2);
		GUI_printf(425,5,RGBto16bit(255,255,0),Variational_Front_13,"%0.1f%%",moist1);
		sleep(1);
		GUI_printf(79,5,RGBto16bit(0,0,0),Variational_Front_13,"%0.1f\x81",temp2);
		GUI_printf(324,5,RGBto16bit(0,0,0),Variational_Front_13,"%0.1f\x81",temp1);
		GUI_printf(185,5,RGBto16bit(0,0,0),Variational_Front_13,"%0.1f%%",moist2);
		GUI_printf(425,5,RGBto16bit(0,0,0),Variational_Front_13,"%0.1f%%",moist1);
	}
}

void pannel_init()
{
	lcd_init();
	pthread_t lcd;
	pthread_create(&lcd, NULL, pannel_task, NULL);
}

