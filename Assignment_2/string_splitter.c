#include<stdio.h>
#include<string.h>

int main(){
	
	//Declare necessary variables
        const int str_len = 100;
        char str[str_len];
	
	//Take user input from terminal
        printf("Enter your string: \n");
        fgets(str,str_len,stdin);
		
	//Print a newline for output clarity
	printf("\nThe tokenized string is:\n");

	//Use string library to tokenize the user input
	//for spaces, newlines, and tabs
	char *token = strtok(str, " \n\t");
	
	//Print out the tokens to prove the string was tokenized
	while (token != NULL) {
		printf("%s\n",token);	
		token = strtok(NULL, " ");
	}
	
	return 0;
}
