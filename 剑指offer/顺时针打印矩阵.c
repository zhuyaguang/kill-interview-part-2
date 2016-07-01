#include<iostream>
using namespace std;

int printMatrix(int** numbers,int columns,int rows){
	//定义四个关键变量来定义打印的范围
	
	int left = 0,right = columns -1,top = 0,button = rows -1;

	while(left <= right && top <= button)
	{
		//左到右
		for (int i = left; i <= right; ++i)
		{
			cout<<numbers[top][i];
		}
		//上到下
		for (int i = top+1; i <= button; ++i)
		{
			cout<<numbers[right][i];	
		}
		//右到左
		if (top != button)
		
		for (int i = right-1; i >= left; --i)
		{
			cout<<numbers[button][i];
		}
		//下到上
		if (left != right)
		for (int i = button-1; i >= top+1; --i)
		{
			cout<<numbers[left][i];
		}

		left++;right--;top++;button--;
	} 
}