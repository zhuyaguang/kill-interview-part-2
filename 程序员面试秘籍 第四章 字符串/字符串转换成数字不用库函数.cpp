#include<iostream>
using namespace std;

int str2int(const char *str)
{
	const char *ptr = str;
	int temp = 0;
	if(*str == '+'|| *str == '-')
	{
		str++;
	}
	while(*str != 0)
	{
		if(*str < '0' || *str > '9')
		{
			break;
		}

		temp = temp * 10 + (*str - '0');
		str++;
	}

	if(*ptr == '-')
	{
		temp = -temp;
	}
	return temp;
}
int main()
{
	while(1)
	{
		int n = 0;
	char s[20];
	cin>>s;
	n = str2int(s);
	cout<<n<<endl;
	}
	
	 system("pause");
}