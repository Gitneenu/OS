#include <stdio.h>
#include <stdlib.h>

void initialise(int f,int frames[f])
{
	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
	}
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
	printf("\n");
}

void fifo(int p,int f,int pages[p],int frames[f])
{
	int pf=0;
	initialise(f,frames);
	int in=0;
	for(int i=0;i<p;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if (page==frames[j])
			{
				found=1;
				printf("%d already found\n",page);
				break;
			}
		}
		if (found==0)
		{
			frames[in]=page;
			in=(in+1)%f;
			pf++;
			display(f,frames);
		}
	}
	printf("\nNumber of page fault is %d\n",pf);
	
}

int rece(int f,int frames[f],int recent[f])
{
	int value=10000;
	int index=-1;
	for(int i=0;i<f;i++)
	{
		if (recent[i]<value)
		{
			value=recent[i];
			index=i;
		}
	}
	return index;
}

void lru(int p,int f,int pages[p],int frames[f])
{
	initialise(f,frames);
	int pf=0;
	int recent[f];
	for(int i=0;i<f;i++)
	{
		recent[i]=-1;
	}
	for(int i=0;i<p;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if(page==frames[j])
			{
				printf("%d already found",page);
				found=1;
				recent[j]=i;
				break;
			}
		}
		if (found==0)
		{
			int index=rece(f,frames,recent);
			frames[index]=page;
			recent[index]=i;
			pf++;
			display(f,frames);
		}	
	}
	printf("\nNumber of page faullt is %d\n",pf);
}

int freq(int f,int frames[f],int count[f],int time[f])
{
	int value=10000;
	int index=-1;
	for(int i=0;i<f;i++)
	{
		if (count[i]<value)
		{
			value=count[i];
			index=i;
		}
		else if(count[i]==value && time[i]<time[index])
		{
			index=i;
		}
	}
	return index;
}

void lfu(int p,int f,int pages[p],int frames[f])
{
	initialise(f,frames);
	int lf=0;
	int current=0;
	int count[f],time[f];
	for(int i=0;i<f;i++)
	{
		count[i]=0;
		time[i]=-1;
	}
	for(int i=0;i<p;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if(frames[j]==page)
			{
				printf("%d already found",page);
				found=1;
				//time[j]=current;
				//current++;
				count[j]++;
				break;
			}
		}
		if (found==0)
		{
			int index=freq(f,frames,count,time);
			frames[index]=page;
			count[index]=1;
			time[index]=current;
			current++;
			lf++;
			display(f,frames);
		}
	}
	printf("\nNumber of page fault is %d: \n",lf);
	
}

int main()
{
	int p,f;
	printf("Enter number of pages and frames: ");
	scanf("%d %d",&p,&f);
	
	int pages[p];
	int frames[f];
	for(int i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
	
	while(1)
	{
		printf("\n1.FIFO\n");
		printf("2.LRU\n");
		printf("3.LFU\n");
		printf("4.exit\n");
		int ch;
		printf("Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case(1):
			{
				fifo(p,f,pages,frames);
				break;
			}
			case(2):
			{
				lru(p,f,pages,frames);
				break;
			}
			case(3):
			{
				lfu(p,f,pages,frames);
				break;
			}
			case(4):
			{
				exit(0);
			}
		}
	}
}
