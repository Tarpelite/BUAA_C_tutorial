#include <stdio.h>
#include <string.h>
int main(){
	char str1[]="Hello";
	char str2[40];
	char str3[40];

	printf("%d\n",strlen(str1));

	strcpy(str2,"World");

	if (strcmp(str1,str2)==0) printf("the same string!\n"); 
	else printf("something different!\n");

	strcpy(str3,str1);
	strcat(str3," ");
	strcat(str3,str2);

	printf("%s\n",str3);
	return 0;
}
