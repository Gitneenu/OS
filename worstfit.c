#include <stdio.h>
#include <stdlib.h>
struct block
{
	int size;
	int pid;
	struct block* next;
};

struct block * createblock(int n)
{
	struct block *head=NULL,*rear=NULL,*newb=NULL;
	for(int i=0;i<n;i++)
	{
		newb=(struct block *)malloc(sizeof(struct block));
		printf("Enter size of block size: ");
		scanf("%d",&(newb->size));
		newb->pid=-1;
		newb->next=NULL;
		if (head==NULL)
		{
			head=newb;
			rear=newb;
		}
		else
		{
			rear->next=newb;
			rear=newb;
		}
	}
	return head;
}

void worstfit(struct block* head,int sizep,int pi)
{
	struct block * temp=head;
	struct block* worstb=NULL;
	int worsty=-1;
	while(temp)
	{
		if(temp->pid==-1 && sizep<=temp->size && temp->size>worsty)
		{
			worstb=temp;
			worsty=temp->size;
		}
		temp=temp->next;
	}
	if (worstb)
	{
	worstb->pid=pi;
	}
}

void display(struct block * head)
{
	struct block* temp=head;
	printf("Memory Allocation\n");
	printf("Block size\t Process\n");
	while(temp)
	{
		printf("%d\t\t",temp->size);
		if (temp->pid==-1)
		{
			printf("Not allocated\n");
		}
		else
		{
			printf("%d\n",temp->pid);
		}
		temp=temp->next;
	}
}	

int main()
{
	int m,n;
	printf("Enter number of blocks: ");
	scanf("%d",&n);
	
	struct block* head=createblock(n);
	
	printf("Enter number of process: ");
	scanf("%d",&m);
	
	int sizep;
	for (int i=0;i<m;i++)
	{
		printf("Enter process size: ");
		scanf("%d",&sizep);
		worstfit(head,sizep,i);
	}
	display(head);
}
