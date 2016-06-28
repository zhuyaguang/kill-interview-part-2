#include<iostream>
using namespace std;
int numberOf1(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n = n&(n-1);
	}
	return count;
}
void main()
{
	cout<<numberOf1(5)<<endl;
	system("pause");
}