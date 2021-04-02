#include<iostream>
using namespace std;
void cal(char *str,int *max0,int *max1)
{
	int temp0=0;
	int temp1=0;
	while(*str)
	{
		if(*str == '0')		
		{
			(*max0)++;
			if(*(++str)=='1')
			{
				if(*max0>temp0)
				{
					temp0 = *max0;
				}
				*max0 =0;
			}
		}else if(*str == '1')
		{
			(*max1)++;
			if(*(++str) =='0')
			{
				if(*max1>temp1)
				{
					temp1=*max1;
				}
				*max1=0;
			}
		}
	}
	*max0 = temp0;
	*max1 = temp1;
}
int main()
{
	char numstr[]="1101010101010011111000011111000";
	int max0=0;
	int max1=0;
	cal(numstr,&max0,&max1);
	cout<<max0<<max1;
	system("pause");
}

