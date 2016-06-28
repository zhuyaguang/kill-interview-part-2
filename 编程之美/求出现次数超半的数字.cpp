#include<iostream>
using namespace std;
int find(int a[],int N)
{
	int dst =0;
	int Ntimes = 0;
	for(int i=0;i<N;i++)
	{
		if(Ntimes == 0)
		{
			dst = a[i];
			Ntimes =1;
		}
		if(dst == a[i])
		{
			Ntimes++;
		}else
		{
			Ntimes--;
		}
	}
	return dst;
}
void main()
{
	int num[]={1,2,3,1,3,4,5,1,1,1,3,1,1,1,1};
	cout<<find(num,15)<<endl;
	system("pause");
}