#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SYS_ID         *((volatile int*) FPGA_SYS_BASE)
#define SHIELD_CTRL_ADDRESS 0x200
#define SHIELD_CTRL_BASE    (SHIELD_CTRL_ADDRESS/4)
#define SHIELD_CTRL    *((volatile int*) FPGA_SYS_BASE+SHIELD_CTRL_BASE)

#define IOA_ADDRESS   0x0
#define IOA_BASE      (IOA_ADDRESS/4)
#define IOA           *((volatile int*)  FPGA_MOD_BASE+IOA_BASE)
#define IOA_ID        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 1)
#define IOA_DATA      *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 2)
#define IOA_OE        *((volatile int*)  FPGA_MOD_BASE+IOA_BASE+ 4)
#define IOA_IO_BASE   16
#define IOA_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE))
#define IOA_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+1)
#define IOA_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+2)
#define IOA_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+3)
#define IOA_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+4)
#define IOA_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+5)
#define IOA_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+6)
#define IOA_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+7)
#define IOA_IO_8      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+8)
#define IOA_IO_9      *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+9)
#define IOA_IO_10     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+10)
#define IOA_IO_11     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+11)
#define IOA_IO_12     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+12)
#define IOA_IO_13     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+13)
#define IOA_IO_14     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+14)
#define IOA_IO_15     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+15)
#define IOA_IO_16     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+16)
#define IOA_IO_17     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+17)
#define IOA_IO_18     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+18)
#define IOA_IO_19     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+19)
#define IOA_IO_20     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+20)
#define IOA_IO_21     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+21)
#define IOA_IO_22     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+22)
#define IOA_IO_23     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+23)
#define IOA_IO_24     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+24)
#define IOA_IO_25     *((volatile char*) (FPGA_MOD_BASE+IOA_BASE+IOA_IO_BASE)+25)


#define IOB_ADDRESS   0x80
#define IOB_BASE      (IOB_ADDRESS / 4)
#define IOB           *((volatile int*)  FPGA_MOD_BASE+IOB_BASE)
#define IOB_ID        *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 1)
#define IOB_DATA      *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 2)
#define IOB_OE        *((volatile int*)  FPGA_MOD_BASE+IOB_BASE+ 4)
#define IOB_IO_BASE   16
#define IOB_IO_0      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE))
#define IOB_IO_1      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+1)
#define IOB_IO_2      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+2)
#define IOB_IO_3      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+3)
#define IOB_IO_4      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+4)
#define IOB_IO_5      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+5)
#define IOB_IO_6      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+6)
#define IOB_IO_7      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+7)
#define IOB_IO_8      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+8)
#define IOB_IO_9      *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+9)
#define IOB_IO_10     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+10)
#define IOB_IO_11     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+11)
#define IOB_IO_12     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+12)
#define IOB_IO_13     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+13)
#define IOB_IO_14     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+14)
#define IOB_IO_15     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+15)
#define IOB_IO_16     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+16)
#define IOB_IO_17     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+17)
#define IOB_IO_18     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+18)
#define IOB_IO_19     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+19)
#define IOB_IO_20     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+20)
#define IOB_IO_21     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+21)
#define IOB_IO_22     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+22)
#define IOB_IO_23     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+23)
#define IOB_IO_24     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+24)
#define IOB_IO_25     *((volatile char*) (FPGA_MOD_BASE+IOB_BASE+IOB_IO_BASE)+25)

int* FPGA_MOD_BASE;
int* FPGA_SYS_BASE;
const int length = 4096;

#include<stdlib.h>
#include<stdarg.h>
char log_buffer[2048];
char* pbuffer = log_buffer;
//int debuginf(const char* fmt,...)
//{
//	va_list argptr;
//	int cnt;
//
//	va_start(argptr, fmt);
//	cnt = vsprintf(pbuffer, fmt, argptr);
//	va_end(argptr);
//	pbuffer+=cnt;
//	return(cnt);
//}
#define debuginf printf
////读传感器 端口位定义，可修改
//#define Sensor_SDA  IOB_IO_15
//#define Sensor_SCL  IOB_IO_16
//
//// 变量定义
//unsigned char Sensor_Data[5]={0x00,0x00,0x00,0x00,0x00};
//unsigned char Sensor_Check;		  //校验和
//
//unsigned char Sensor_AnswerFlag;  //收到起始标志位
//unsigned char Sensor_ErrorFlag;   //读取传感器错误标志
//unsigned int  Sys_CNT;
//unsigned int  Tmp;
//
///********************************************\
//|* 功能： 读传感器发送的单个字节	        *|
//\********************************************/
//unsigned char Read_SensorData(void)
//  {
//	unsigned char i,cnt;
//	unsigned char buffer,tmp;
//	buffer = 0;
//	for(i=0;i<8;i++)
//	{
//		cnt=0;
//		while(!Sensor_SDA)	//检测上次低电平是否结束
//		{
//		  printf("Sensor_SDA=%d\n", Sensor_SDA);
//		  usleep(1);
//		  if(++cnt >= 300)
//		   {
//			  break;
//		   }
//		}
//		//延时Min=26us Max50us 跳过数据"0" 的高电平
//		usleep(30);	 //延时30us
//
//		//判断传感器发送数据位
//		tmp =0;
//		if(Sensor_SDA)
//		{
//		  tmp = 1;
//		}
//		cnt =0;
//		while(Sensor_SDA)		//等待高电平 结束
//		{
//			printf("Sensor_SDA=%d\n", Sensor_SDA);
//		   	if(++cnt >= 200)
//			{
//			  break;
//			}
//		}
//		buffer <<=1;
//		buffer |= tmp;
//	}
//	return buffer;
//  }
//
///********************************************\
//|* 功能： 读传感器              	        *|
//\********************************************/
//unsigned char Read_Sensor(void)
//  {
//	unsigned char i;
//	//主机拉低(Min=800US Max=20Ms)
//    Sensor_SDA = 0;
//	usleep(2000);  //延时2Ms
//
//	//释放总线 延时(Min=30us Max=50us)
//	Sensor_SDA = 1;
//	usleep(30);//延时30us
//	//主机设为输入 判断传感器响应信号
//	Sensor_SDA = 1;
//
//	Sensor_AnswerFlag = 0;  // 传感器响应标志
//
//	//判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行
//	if(Sensor_SDA ==0)
//	{
//	   Sensor_AnswerFlag = 1;//收到起始信号
//	   Sys_CNT = 0;
//	   //判断从机是否发出 80us 的低电平响应信号是否结束
//	   while((!Sensor_SDA))
//	   {
//		 printf("Sensor_SDA=%d\n", Sensor_SDA);
//		  usleep(1);
//	     if(++Sys_CNT>300) //防止进入死循环
//		 {
//		   Sensor_ErrorFlag = 1;
//		   printf("Error 1\n");
//		   return 0;
//		  }
//	    }
//	    Sys_CNT = 0;
//	    //判断从机是否发出 80us 的高电平，如发出则进入数据接收状态
//	    while((Sensor_SDA))
//	    {
//	    	usleep(1);
//		   printf("Sensor_SDA=%d\n", Sensor_SDA);
//	       if(++Sys_CNT>300) //防止进入死循环
//		   {
//
//		     Sensor_ErrorFlag = 1;
//			 printf("Error 2\n");
//		     return 0;
//		   }
//	    }
//	    // 数据接收	传感器共发送40位数据
//	    // 即5个字节 高位先送  5个字节分别为湿度高位 湿度低位 温度高位 温度低位 校验和
//	    // 校验和为：湿度高位+湿度低位+温度高位+温度低位
//	    for(i=0;i<5;i++)
//	    {
//	      Sensor_Data[i] = Read_SensorData();
//	    }
//	  }
//	  else
//	  {
//	    Sensor_AnswerFlag = 0;	  // 未收到传感器响应
//	  }
//	  printf("Sensor_ErrorFlag=%d\n",Sensor_ErrorFlag);
//	  return 1;
//  }
//
//void Clear_Data (void)
//  {
//	int i;
//	for(i=0;i<5;i++)
//	{
//	   Sensor_Data[i] = 0x00;
//	 }//接收数据清零
//  }
//
//void print_Data (void)
//  {
//	int i;
//	for(i=0;i<5;i++)
//	{
//	   printf("0x%x ", Sensor_Data[i]);
//	 }//接收数据清零
//	printf("\n");
//  }
//
//void UART_PutStringAndNum(unsigned char *buf ,unsigned int num)
//  {
//	unsigned char a[3],i;
//	a[3] = '0'+num%10;
//	a[2] = '.';
//	a[1] = '0'+num/10%10;
//	a[0] = '0'+num/100%10;
//	while(*buf)
//      putchar(*buf++);
//	putchar(' ');
//	 for(i=0;i<4;i++)
//	{
//		putchar(a[i]);
//	}
//  }
#define Sensor_SDA  IOB_IO_15

char AM_2301_read_1bit()
{
	while(!Sensor_SDA);
	usleep(40);
	debuginf("1 bit data %d\n",Sensor_SDA);
	while(!Sensor_SDA);
	return Sensor_SDA;
}

unsigned char AM_2301_read_byte()
{
	int  i;
	char data=0;
	for(i=0; i<8; i++)
	{
		data += AM_2301_read_1bit()<<i;
	}
	debuginf("8 bit data 0x%x\n",data);
	return data;
}

int AM_2301_read_data()
{
	char data_buffer[5];
	int i;
	int ret;

	IOB_OE = 0xffffffff;
	Sensor_SDA = 1;
	Sensor_SDA = 0;
	usleep(2000);  //delay 2ms
	Sensor_SDA = 1;
	IOB_OE = 0x0;
	while(Sensor_SDA);
	debuginf("s1");
	while(!Sensor_SDA);
	debuginf("s2");
	while(Sensor_SDA);
	debuginf("ready to read date\n");
	// ready to ready date
	for(i=0; i<5; i++)
	{
		data_buffer[i] = AM_2301_read_byte();
	}
	ret = (int)data_buffer[0]+((int)data_buffer[1])<<8+((int)data_buffer[2])<<16+((int)data_buffer[3])<<24;
	debuginf("32 bit data 0x%x\n",ret);
	return ret;
}

int main(int argn, char* argv[])
{
	  int sysmem_fd;

	  sysmem_fd = open("/sys/kernel/debug/lophilo/modmem", O_RDWR);
	  FPGA_MOD_BASE = mmap(
		  0,  // starting address
		  length, // length
		  PROT_READ | PROT_WRITE,  //prot
		  MAP_SHARED, //flags
		  sysmem_fd, //filedescriptor
		  0x0 // offset
		  );
	  close(sysmem_fd);
	  sysmem_fd = open("/sys/kernel/debug/lophilo/sysmem", O_RDWR);
	  FPGA_SYS_BASE = mmap(
		  0,  // starting address
		  length, // length
		  PROT_READ | PROT_WRITE,  //prot
		  MAP_SHARED, //flags
		  sysmem_fd, //filedescriptor
		  0x0 // offset
		  );
	  close(sysmem_fd);
	  printf("FPGA ID=0x%x\n", IOB_ID);
	  SHIELD_CTRL = 0x03030300;
	  //IOA_OE      = 0xffffffff;
	  IOB_OE      = 0xffffffff;
	  printf("IOB_OE =0x%x\n", IOB_OE);
	  printf("&IOB_OE =0x%x\n", &IOB_OE);
	  printf("&IOA_OE =0x%x\n", &IOA_OE);

	  //Sensor_SDA = 1;
	  IOB_OE = 0x0;
	  debuginf("%d",Sensor_SDA);
	  //while(1)
	  //{
	//	  IOB_DATA=0;
		  //usleep(20);
	//	  IOB_DATA=0xffffffff;
		  //usleep(20);
	//  }
//	  while(1)
//	  {
		  printf("0x%x\n",AM_2301_read_data());

//	      Tmp = Sensor_Data[0]*256+Sensor_Data[1];
//	      UART_PutStringAndNum("M",Tmp);
//	   	  Tmp = Sensor_Data[2]*256+Sensor_Data[3];
//	      UART_PutStringAndNum("T",Tmp);
//		  usleep(2000000);
//	  }
	  printf(log_buffer);
	  printf("\n");
	  munmap(FPGA_SYS_BASE, length);
	  munmap(FPGA_MOD_BASE, length);

  return 0;
}
