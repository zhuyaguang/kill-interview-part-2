#include<iostream>
using namespace std;
int tail_num_0(int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j % 5 == 0)
		{
			count++;
			j=j/5;
		}
	}
	return count;
}
void main()
{
	cout<<tail_num_0(10)<<endl;
	system("pause");
}