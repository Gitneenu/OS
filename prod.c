#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define buff_size 10

int buffer[buff_size];
int in=0,out=0;
sem_t empty,full;
pthread_mutex_t mutex;

void *producer(void*arg)
{
	int item;
	for(int i=0;i<10;i++)
	{
		item=rand()%100;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in]=item;
		in=(in+1)%buff_size;
		printf("Produced item is %d\n",item);
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		sleep(1);
	}
}

void * consumer(void*arg)
{
	int item;
	for(int i=0;i<10;i++)
	{
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		item=buffer[out];
		printf("Consumed item is %d\n",item);
		out=(out+1)%buff_size;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		sleep(1);
	}
}

int main()
{
	pthread_t prod,con;
	sem_init(&empty,0,buff_size);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&con,NULL,consumer,NULL);
	
	pthread_join(prod,NULL);
	pthread_join(con,NULL);
	
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);
