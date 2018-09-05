#include "thread.h"
int main()
{
  int id1,id2,id3,id4;
  pthread_t tid1,tid2,tid3,tid4;

  
  sem1=sem_open("sem11",O_CREAT|O_EXCL,0777,1);
   if(sem1 == SEM_FAILED) {
        perror(" sem_open failed");
        return 0;
    }
  sem2=sem_open("sem21",O_CREAT|O_EXCL,0777,0);
   if(sem2 == SEM_FAILED) {
        perror(" sem_open failed");
        return 0;
    }
  sem3=sem_open("sem31",O_CREAT|O_EXCL,0777,0);
  if(sem3 == SEM_FAILED) {
        perror(" sem_open failed");
        return 0;
    }
  sem4=sem_open("sem41",O_CREAT|O_EXCL,0777,0);
   if(sem4 == SEM_FAILED) {
        perror(" sem_open failed");
        return 0;
    }
//  sem_close(sem1);
//  sem_close(sem2);
//  sem_close(sem3);
//  sem_close(sem4);


  sem_unlink("sem11");
  sem_unlink("sem21");
  sem_unlink("sem31");
  sem_unlink("sem41");
    id1=pthread_create(&tid1,NULL,thread1,NULL);
    if(id1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",id1);
         exit(EXIT_FAILURE);
     }
     
     sleep(5);
    id2=pthread_create(&tid2,NULL,thread2,NULL);
    if(id2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",id2);
         exit(EXIT_FAILURE);
     }
     sleep(5);
    id3=pthread_create(&tid3,NULL,thread3,NULL);
    if(id3)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",id3);
        exit(EXIT_FAILURE);
     }
     sleep(5);
    id4=pthread_create(&tid4,NULL,thread4,NULL);
    if(id4)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",id4);
         exit(EXIT_FAILURE);
     }
     sleep(5);
    if ( pthread_join(tid1,NULL) != 0) {
       perror("pthread_join() error");
        exit(0);
       }
    if (  pthread_join(tid2,NULL) != 0) {
       perror("pthread_join() error");
        exit(0);
       }
     if (  pthread_join(tid3,NULL) != 0) {
       perror("pthread_join() error");
        exit(0);
       }
      if (  pthread_join(tid4,NULL) != 0) {
       perror("pthread_join() error");
        exit(0);
       }
   

  
}
void *thread1(void *ptr)
{
  int i=1;
 while(1)
  {
	  sem_wait(sem1);
	  printf("thread1 value is %d\n",i);
	  sem_post(sem2);
	 
   }
    pthread_exit(0);
}
void *thread2(void *ptr)
{
  int i=2;
  while(1)
  {
	  sem_wait(sem2);
	  printf("thread2 value is %d\n",i);
	  sem_post(sem3);
	 
  }
   pthread_exit(0);
}
void *thread3(void *ptr)
{

  int i=3;
  while(1)
  {
	  sem_wait(sem3);
	  printf("thread3 value is %d\n",i);
	  sem_post(sem4);
	  
  }
   pthread_exit(0);
  
}
void *thread4(void *ptr)
{

  int i=4;
 while(1)
  {
	  sem_wait(sem4);
	  printf("thread4 value is %d\n",i);
	  sem_post(sem1);
	  
  }
   pthread_exit(0);
}
