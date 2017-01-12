#include<stdio.h>
#include<stdlib.h>

int main()
{
	float change;
	int noOfCoins=0,temp;
	//input sanitization
	printf("Hi! how much change do we owe you? : ");
	scanf("%f",&change);
	if(change >= 10)
	{
		if(change == 10)
		{
			printf("did you even buy anything?\n");
			exit(0);
		}
		if(change > 10)
		{
			printf("whoa! that's a huge amount. We'll be out of change!! \n$10 bill is the highest we accept.\n");
			exit(0);
		}
	}
	else if(change < 10){
	//rendring change
	//printf("change=%f\n", change);
	temp = change*100;
	//printf("temp = %d\n",temp);
	while (temp != 0)
	{
		if(temp >= 25)
		{
			temp = temp-25;
			noOfCoins++;
			//printf("temp = %d\n",temp);
		}
		else
		if(temp >= 10)
		{
			temp = temp-10;
			noOfCoins++;
			//printf("temp = %d\n",temp);
		}
		else
		if(temp >= 5)
		{
			temp = temp-5;
			noOfCoins++;
			//printf("temp = %d\n",temp);
		}
		else
		//printf("temp = %d\n",temp);
		if(temp >= 1)
		{
			temp = temp-1;
			noOfCoins++;
		}
		
	};
		printf("number of coins in your hand must be: %d\n", noOfCoins);
	}
	return 0;

}