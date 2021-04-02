#include<iostream>
#include<assert.h>
using namespace std;
int length(char *str)
{
	int len = 0;
	while(*str++ != '\0')
	{
		len++;
	}
	return len;
}
int length2(char *str)
{
	char *temp = str;
	while(*str++ != '\0');
	return (str-temp-1);

}
int main()
{
	char strSrc[] = "hello world!";
	
	cout<<length(strSrc)<<endl;
	cout<<length2(strSrc)<<endl;
	system("pause");
}