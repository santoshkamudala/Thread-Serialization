#include "ptr.h"
int main()
{
	int r,c,i,j,**p,Sum,sum;
	printf("enter rows and coloumns\n");
	scanf("%d%d",&r,&c);
	p=(int **)malloc(sizeof(int *)*r);
	printf("enter elements of array\n");
	for(i=0;i<r;i++)
	{
		 p[i]=(int *)malloc(sizeof(int)*c);
		for(j=0;j<c;j++)
		{
			
			scanf("%d",&p[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",p[i][j]);
			printf("\n");
	}
	for(i=0;i < r;i++)
	{
		for(j=0;j < c;j++)
		{
			if(i==j)
			{
				Sum+=p[i][j];
			}
		}
	}
	printf("\nThe sum of diagonal elements is %d",Sum);
        for(i=0;i < r;i++)
	{
		for(j=0;j < c;j++)
		{
			if(i+j==r || i+j==0)
			{
				sum+=p[i][j];
			}
		}
	}
	printf("\nThe sum of cdiagonal elements is %d",sum);
	for(i=0;i<r;i++)
	{
		free(p[i]);
		p[i]=NULL;
	}
	free(p);
	p=NULL;
       return 0;
}


