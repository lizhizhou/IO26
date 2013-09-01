/*
 * debug.c
 *
 *  Created on: Oct 26, 2012
 *      Author: Zhizhou Li
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<execinfo.h>

#define LOG_BUFFER_SIZE 2048
char log_buffer[LOG_BUFFER_SIZE];
char* pbuffer = log_buffer;
static int debug_flag = 0;
int debuginf(const char* fmt,...)
{
	if(debug_flag)
	{
		va_list argptr;
		int cnt;

		va_start(argptr, fmt);
		cnt = vprintf(fmt, argptr);
		va_end(argptr);
		return(cnt);
	}
	else
		return (0);
}
//int debuginf(const char* fmt,...)
//{
//	if(debug_flag)
//	{
//		va_list argptr;
//		int cnt;
//
//		va_start(argptr, fmt);
//		cnt = vsprintf(pbuffer, fmt, argptr);
//		va_end(argptr);
//		pbuffer+=cnt;
//		return(cnt);
//	}
//	else
//		return (0);
//}
//int print_log()
//{
//	int i;
//	for(i=0;i<LOG_BUFFER_SIZE || log_buffer[i] == '\0';i++)
//		putchar(log_buffer[i]);
//	return (i);
//}
#define TRACE_BUFFER_SIZE 2048
void trace_back()
{
    void *buffer[TRACE_BUFFER_SIZE];
    int returned_size;
    char **strings;
    int i=0;
    returned_size=backtrace(buffer,TRACE_BUFFER_SIZE);
    printf("%d addresses are returned.\n",returned_size);
    strings=backtrace_symbols(buffer,returned_size);
    if(strings==NULL)
    	return;
    for(i=0;i<returned_size;i++)
    {
    	printf("%s\n",strings[i]);
    }
}
