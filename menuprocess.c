#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid,at,bt,ct,tat,wt,status,prio;
};

void initialise(int p,struct process pro[p])
{
	for(int i=0;i<p;i++)
	{
		pro[i].status=0;
		pro[i].ct=0;
		pro[i].tat=0;
		pro[i].wt=0;
	}
}	

void sortbyat(int p,struct process pro[p])
{
	for(int i=0;i<p;i++)
	{
		for(int j=i+1;j<p;j++)
		{
			if(pro[i].at>pro[j].at)
			{
				struct process temp=pro[i];
				pro[i]=pro[j];
				pro[j]=temp;
			}
		}
	}
}

int lowbt(int p,struct process pro[p],int current)
{
	int value=10000;
	int id=0;
	for(int i=0;i<p;i++)
	{
		if(pro[i].status==0 && pro[i].at<=current && pro[i].bt<value)
		{
			value=pro[i].bt;
			id=pro[i].pid;
		}
	}
	return id;
}

int lowprio(int p,struct process pro[p],int current)
{
	int value=10000;
	int id=0;
	for(int i=0;i<p;i++)
	{
		if(pro[i].status==0 && pro[i].at<=current && pro[i].prio<value)
		{
			value=pro[i].prio;
			id=pro[i].pid;
		}
	}
	return id;
}

void fcfs(int p,struct process pro[p])
{
	sortbyat(p,pro);
	int currenttime=0;
	printf("Gantt chart\n");
	for(int i=0;i<p;i++)
	{
		currenttime=currenttime+pro[i].bt;
		printf("p%d\t%d|",pro[i].pid,currenttime);
		pro[i].ct=currenttime;
		pro[i].tat=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].tat-pro[i].bt;
	}
}

void sjf(int p,struct process pro[p])
{
	initialise(p,pro);
	int current=0;
	int complete=0;
	printf("Gantt chart\n");
	while(complete<p)
	{
		int id=lowbt(p,pro,current);
		if (id==-1)
		{
			current++;
			continue;
		}
		for(int i=0;i<p;i++)
		{
			if (id==pro[i].pid)
			{
				current=current+pro[i].bt;
				printf("p%d\t%d|",id,current);
				pro[i].ct=current;
				pro[i].status=1;
				pro[i].tat=pro[i].ct-pro[i].at;
				pro[i].wt=pro[i].tat-pro[i].bt;
				complete++;
			}
		}
	}
	
}

void priority(int p,struct process pro[p])
{
	initialise(p,pro);
	int current=0;
	int complete=0;
	printf("Gantt chart\n");
	while (complete<p)
	{
		int id=lowprio(p,pro,current);
		if (id==-1)
		{
			current++;
			continue;
		}
		for(int i=0;i<p;i++)
		{
			if (id==pro[i].pid)
			{
				current=current+pro[i].bt;
				printf("p%d\t%d|",id,current);
				pro[i].ct=current;
				pro[i].status=1;
				pro[i].tat=pro[i].ct-pro[i].at;
				pro[i].wt=pro[i].tat-pro[i].bt;
				complete++;
			}
		}
	}
}

void display(int p,struct process pro[p],int ch)
{
	printf("PID\tAT\tBT\tCT\tTAT\tWT");
	if (ch==3)
	{
		printf("\tPRIORITY\n");
	}
	else
	{
		printf("\n");
	}
	float avgtat=0;
	float avgwt=0;
	for(int i=0;i<p;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d",pro[i].pid,pro[i].at,pro[i].bt,pro[i].ct,pro[i].tat,pro[i].wt);
		if(ch==3)
		{
			printf("\t%d\n",pro[i].prio);
		}
		else
		{
			printf("\n");
		}
		avgtat=avgtat+pro[i].tat;
		avgwt=avgwt+pro[i].wt;
	}
	printf("\nAverage waiting time is: %f",avgwt/p);
	printf("\nAverage turn around time is: %f",avgtat/p);
}

int main()
{
	printf("Enter number of process: ");
	int p;
	scanf("%d",&p);
	
	struct process pro[p];
	
	for(int i=0;i<p;i++)
	{
		printf("Enter at and bt: ");
		scanf("%d %d",&pro[i].at,&pro[i].bt);
		pro[i].pid=i;
		pro[i].status=0;
	}
	int chp=0;
	while(3)
	{
		printf("\n1.FCFS\n");
		printf("2.SJF\n");
		printf("3.Priority\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Enter choice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case(1):
			{
				fcfs(p,pro);
				chp=1;
				break;
			}
			case(2):
			{
				sjf(p,pro);
				chp=2;
				break;
			}
			case(3):
			{
				priority(p,pro);
				chp=3;
				break;
			}
			case(4):
			{
				display(p,pro,chp);
				break;
			}
			case(5):
			{
				exit(0);
			}
		}
	}
}
