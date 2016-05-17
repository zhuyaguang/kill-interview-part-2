#include<iostream>
using namespace std;
void loopmove(char *str,int n)
{
	char *head = str;
	int len = strlen(str);
	n = n % len;
	char *temp = NULL;
	temp = (char *)malloc(n);
	int i = 0;
	for(i =0;i<n;i++)
	{
		temp[i] = str[len - n +i];
	}
	for(i=len -1;i>=n ;i--)
	{
		str[i]= str[i-n];
	}
	for(i = 0;i<n;i++)
	{
		str[i] = temp[i];
	}

	free(temp);
}
int main()
{
	char string[]="123456789";
	//int n;
	//cin>>n;
	loopmove(string,2);
	cout<<string<<endl;
	system("pause");
}