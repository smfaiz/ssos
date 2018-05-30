#include<stdio.h>
typedef struct J
{	int num,arrival,finish,burst,tat,wt;
}Job;

void scheduler(Job job[],int n,int q,int c)
{	int bursts[100];
	for(int i=0;i<n;i++)
		bursts[i]=job[i].burst;
	int t=0,done=0,curr,diff;
	float tat_sum=0,wt_sum=0;
	if(c==0)
		curr=-1;
	else
		curr=0;
	while(done<n)
	{
		if(c==1)
		{	for(int x=0;x<n;x++)
			{
				if(job[curr].burst==0)
					curr=x;
				if(job[x].burst<job[curr].burst)
					if(job[x].burst>0 && job[x].arrival<=t)
						curr=x;
			}
			diff=1;
		}
		else
		{
			while(1)
			{	curr=(curr+1)%n;
				if(job[curr].burst!=0)
					break;
			}
			diff=(q<=job[curr].burst)?q:job[curr].burst;
		}
		job[curr].burst-=diff;
			t+=diff;
		if(job[curr].burst==0)
		{	done++;
			job[curr].finish=t;
		}
	}
	if(c==1)
		printf("\nSJF schedule details are : ");
		
	else
		printf("\nThe RR schedule details are : ");
	for(int i=0;i<n;i++)
		job[i].burst=bursts[i];
	printf("\nJob\tTAT\nWT\n");
	for(int i=0;i<n;i++)
	{
		job[i].tat=job[i].finish-job[i].arrival*c;
		
		job[i].wt=job[i].tat-job[i].burst;
		
		printf("%d\t%d\n",i+1,job[i].tat,job[i].wt);
		
		tat_sum+=job[i].tat;
		
		wt_sum+=job[i].wt;
	}
	printf("\nAvg Turn Around Time =%f\nAvg Waiting Time=%f\n",tat_sum/n,wt_sum/n);
}

int main()
{
	Job job[100];
	int n,q,c;
	printf("\nEnter the number of jobs : ");
	scanf("%d",&n);
	printf("\nEnter the arrival and burst time : \n");
	for(int i=0;i<n;i++)
	{
		printf("J%d:",i+1);
		scanf("%d%d",&job[i].arrival,&job[i].burst);
	}
	printf("\n1.Round Robin\n2.SJF\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:	printf("\nEnter quantum for RR\n");
			scanf("%d",&q);
			scheduler(job,n,q,0);
			break;
		case 2:	scheduler(job,n,q,1);
	}
} 
