#include<stdio.h>
//for handling string functions
#include<string.h>
//for handling character converstion
#include<ctype.h>


//main begins here
int main(void)
{
	//declaring of all the variables
	char name[50],initials[10],s;
	
	//reading the name 
	printf("enter your name: ");
	gets(name);
	//puts(name);
	//how will you get string lenth before reading the string
	int n=strlen(name),j=0;
	
	//first character to upper
	s = toupper(name[0]);
	initials[j] = s;
	j++;
	
	//to get individual characters
	for (int i=0;i<n;i++)
	{
		//check if we hit a space which denotes the end of a part of name
		if (name[i] == ' ' )
		{
			
			//when we hit the space increment the counter to point to the next character
			i += 1;
			//convert the character into upper and save it in the s
			s=toupper(name[i]);
			//copy the s into an array
			initials[j] = s;
			j++;
		}
	}
	//printf("check");
	//print the initials
	printf("Iniatials : ");
	for(int i=0;i<strlen(initials);i++)
	printf("%c",initials[i]);
	//print a blank line
	printf("\n");
	return 0;
}
