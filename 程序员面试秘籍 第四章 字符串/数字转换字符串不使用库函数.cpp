#include<iostream>
using namespace std;
void int2str(int n,char *str)
{
	char buf[10] = " ";
	int i = 0;
	int len = 0;
	int temp = n < 0 ? -n :n;
	if(str == NULL)
	{
		return;
	}
	while(temp)
	{
		buf[i++]=(temp % 10)+ '0';
		temp = temp / 10;
	}
	len = n < 0 ? ++i : i;
	str[i] = 0;
	while(1)
	{
		i--;
		if(buf[len-i-1] == 0)
		{
			break;
		}
		str[i] = buf[len-i-1];
		
	}
	if(i == 0)
		{
			str[i] = '-';
		}
}
int main()
{
	int NUM;
	char p[10];
	cout<<"please input an integer:";
	cin>>NUM;
	cout<<"output:";
	int2str(NUM,p);
	cout<<p<<endl;
	system("pause");

}