#include<iostream>
using namespace std;
int main()
{
	int num_int = 435;
	double num_double = 435.10f;
	char str_int[30];
	char str_double[30];
	itoa(num_int,str_int,10);
	gcvt(num_double,8,str_double);
	printf("int ×ª»»³É ×Ö·û´® %s\n",str_int);
	printf("double ×ª»»³É ×Ö·û´® %s\n",str_double);

	system("pause");

}