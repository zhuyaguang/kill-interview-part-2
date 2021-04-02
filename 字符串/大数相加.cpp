#include<iostream>
#include<string>
using namespace std;
char *addBigInt(char *str1,char *str2)
{
	int i = strlen(str1)-1;
	int j = strlen(str2)-1;
	int k = i+1>j+1?i+1:j+1;
	
	char *ret = (char *)malloc(k+1);
	ret[k]='\0';
	int c = 0;
	k = strlen(ret)-1;
	while(i>=0 && j>=0)
	{
		ret[k]=(str1[i]-'0'+str2[j]-'0'+c)%10+'0';
		c = (str1[i]-'0'+str2[j]-'0')/10;
		k--;
		i--;
		j--;
	}
	while(i>=0)
	{
		ret[k]=(str1[i]-'0'+c)%10+'0';
		c = (str1[i]-'0'+c)/10;
		k--;
		i--;
	}
	while(j>=0)
	{
		ret[k]=(str2[j]-'0'+c)%10+'0';
		c = (str2[j]-'0')/10;
		k--;
		j--;
	}
	ret[0] = c+'0';
	if(ret[0]!='0')
	{
		return ret;
	}else
	{
		return ret+1;
	}
}
int main()
{
	char num1[] = "12345678956";
	char num2[] = "1568913596";
	char *num3 = addBigInt(num1,num2);
	cout<<num1<<"+"<<num2<<"="<<num3;

	system("pause");
}