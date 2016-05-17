#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void select_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp =a[i];
				a[i]=a[j];
				a[j] =temp;
			}
		}
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
	select_sort(a,9);
	print_num(a,9);
	system("pause");
}