#include<iostream>
using namespace std;
int subsum(int *num,int n)
{
	
	int sum=0;
	int temp = 0;
	for(int i = 0;i<n;i++)
	{
		if(temp <=0)
		{
			temp = num[i];
		}else
		{
			temp+=num[i];
		}

		if(sum<temp)
		{
			sum = temp;

		}
	}

	return sum;
}
int main()
{
	int a[]={1,2,3,4,5,667,76};
	int n = sizeof(a)/sizeof(a[0]);
	int b = subsum(a,n);
	cout<<b;
	system("pause");
}

