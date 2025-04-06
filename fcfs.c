#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid,at,bt,ct,tat,wt;
};

void sortbyat(struct process p[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
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

void fcfs(int n,struct process p[n])
{
	int currenttime=0;
	printf("Gantt chart\n");
	int pro[n];
	int time[n];
	int i;
	for(i=0;i<n;i++)
	{
		if (currenttime<p[i].at)
		{
			currenttime=p[i].at;
		}
		p[i].ct=currenttime+p[i].bt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		currenttime=p[i].ct;
		pro[i]=p[i].pid;
		time[i]=currenttime;
	}
	for(i=0;i<n;i++)
	{
		printf("p%d\t",pro[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",time[i]);
	}
}

void display(int n,struct process p[n])
{
	printf("\nPID\tAT\tBT\tCT\tTAT\tBT\n");
	for(int i=0;i<n;i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
		
	}
}

int main()
{
	printf("Enter number of processes ");
	int n;
	scanf("%d",&n);
	struct process p[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Enter at and bt for p%d:",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].pid=i+1;
	}
	
	sortbyat(p,n);
	fcfs(n,p);
	display(n,p);
}
