#include<iostream>
using namespace std;
int main()
{
	int num_int;
	double num_double;
	char str_int[30]="4268";
	char str_double[30]="4268.31";
	 num_int = atoi(str_int);
	 num_double = atof(str_double);
	 cout<<num_int<<endl;
	 cout<<num_double<<endl;
	 system("pause");
}