#include <stdio.h>

#define max_p 10
#define max_r 10

void issafe(int p,int r,int allocation[max_p][max_r],int need[max_p][max_r],int available[max_r])
{
	int work[max_r],finish[max_p]={0};
	int safesequence[max_p];
	int completed=0;
	int i,j;
	for (i=0;i<r;i++)
	{
		work[i]=available[i];	
	}
	while(completed<p)
	{
		int found=0;
		for(i=0;i<p;i++)
		{
			if(!finish[i])
			{
				int c=0;
				for(j=0;j<r;j++)
				{
					if (need[i][j]>work[j])
					{
						break;
					}
					else
					{
						c++;
					}
				}
				if (c==r)
				{
					safesequence[completed]=i;
					completed++;
					finish[i]=1;
					found=1;
					for (j=0;j<r;j++)
					{
						work[j]+=allocation[i][j];
					}
				}
			}
		}
		if (!found)
		{
			printf("It is an unsafe sequence");
			return;
			
		}
	}
	printf("Safe Sequence\n");
	for(i=0;i<p;i++)
	{
		printf("p%d\t",safesequence[i]);
	}
}

int main()
{
	printf("Enter number of resourses: ");
	int r,p;
	scanf("%d",&r);
	printf("Enter number of processes: ");
	scanf("%d",&p);
	int max[max_p][max_r],allocation[max_p][max_r],need[max_p][max_r],available[max_r];
	
	int i,j;
	printf("Enter for max matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}	
	}
	
	printf("Enter for allocation matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&allocation[i][j]);
		}	
	}
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}	
	}
	
	printf("Enter for available vector\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&available[i]);
	}
	
	issafe(p,r,allocation,need,available);
}
