#include <stdio.h>

struct process
{
	int pid,at,bt,ct,tat,wt,completed,prio;
};

int nexty(int n,int currenttime,struct process p[n])
{
	int minindex=-1;
	int minprio=10000;
	for(int i=0;i<n;i++)
	{
		if (!p[i].completed && p[i].at<=currenttime && p[i].prio<minprio)
		{
			minprio=p[i].prio;
			minindex=i;
		}
	}
	return minindex;
}

void priority(int n,struct process p[n])
{
	int currenttime=0;
	int comply=0;
	printf("Gantt Chart\n");
	int pro[n];
	int time[n];
	while(comply<n)
	{
		int prio=nexty(n,currenttime,p);
		if(prio==-1)
		{
			currenttime++;
		}
		p[prio].ct=currenttime+p[prio].bt;
		p[prio].tat=p[prio].ct-p[prio].at;
		p[prio].wt=p[prio].tat-p[prio].bt;
		currenttime=p[prio].ct;
		p[prio].completed=1;
		pro[comply]=prio;
		time[comply]=currenttime;
		comply++;
		
		
	}
	for(int i=0;i<n;i++)
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
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tPriority\n");
	for (int i=0;i<n;i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].prio);
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
		printf("Enter at ,bt and prio for p%d",i);
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].prio);
		p[i].pid=i;
		p[i].completed=0;
	}
	priority(n,p);
	display(n,p);
}
