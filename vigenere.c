#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//pass1: Made sure that user inputs only characters and not digits or special characters.
//safe alternate for gets() used is fgets() which gets my job done and also does size checking.

int noofalphas(int j);

int main(int argc,char *argv[])
{	
	//checking for valid command line arguments
	if(argc != 2)	
	{
		printf("Expecting an argument and only one!\n");
		return 1;
	}	
	int n = strlen(argv[1]);
	for(int i=0;i<n;i++)//itterate over individual char of argv[1] and stop at the first occurance of non alphabet.
	{
		if(!isalpha(argv[1][i]))//make sure user has given string of chars as keyword. isdigit() fails to check for special char.
		{			
			printf("Only character based keywords are accepted\n");
			return 2;
		}
	}	

	char msg[100],crypt_msg[100];
	static int j=0;
	printf("Enter your message : ");
	fgets(msg, sizeof(msg), stdin);
	int msg_ln = strlen(msg);
	printf("msg length = %d\n",msg_ln);
	for(int i=0; i<msg_ln; i++)
	{
		if(isalpha(msg[i]))
		{		
			j=noofalphas(j);
			printf("j=%d\n",j);

		}
		else
			crypt_msg[i] = msg[i];
	}
	return 0;
}

int noofalphas(int j)
{
	return j++;
}
