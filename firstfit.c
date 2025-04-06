#include <stdio.h>
#include <stdlib.h>

struct block
{
	int size;
	int pid;
	struct block*next;
};

struct block* createblock(int n)
{
	struct block* head=NULL,*temp=NULL,*newb=NULL;
	for (int i=0;i<n;i++)
	{
		newb=(struct block*)malloc(sizeof(struct block));
		printf("Enter size of block: ");
		scanf("%d",&newb->size);
		newb->pid=-1;
		newb->next=NULL;
		if (head==NULL)
		{
			head=newb;
			temp=newb;
		}
		else
		{
			temp->next=newb;
			temp=newb;
		}
	}
	return head;
}

void firstfit(struct block* head,int sizep,int pi)
{
	struct block*temp=head;
	while(temp)
	{
		if (temp->pid==-1 && sizep <= (temp->size))
		{
			temp->pid=pi;
			return;
		}
		temp=temp->next;
	}
}

void display(struct block* head)
{
	printf("Memory Allocation\n");
	printf("Block size\tprocess\n");
	struct block* temp=head;
	while(temp)
	{
		printf("%d\t\t",temp->size);
		if (temp->pid==-1)
		{
			printf("Not allocated\n");
		}
		else
		{
			printf("p%d\n",temp->pid);
		}
		temp=temp->next;
	}
}

int main()
{
	printf("Enter number of blocks: ");
	int n,m;
	scanf("%d",&n);
	
	struct block * head=createblock(n);
	
	printf("Enter number of process: ");
	scanf("%d",&m);
	
	int sizep;
	for (int i=0;i<m;i++)
	{
		printf("Enter size of process: ");
		scanf("%d",&sizep);
		firstfit(head,sizep,i);
	}
	display(head);
}
