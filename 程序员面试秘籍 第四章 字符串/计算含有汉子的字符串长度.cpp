#include<iostream>
using namespace std;
int my_strlen(char *str)
{
	char *p=str;
	int len =0;
	while(*p)
	{
		if(*p<0 && (*(p+1)<0||*(p+1)>63))
		{
			len++;
			p=p+2;
		}else
		{
			p++;len++;
		}
	}

	return len;
}
int main()
{
	char mystring[]="wwwÖíÑøµÄ¶àwww";
	cout<<my_strlen(mystring);
	system("pause");
}

