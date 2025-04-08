#include <stdio.h>

void initialise(int f,int frames[f],int recent[f])
{
	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
		recent[i]=-1;
	}
}

int findlow(int f,int recent[f])
{
	int index=0;
	int value=100000;
	for(int i=0;i<f;i++)
	{
		if(recent[i]<value)
		{
			value=recent[i];
			index=i;
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

void lru(int p,int f,int pages[p],int frames[f],int recent[f])
{
	int pagefault=0;
	for (int i=0;i<p;i++)
	{
		int page=pages[i];
		int found=0;
		for(int j=0;j<f;j++)
		{
			if(frames[j]==page)
			{
				found=1;
				recent[j]=i;
				printf(" \n%d is already there",page);
				break;
			}
		}
		if(found==0)
		{
			int index=findlow(f,recent);
			frames[index]=page;
			recent[index]=i;
			pagefault++;
			display(f,frames);
		}
		printf("\n");
		
	}
	printf("\nNumber of pagefaults is: %d",pagefault);
}

int main()
{
	int p,f;
	printf("Enter number of pages and frames: ");
	scanf("%d %d",&p,&f);
	
	int pages[p];
	int frames[f];
	int recent[f];
	
	printf("Enter page sequence: ");
	for(int i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
	
	initialise(f,frames,recent);
	lru(p,f,pages,frames,recent);
}
