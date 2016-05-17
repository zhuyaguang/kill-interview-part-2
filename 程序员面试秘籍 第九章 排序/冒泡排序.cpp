#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void bubble_sort(int a[],int n)
{
	int i,j,temp,exchange = 0;
	for(i = 0;i<n;i++)
	{
		 exchange = 0;
		for(j = n-1;j>=i;j--)
		{   
			if(a[j]<a[j-1])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				exchange =1;
			}
		}

		if(exchange !=1)
			return ;
	}
}
void print_num(int a[],int n)
{
	for(int i =0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	int a[]={7,3,5,8,9,1,2,4,6};
	print_num(a,9);
	bubble_sort(a,9);
	print_num(a,9);
	system("pause");
}