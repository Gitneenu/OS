#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid,at,bt,ct,wt,tat,remain,status;
};

struct node
{
	struct process*process;
	struct node* next;
}*front=NULL,*rear=NULL;

 void sort(int n,struct process p[n])
{
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (p[i].at>p[j].at)
			{
				struct process temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}


void enqueue(struct process *p)
{
	struct node* noden=(struct node*)malloc(sizeof(struct node));
	noden->process=p;
	noden->next=NULL;
	if (front==NULL)
	{
		front=rear=noden;
	}
	else
	{
		rear->next=noden;
		rear=noden;
	}
}

struct process* dequeue()
{
	if (front==NULL)
	{
		return NULL;
	}
	struct node* noden=front;
	struct process*temp=noden->process;
	front=front->next;
	free(noden);
	return temp;
}

void roundrobin(int n,int tq,struct process p[n])
{
	int currenttime=0;
	int completed=0;
	printf("Gantt chart\n");
	
	enqueue(&p[0]);
	p[0].status=1;
	
	while(completed<n)
	{
		struct process* proc=dequeue();
		if (proc)
		{
			int exec=((proc->remain < tq)?(proc->remain):tq);
			proc->remain=proc->remain-exec;
			currenttime=currenttime+exec;
			printf("p%d  %d|",proc->pid,currenttime);
			
			for (int i=0;i<n;i++)
			{
				if (!p[i].status && p[i].at<=currenttime)
				{
					enqueue(&p[i]);
					p[i].status=1;
				}
			}
			if (proc->remain==0)
			{
				proc->ct=currenttime;
				completed++;
			}
			else
			{
				enqueue(proc);
			}
		}
	}
}


void display(int n,struct process p[n])
{
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	float twt=0,ttat=0;
	for (int i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
		twt=twt+p[i].wt;
		ttat=ttat+p[i].tat;
	}
	printf("\nAverage waiting time is %.2f\n",twt/n);
	printf("Average turn around time is %.2f",ttat/n);
	
}

int main()
{
	printf("Enter number of processes:");
	int n;
	scanf("%d",&n);
	
	struct process p[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Enter at and bt for p%d",i);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].pid=i;
		p[i].status=0;
		p[i].remain=p[i].bt;
	}
	
	printf("Enter time quantum:");
	int tq;
	scanf("%d",&tq);
	
	sort(n,p);
	
	roundrobin(n,tq,p);
	display(n,p);
}
