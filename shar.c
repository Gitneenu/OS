#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>


#define shm_size 1024

int main()
{
	int shmid;
	key_t key;
	pid_t child_pid;
	char * shmptr;
	
	key=ftok(".",'X');
	if (key==-1)
	{
		perror("ftok");
		exit(1);
	}
	
	shmid=shmget(key,shm_size,IPC_CREAT|0666);
	{
		if(shmid==-1)
		{
			perror("shmget");
			exit(1);
		}
	}
	
	child_pid=fork();
	
	if(child_pid==-1)
	{
		perror("fork");
		exit(1);
	}
		
	else if(child_pid==0)
	{
		shmptr=shmat(shmid,NULL,0);
		if (shmptr==(char*)-1)
		{
			perror("shmat");
			exit(1);
		}
		printf("Reader :%s",shmptr);
			
		if (shmdt(shmptr)==-1)
		{
			perror("shmdt");
			exit(1);
		}
		exit(0);
	}
		
	else
	{
		shmptr=shmat(shmid,NULL,0);
		{
			if (shmptr==(char*)-1)
			{
				perror("shmat");
				exit(1);
			}
		}
		strcpy(shmptr,"I am doing ipc");
		if (shmdt(shmptr)==-1)
		{
			perror("shmdt");
			exit(1);
		}
		wait(NULL);
	}
	if (shmctl(shmid,IPC_RMID,NULL)==-1)
	{
		perror("shmctl");
		exit(1);
	}
	
	
	
}
