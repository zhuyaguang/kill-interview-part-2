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
void bubbleSort(int arr[], int n)
{
	for(int i = 0;i < n;i++){  
		//比较两个相邻的元素   
		for(int j = 0;j < n-i-1;j++){  
            if(arr[j] > arr[j+1]){  
                int t = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = t;  
            }  
        }  
    }       
}
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

//堆排序
int heapSize =0;
int Left(int index){return index*2+1;}
int Right(int index){return index*2+2;}
void swap(int *a,int *b){int temp = *a;*a = *b;*b = temp;}
//调整堆
void maxHeapify(int array1[],int index)
{
	int largest = 0;
	int left = Left(index);
	int right = Right(index);
	if((left <= heapSize)&&(array1[left]>array1[index]))
	{
		largest = left;
	}else
	{
		largest = index;
	}

	if((right <= heapSize)&&(array1[right]>array1[largest]))
	{
		largest = right;
	}

	if(largest != index)
	{
		swap(&array1[index],&array1[largest]);
		maxHeapify(array1,largest);
	}
}
//建堆
void buildMaxHeap(int array1[],int length)
{
	int i;
	heapSize = length;
	for(i=length/2;i>=0;i--)
	{
		maxHeapify(array1,i);
	}
}
//排序
void heap_sort(int array1[],int length)
{
	int i;
	buildMaxHeap(array1,length-1);
	for(i=length-1;i>=1;i--)
	{
		swap(&array1[0],&array1[i]);
		heapSize--;
		maxHeapify(array1,0);
	}
}

void main()
{
	int a[]={7,3,5,8,9,1,2,4,6};
	
	print_num(a,9);
	//insert_sort(a,9);
	//shell_sort(a,9);
	//select_sort(a,9);
	//bubble_sort(a,9);
	//bubbleSort(a,9);
	//quickSort(a,0,8);
	//HeapSort(a,9);
	//heap_sort(a,9);

	print_num(a,5);
	system("pause");
}