## 排序大总结(C++版)

### 直接插入排序

```C++
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
```

### 选择排序

```c++
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
```

### 冒泡排序

```c++
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
```

### 快速排序

```c++
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
```

```c++
//堆排序
#include<iostream>
using namespace std;

oid HeapAdjust(int *a,int i,int size)  //调整堆 
{
    int lchild=2*i+1;       //i的左孩子节点序号 
    int rchild=2*i+2;     //i的右孩子节点序号 
    int max=i;            //临时变量 
    if(i<=size/2)          //如果i是叶节点就不用进行调整 
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }    
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);    //避免调整之后以max为父节点的子树不是堆 
        }
    }        
}

void BuildHeap(int *a,int size)    //建立堆 
{
    int i;
    for(i=size/2;i>=1;i--)    //非叶节点最大序号值为size/2 
    {
        HeapAdjust(a,i,size);    
    }    
} 

void HeapSort(int *a,int size)    //堆排序 
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        swap(a[1],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面 
          //BuildHeap(a,i-1);        //将余下元素重新建立为大顶堆 
          HeapAdjust(a,1,i-1);      //重新调整堆顶节点成为大顶堆
    }
}

void main()
{
	int a[]={7,3,5,8,9,1,2,4,6};
	print_num(a,9);
	HeapSort(a,8);
	print_num(a,9);
	system("pause");
}
```

### 希尔排序

```c++
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
```