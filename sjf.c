#include <stdio.h>
#include <limits.h>

struct process
{
	int pid,at,bt,ct,tat,wt,completed;
};

int shortest(int n,struct process p[n],int currenttime)
{
	int minindex=-1;
	int minb=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(!p[i].completed && p[i].at<=currenttime && p[i].bt<minb)
		{
			minindex=i;
			minb=p[i].bt;
		}
	}
	return minindex;
}

void sjf(int n,struct process p[n])
{
	int comply=0;
	int currenttime=0;
	printf("Gantt chart\n");
	int pro[n];
	int time[n];
	while (comply<n)
	{
	
		int shor=shortest(n,p,currenttime);
	
		if (shor==-1)
		{
			currenttime++;
			continue;
		}
		p[shor].ct=currenttime+p[shor].bt;
		p[shor].tat=p[shor].ct-p[shor].at;
		p[shor].wt=p[shor].tat-p[shor].bt;
		p[shor].completed=1;
		currenttime=p[shor].ct;
		pro[comply]=shor;
		time[comply]=p[shor].ct;
		comply=comply+1;
	}
	for (int i=0;i<n;i++)
	{
		printf("p%d\t",pro[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",time[i]);
	}
	
}

void display(int n,struct process p[n])
{
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for (int i=0;i<n;i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
}

int main()
{
	printf("Enter number of process ");
	int n;
	scanf("%d",&n);
	
	struct process p[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Enter at and bt for p%d",i);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].pid=i;
		p[i].completed=0;
	}
	
	sjf(n,p);
	display(n,p);
}
