#include<iostream>
using namespace std;
char * deletestr(char *str,char c)
{
	char *head =NULL;
	char *p = NULL;
	head = p =str;
	while(*p++)
	{
		if(*p != c)
		{
			*str++ = *p;
		}
	}
	*str = '\0';
	return head;
}
int main()
{
	char string[]="zhuysgdlledwffd";
	cout<<deletestr(string,'d');
	system("pause");
}