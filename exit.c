/*
 * exit.c
 *
 *  Created on: Dec 1, 2013
 *      Author: zhizhouli
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <syslog.h>
#include <pthread.h>
#include <stdlib.h>
#include "temperature.h"
void signal_handler(int signo)
{
    signal(signo, signal_handler);
    switch(signo)
    {
        case SIGHUP:
             //终端退出
        	 printf( "Process will  exit, because tty is exit/n");
        	 stop_temperature_subsystem();
        	 stop_moisture_subsystem();
             exit(0);
             break;
        case SIGSEGV:
             //段错误，意味着指针所对应的地址是无效地址，没有物理内存对应该地址
        	 printf( "memory error/n");
        	 stop_temperature_subsystem();
        	 stop_moisture_subsystem();
             exit(1);
             break;
        case SIGTERM:
             //程序自己退出，或shell里调用kill缺省该进程。该信号可以被阻塞，或被处理
             //可以在这里做一些程序退出前的最后处理工作
        	 printf( "Process recieve SIGTERM/n");
        	 stop_temperature_subsystem();
        	 stop_moisture_subsystem();
             exit(0);
             break;
        case SIGQUIT:
             //按下ctrl+ "/"产生，程序退出，并产生core文件
        	 printf( "Process recieve SIGQUIT/n");
        	 stop_temperature_subsystem();
        	 stop_moisture_subsystem();
             exit(0);
             break;
        case SIGINT:
             //按下ctrl+c产生，程序终止
        	 printf( "Process recieve SIGINT/n");
        	 stop_temperature_subsystem();
        	 stop_moisture_subsystem();
             exit(0);
             break;
        case SIGALRM:
             //时钟定时信号
           	 printf("Process recieve SIGALRM");
             exit(0);
           	 break;
        case SIGCHLD:
             //处理子进程退出
             exit(0);
             break;
        default:
        	 printf("%d signal unregister/n", signo);
             break;
    }
}

void init_exit_hanedle()
{
    signal(SIGHUP, &signal_handler);
    signal(SIGSEGV, &signal_handler);
    signal(SIGQUIT, &signal_handler);
    signal(SIGINT,  &signal_handler);
    signal(SIGTERM, &signal_handler);
    signal(SIGALRM, &signal_handler);
    signal(SIGCHLD, &signal_handler);
}
