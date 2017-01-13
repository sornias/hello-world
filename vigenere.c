#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//pass1: Made sure that user inputs only characters and not digits or special characters.
//safe alternate for gets() used is fgets() which gets my job done and also does size checking.

int encrypt(char txt,char key);

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

	char msg[100],crypt_msg[100],j;
	int iarg=0;
	
	printf("Enter your message : ");
	fgets(msg, sizeof(msg), stdin);
	
	int msg_ln = strlen(msg);
	
	for(int i=0; i <= msg_ln; i++)
	{
		if(isalpha(msg[i]))
		{		
			j= encrypt(msg[i],argv[1][iarg]);//call encrypt func with ith char in plain txt and ith char in argv[1] as key
			crypt_msg[i] = (char)j;//j contains the encrypted text
			
			iarg++;//increment to next char in argv[1]
			int slnargv = strlen(argv[1]);
			if(iarg >= slnargv) iarg = 0;//rotate the char in argv[1]

		}
		else
			crypt_msg[i] = msg[i];//if not an alphabet then simply copy it 
	}
	
	int slncrypt = strlen(crypt_msg);//print the encrypted msg
	for(int i = 0; i < slncrypt; i++)
	printf("%c",crypt_msg[i]);
	
	printf("\n");
	
	return 0;
}

int encrypt(char txt,char key)
{
	if(isupper(key)) key = tolower(key);//key is case insensitive only the char's position in alphabet is that matters
	char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//alphabet array
	int add = 0;
	for(int i = 0; i < 26; i++)
	{
		if(key == alpha[i])
		{
			add = i;//each add value is based on the key's position in alphabet array
		}
	}
	
	if(islower(txt))
	{	//rotation algorithm starts here
		int temp = (int)txt;//the max entries in ascii table is 127 so if we try direct character arithmatic we run out of characters and start getting negitive values
		temp = temp + add;//this is encryption of the char
		if(temp >= 'z')
		{
			int itp = temp - 'z';
			if(itp == 0) return 'z'; //corner case if the addition points at 'z'. If not handled moves on to previous char of a
			else
			temp = 'a' + (itp-1);
			return temp;
		}
		else
		return temp; //if no rotation is required everyting is in boundaries and well
	}
	else if(isupper(txt))//maintaining case sensitivity
	{
		char temp = txt + add;//we have ample characters fom 'Z' so direct char aithmatic will suffise
		if(temp >= 'Z')
		{
			int itp = temp -'Z';
			if(itp == 0) return 'z'; //corner case 
			else
			temp = 'A' + (itp-1);
			return (int)temp;
		}
		else
		return (int)temp;//no rotation is required
	}
}
