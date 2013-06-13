/*
 * sht1x.c
 *
 *  Created on: Jun 11, 2013
 *      Author: cowin
 */
#include <stdint.h>
#include "FPGA.h"
#include "sht1x.h"
#define SHT1X_ADDRESS  sht1x_address//0x220
#define SHT1X_ID      *((volatile int*) sht1x_address+1)
#define SHT1X_DATA    *((volatile int*) sht1x_address+3)
#define SHT1X_READY   *((volatile int*) sht1x_address+4)

void sht1x_init(void* sht1x_address)
{
//    printf("SHT1X ID   =0x%x\n", SHT1X_ID);
//    printf("SHT1X_DATA =0x%x\n", SHT1X_DATA);
//    printf("SHT1X_READY=0x%x\n", SHT1X_READY);
//    printf("Moisture=%.1f%%\n", SHT1X_get_moisture(SHT1X_address));
//    printf("Temperature=%.1fC\n", SHT1X_get_temperature(SHT1X_address));
}

float sht1x_get_temperature(void* sht1x_address)
{
      short temperature_data;
      int   sign;
      float temperature;
      while(SHT1X_READY!=1);
      sign             = 0x1 & (SHT1X_DATA>>15);
      temperature_data = 0x7fff & SHT1X_DATA;
      if (sign)
          temperature  = temperature_data/-10.0;
      else
          temperature  = temperature_data/10.0;
      return (temperature);
}

float SHT1X_get_moisture(void* sht1x_address)
{
      short moisture_data;
      float moisture;
      while(SHT1X_READY!=1);
      moisture_data    =  SHT1X_DATA >> 16;
      moisture     = moisture_data/10.0;
      return (moisture);
}
