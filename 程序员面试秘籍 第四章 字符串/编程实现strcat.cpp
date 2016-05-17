#include<iostream>
using namespace std;
char *mystrcat(char *src,char*dest)
{
	char *ret = dest;
	while(*dest++);
	dest=dest-1;
	while(*dest++=*src++);
	return ret;
}
int main()
{
	char str1[100]="sssdd";
	char str2[]="deggg";
	char *dest= NULL;
	dest =(char *)malloc(256);
	*dest ='\0';
	dest = mystrcat(str1,str2);

	cout<<dest;

	//char str3[]="ssdjfei9enfffdkk";
	//char *pp =str3;
	//while(*pp++);
	//cout<<*(pp-1)<<endl;
	//cout<<*(pp-2)<<endl;
	system("pause");
}

