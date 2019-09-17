#include<stdio.h>
#include<string.h>

int main(){

	const int str_len = 60;
	char str[str_len];
	char tok[str_len];

	printf("String Entry: \n");
	fgets(str,str_len,stdin);

	printf("Token Entry: \n");
	fgets(tok,str_len,stdin);

	if (strstr(str,tok) != NULL) {
		printf("FOUND\n");
	}
	else {
		printf("NOT FOUND\n");
	}

return 0;
}
