#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//cleaning up the code from excesive printf check statement used 
//pass 1 achieves identifying a character and encrypting only them
//some weird charaters are appearing at the end of the encrypt msg lets try looping over individual caracters and print them istead of puts
//pass 2 weird characters has been taken off by looping over
//encrypting and rotation alogorithm implemented but not effectively
//pass 3 did explicit type casting for lower letter as char arithmatic used to run out of ascii chars and start getting negative values
//caught the corner case for the 'z'
int main(int argc,char *argv[])
{	//checking for valid command line arguments
	if(argc != 2)	
	{
		printf("Expecting an argument and only one!\n");
		return 1;
	}	
	
	if(isalpha(*argv[1]))//we want an integer value not an letter and for some reason isdigit() and negative values dont respond well
	{
		printf("Expeting an integer value\n");
		return 2;
	}
	//command line arguments are strings so convert them to integer
	int k = atoi(argv[1]);
	char msg[100],crypto[100];
	
	if(k < 0)
	{	//if k is negative 
		printf("Try giving a positive integer, may be you wont screw up this time\n");
		return 3;
	}
	//no matter how big the k is it rotates only %26 times ie ci = (pi + k) %26 
	//for ex k=80 and k=2 are one and the same k=80 we hit z thrice and rotate by 2
	while(k >= 26){ k = k % 26;}

	printf("Enter your message: ");
	fgets(msg, sizeof(msg), stdin);//gets() alternate that gets my job done	
	int sln = strlen(msg);
	//encryption starts here
	for(int i = 0;i < sln;i++)
	{	//check for character and only encrypt the characters
		if(isalpha(msg[i]))
		{	//maintain the case sensitivity
			if(islower(msg[i]))
			{	//rotation algorithm starts here
				int temp = (int)msg[i];//the max entries in ascii table is 127 so if we try direct character arithmatic we run out of characters and start getting negitive values
				temp = temp + k;
				if(temp >= 'z')
				{
					int itp = temp - 'z';
					if(itp == 0) crypto[i] = 'z'; //corner case if the addition points at 'z'. If not handled moves on to previous char of a
					else
					temp = 'a' + (itp-1);
					crypto[i] = temp;
				}
				else
				crypto[i] = temp; //if no rotation is required everyting is in boundaries and well
			}
			else if(isupper(msg[i]))//maintaining case sensitivity
			{
				char temp = msg[i] + k;//we have ample characters fom 'Z' so direct char aithmatic will suffise
				if(temp >= 'Z')
				{
					int itp = temp -'Z';
					if(itp == 0) crypto[i] = 'z'; //coener case 
					else
					temp = 'A' + (itp-1);
					crypto[i] = temp;
				}
				else
				crypto[i] = temp;//no rotation is required
			}
		}
		else
		{
			crypto[i] = msg[i];//if the value is not at all a alphabet then print them simply as it is
		}
	}
	
	for(int j=0;j < sln;j++)//puts used to print some weird characters, mostly eoc/eof something, so use loop
	printf("%c",crypto[j]);
	
	printf("\n");

	return 0;
}
	
