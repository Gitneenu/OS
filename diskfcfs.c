#include <stdio.h>
#include <stdlib.h>

void fcfs(int r,int st,int request[r])
{
	int seektime=0;
	int parseek=0;
	int current=st;
	for(int i=0;i<r;i++)
	{
		parseek=abs(current-request[i]);
		seektime=seektime+parseek;
		current=request[i];
	}
	printf("Total seek time is %d: ",seektime);
}

int main()
{
	int r,st;
	printf("Enter number of requests: ");
	scanf("%d",&r);
	
	int request[r];
	
	printf("Enter request: ");
	for (int i=0;i<r;i++)
	{
		scanf("%d",&request[i]);
		
	}
	printf("Enter starting time: ");
	scanf("%d",&st);
	
	fcfs(r,st,request);
}
