#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void insert_sort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp =a[i];
		for(j = i-1;j>=0&&temp<a[j];j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] =temp;
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
	insert_sort(a,9);
	print_num(a,9);
	system("pause");
}