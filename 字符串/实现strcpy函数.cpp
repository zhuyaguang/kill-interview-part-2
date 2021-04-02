#include<iostream>
using namespace std;
char *strcopy(char *str_src,char *str_dest)
{
	if(str_src == NULL||str_dest == NULL)
	{
		return NULL;
	}
	char *strDestCopy = str_dest;

	while( (*str_dest++ = *str_src++) !='\0' );
	return strDestCopy;
}

int lenth(char *str)
{
	int len  = 0;
	while(*str++ != '\0')
	{
		len++;
	}
	return len;
}
int main()
{
	char str[] = "l love code forever";
	int length = lenth(str);
	char str2[30];
	cout<<strcopy(str,str2)<<endl;
	cout<<"³¤¶ÈÎª"<<length<<endl;
	 system("pause");
}