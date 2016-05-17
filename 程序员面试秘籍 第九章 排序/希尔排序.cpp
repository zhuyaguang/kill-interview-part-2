#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void shell_sort(int a[],int n)
{
	int i,j,h,temp;
	for(h=n/2;h>0;h=h/2)
	{
		for(i=h;i<n;i++)
		{
			temp =a[i];
			for(j=i-h;j>=0&&a[j]>temp;j=j-h)
			{
				a[j+h]=a[j];
			}
			a[j+h]=temp;
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
	shell_sort(a,9);
	print_num(a,9);
	system("pause");
}