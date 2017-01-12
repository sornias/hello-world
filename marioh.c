#include<stdio.h>

int main()
{
	int i,j,n,bs,hash,k;
	
	printf("Enter the height of the steps(1-25) : ");
	scanf("%d",&n);
	bs = n-1;
	hash = 2;
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=bs; j++)
		{
			printf(" ");
		}
		for(k=1; k<=hash; k++)
		{
			printf("#");
		}
		printf(" ");
		for(k=1; k<=hash; k++)
		{
			printf("#");
		}
		printf("\n");	
		bs--;
		hash++;
	}
	return 0;
}