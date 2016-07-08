#include <iostream>
using namespace std;

void calc(int* arr,int n)
{
	int result = 0;
	int a=0,b=0;
	for (int i = 0; i < n; ++i)
	{
		result = result^arr[i];
	}

	while(result)
	{
		if (result & 1 == 0)
		{
			index++;
			result = result>>1;
		}
		else break;
	}

	int cmp = 1<<index;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] & cmp)
		{
			a = a^arr[i];
		}else {
			b = b^arr[i];
		}
	}

	cout<<a<<" "<<b<<endl;
}