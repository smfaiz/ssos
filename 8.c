#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int alloc[10][10],max[10][10],need[10][10];
int avail[10],work[10],p,r,j,i,k,v=0;
bool finish[10];
bool check(int i)
{	for(j=0;j<r;j++)
	{	if(need[i][j]>work[j])
			return false;
	}
	return true;
}

int main()
{	printf("\nEnter the number of process and resources \n");
	scanf("%d%d",&p,&r);
	int seq[p];
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	printf("\nEnter the maximum values \n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	printf("\nEnter the available matrix\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
		work[i]=avail[i];
	}
	for(i=0;i<p;i++)
	{
		finish[i]=false;
	}
	while(v<p)
	{
		bool allocated=false;
		for(i=0;i<p;i++)
		{	if(!finish[i] && check(i))
			{
				for(k=0;k<r;k++)
					work[k]=work[k]+alloc[i][k];
				allocated=finish[i]=true;
				seq[v]=i;
				v++;
			}
		}
		if(!allocated)
			break;
	}
	for(i=0;i<p;i++)
	{	if(finish[i]==false)
		{
			printf("\nAll process not safely allocated \n");
			exit(0);
		}
	}
	printf("\nProcess safely allocated with the sequences \n");
	for(i=0;i<v;i++)
		printf("%d\t",seq[i]);
}
