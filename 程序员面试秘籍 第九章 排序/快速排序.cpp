#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void quickSort(int *arr,int l,int r)
{
	//此处编写代码实现快速排序
	int i,j,x,temp;
	if(l<r)
	{
		i=l;
		j=r;
		x=arr[(l+r)/2]; 
		//以中间元素为轴 
		while(1)
		{
			while(i<=r&&arr[i]<x)
				i++;
			while(j>=0&&arr[j]>x)
				j--;
			if(i>=j) //相遇则跳出 
				break;
			else
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp; 
				//交换 
			}
		}
		quickSort(arr,l,i-1); //对左半部分进行快排 
		quickSort(arr,j+1,r); //对右半部分进行快排 
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
	quickSort(a,0,8);
	print_num(a,9);
	system("pause");
}
}