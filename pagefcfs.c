#include <stdio.h>



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

void fcfs(int f,int p,int pages[p],int frames[f])
{
	int pagefault=0;
	int rear=0;
	int i,j;
	for (i=0;i<p;i++)
	{
		int found=0;
		int page=pages[i];
		for(j=0;j<f;j++)
		{
			if (page==frames[j])
			{
				found=1;
				printf("%d is already there",page);
				break;
			}
		}
		if (found==0)
		{
			pagefault++;
			frames[rear]=page;
			rear=(rear+1)%f;
			printf("%d is loaded\n",page);
			display(f,frames);
		}
		
	}
	printf("\nNumber of page faults is %d: ",pagefault);
}

int main()
{
	printf("Enter number of pages and frames: ");
	int p,f;
	scanf("%d %d",&p,&f);
	
	int pages[p];
	int frames[f];
	for (int i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	
	printf("Enter page sequence: ");
	for (int i=0;i<p;i++)
	{
		scanf("%d",&pages[i]);
	}
	
	fcfs(f,p,pages,frames);
	
	
}
