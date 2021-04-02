#include<iostream>
using namespace std;
char *deleteChar(char *str,int pos ,int len)
{
	char *p = str+pos-1;
	//判断，优化代码 加分点
	//____
	int tt= strlen(str);
	if(pos<1 ||(p-str)>tt)
	{
		return str;
	}

	if((p+len-str)>tt)
	{
		*p='\0';
		return str;
	}
	//____
	while(*p&&*p++)
	{
		*p = *(p+len);
		p++;
	}
	*p='\0';

	return str;
}
int main()
{
	char string[] = "dhusfff";
	cout<<deleteChar(string,2,2);
	system("pause");
}