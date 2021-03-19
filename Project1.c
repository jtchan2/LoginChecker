#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * A password strength meter and a default password generator, 
 * as defined in the CS221 course website for Project 1.
 *
 */
bool isStrongPassword(const char* username, const char* password) {
	bool continuous=true;
	int number=0;
	int upper=0;
	int lower=0;
	int holder=0;
	int sStri=4;
	int ssCounter=0;
	//printf("%c\n", username[1]);
	//printf("%s\n", password);
	int length= strlen(password);
	for(int i=0; i<length; i++){
		char temp= password[i];
		//Checks if char is upper case
		if(temp>=65 && temp<=90){
			printf("it is a upper case\n");
			printf("%c\n", password[i]);
			printf("%d\n", temp);
			upper++;
			if(holder==0){
				holder=i;
			}
		}
		//Checks if char is lower case
		if(temp<=122&&temp>=97){
			printf("It is an lower case\n");
			printf("%c\n", password[i]);
			printf("%d\n", temp);
			lower++;
			if(holder==0){
				holder=i;
			}
		}
		//check if char is a number
		if(temp<=57 &&temp>=48){
			printf("It is a digit\n");
			printf("%c\n", password[i]);
			printf("%d\n", temp);
			number++;
		}
	}
	//this checks if substring is longerthan 4, holder is the start of string in password
	//printf("%d this is holder\n",holder);
	char runner= password[holder];
	while(continuous==true){
		if(runner>=65 &&runner<=90 && continuous==true){
			ssCounter++;
		}
		if(runner>=97 && runner<=122&& continuous==true){
			ssCounter++;
		}
		if(runner<=57 && runner>=48){
			continuous=false;
		}
		runner= password[holder++];
	}
	//printf("string length is %d\n", ssCounter);
	//Implement username check in passsword
	if(length>=8 && number>=1 && upper>=1 && lower>=1 && ssCounter>=4){
	    printf("Password is Strong\n");
		printf("%d\n", holder);
	    return true;
	}else{
		printf("Password is weak\n");
		return false;
	}
	
	
	printf("%d\n", length);
	return false;
}

/** 
 * Example: isStrongDefaultPassword("vahab", "Taher3h") returns false
 */
bool isStrongDefaultPassword(const char* username, const char* password) {
	//TODO: your code goes here.	
	return false;
}

/** 
 * This function may *not* call isStrongPassword(). 
 * This function must call isStrongDefaultPassword().
 */
void generateDefaultPassword(char * default_password, const char * username) {
	//TODO: your code goes here.
	int len= (rand()%(15-8+1))+8;
	int cap=0;
	int low=0;
	int num=0;
	char* ch="";
	// Three r variables for generating random char
	int rUp= (rand()%(90-65+1))+65;
	int rLow= (rand()%(122-97+1))+97;
	int rInt=(rand()%(57-48+1))+48;
	if(cap==0){
		// add an uper case letter
	}
	if(low==0){
		//add lower case letter
	}
	if(num==0){
		//add a number
	}
	


}

int main(void) 
{
	char user[]="";
	char pass[]="";
	char dpass[15]="";
	//creates array to save password and user when inputed
	printf("Enter User: \n");
	scanf("%s", user);
	printf("Enter Password: \n");
	scanf("%s", pass);
	srand(time(0));
	isStrongPassword(user,pass);

	return 0;
}