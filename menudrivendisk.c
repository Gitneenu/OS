#include <stdio.h>
#include <stdlib.h>

void sortorder(int r,int request[r])
{
	for(int i=0;i<r;i++)
	{
		for(int j=i+1;j<r;j++)
		{
			if(request[i]>request[j])
			{
				int temp=request[i];
				request[i]=request[j];
				request[j]=temp;
			}
		}
	}
}

void fcfs(int r,int request[r],int hs)
{
	int seektime=0;
	int current=hs;
	for(int i=0;i<r;i++)
	{
		seektime=seektime+abs(current-request[i]);
		current=request[i];
	}
	printf("Seektime is %d",seektime);
}

void scan(int r,int request[r],int hs)
{
	sortorder(r,request);
	int index=0;
	for(int i=0;i<r;i++)
	{
		if (request[i]<hs)
		{
			index++;
		}
	}
	int dir,size,seektime=0,current;
	printf("Enter direction(1 for forward and 0 for backward)and disk size: ");
	scanf("%d %d",&dir,&size);
	if (dir==1)
	{
		
		current=hs;
		for(int i=index;i<r;i++)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		seektime=seektime+abs(current-(size-1));
		current=size-1;
		for(int i=index-1;i>=0;i--)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		printf("Seektime is %d",seektime);
	}
	else
	{
		current=hs;
		for(int i=index-1;i>=0;i--)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		if (current!=0)
		{
			seektime=seektime+current;
			current=0;
		}
		for(int i=index;i<r;i++)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		printf("Seektime is %d",seektime);
	}
}

void cscan(int r,int request[r],int hs)
{
	sortorder(r,request);
	int index=0;
	for(int i=0;i<r;i++)
	{
		if (request[i]<hs)
		{
			index++;
		}
	}
	int dir,size,seektime=0,current;
	printf("Enter direction(1 for forward and 0 for backward)and disk size: ");
	scanf("%d %d",&dir,&size);
	if (dir==1)
	{
		
		current=hs;
		for(int i=index;i<r;i++)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		seektime=seektime+abs(current-(size-1));
		seektime=seektime+size-1;
		current=0;
		for(int i=0;i<index;i++)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		printf("Seektime is %d",seektime);
	}
	else
	{
		current=hs;
		for(int i=index-1;i>=0;i--)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		if (current!=0)
		{
			seektime=seektime+current;
		}
		seektime=seektime+(size-1);
		current=size-1;
		for(int i=r-1;i>=index;i--)
		{
			seektime=seektime+abs(current-request[i]);
			current=request[i];
		}
		printf("Seektime is %d",seektime);
	}
}


int main()
{
	int r,hs,i;
	
	
	printf("Enter number of request: ");
	scanf("%d",&r);
	int request[r];
	
	printf("Enter request: ");
	for(i=0;i<r;i++)
	{
		scanf("%d",&request[i]);
	}
	
	printf("Enter head start: ");
	scanf("%d",&hs);
	while(1)
	{
		printf("\n1.FCFS\n");
		printf("2.SCAN\n");
		printf("3.CSCAN\n");
		printf("4.exit\n");
		int ch;
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case(1):
			{
				fcfs(r,request,hs);
				break;
			}
			case(2):
			{
				scan(r,request,hs);
				break;
			}
			case(3):
			{
				cscan(r,request,hs);
				break;
			}
			case(4):
			{
				exit(1);
			}
		}
	}
}
