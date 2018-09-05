#ifndef THREAD_H
#define THREAD_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
void *thread1(void *ptr);
void *thread2(void *ptr);
void *thread3(void *ptr);
void *thread4(void *ptr);
sem_t *sem1,*sem2,*sem3,*sem4;

#endif


