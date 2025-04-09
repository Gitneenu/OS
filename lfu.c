#include <stdio.h>

void initialise(int f,int frames[f],int count[f],int time[f])
{
	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
		count[i]=0;
		time[i]=0;
	}
}

int leastcount(int f,int count[f],int time[f])
{
	int index=0;
	int value=10000;
	int timey=10000;
	for(int i=0;i<f;i++)
	{
		if (count[i]<value)
		{
			index=i;
			value=count[i];
			timey=time[i];
		}
		else if(count[i]==value)
		{
			if (time[i]<timey)
			{
				index=i;
			}
		}
	}
	return index;
}

void display(int f,int frames[f])
{
	for(int i=0;i<f;i++)
	{
		if (frames[i]==-1)
		{
			printf("-");
		}
		else
		{
			printf("%d",frames[i]);
		}
	}
}

void lfu(int p,int f,int pages[p],int frames[f],int count[f],int time[f])
{
	int pagefault=0;
	int current=0;
	for(int i=0;i<p;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if(frames[j]==page)
			{
				found=1;
				count[j]++;
				printf("\n%d already found ",pages[i]);
				break;
			}
		}
		if(found==0)
		{
			int index=leastcount(f,count,time);
			frames[index]=page;
			count[index]=1;
			time[index]=current;
			current++;
			printf("\n");
			pagefault++;
			display(f,frames);
		}
	}
	printf("\nNumber of page faults is: %d",pagefault);
}

int main()
{
	int p,f;
	printf("Enter number of pages and frames: ");
	scanf("%d %d",&p,&f);
	
	int pages[p];
	int frames[f];
	int count[f];
	int time[f];
	
	printf("Enter page sequence: ");
	for(int i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);	
	}
	
	initialise(f,frames,count,time);
	lfu(p,f,pages,frames,count,time);
}
