## 剑指offer汇总

### 1.[二维数组中的查找](http://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 我的暴力方法，双重循环查找

```c++
#include<iostream>
using namespace std;

int main()
{
	
	int num[4][4] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int tar;
	cin>>tar;
	int flag = 0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(num[i][j]==tar)
			{
				flag = 1;
				break;
			}
		}
		cout<<flag;
		system("pause");
 }
```

### 2.[替换空格](http://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 同样是我的方法，利用了sstream

```c++
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<string> a;
    string s;
    getline(cin,s);
    
    for (int i = 0; i<s.length(); i++) {
        stringstream stream;
        stream << s[i];
        string tep = stream.str();
        a.push_back(tep);
    }
    
    
    int len = int(a.size()-1);
    
    for (int  i = 0; i<len; i++) {
        if(a[i] == " ")
        {
            a[i] = "%20";
        }
    }
    
     for (int  i = 0; i<=len; i++) {
         cout<<a[i];
     }
    
    return 0;
}
```

### 3.[从尾到头打印链表](http://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 4.[重建二叉树](http://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 5.[用两个栈实现队列](http://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 6.[旋转数组的最小数字](http://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 7.[斐波那契数列](http://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
//我的解法

long long Fibonacci(int n){
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;

	return Fibonacci(n-1)+Fibonacci(n-2);

}


//大神的解法 C++动态规划

 int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n--) {
            g += f;
            f = g - f;
        }
        return f;
    }

int main()
{
	
	
	cout<<Fibonacci(4);
	
	system("pause");
}
```

### 8.[跳台阶](http://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int jumpFloor(int number) {
        if (number == 1 || number == 2)
	{
		return number;
	}else {
		return jumpFloor(number-1)+jumpFloor(number-2);
	}
    }
```

### 9.[变态跳台阶](http://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int jumpFloorII(int number) {
        if(number==1) return 1;
        else if(number==2) return 2;
        else
        {
            return 2*jumpFloorII(number-1);
        }
 
    }
```

### 10.[矩形覆盖](http://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
>

```c++
int RectCover(int target) {
      if(target  <= 1){
            return 1;
        }
        if(target*2 == 2){
            return 1;
        }else if(target*2 == 4){
            return 2;
        }else{
            return RectCover((target-1))+RectCover(target-2);
        }
    }
```

### 11.[二进制中1的个数](http://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int  NumberOf1(int n) {
         int count =0;
         while(n)
             {
             count++;
             n=n&(n-1);
             
         }
         return count;
     }
```

### 12.[数值的整数次方](http://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
Power(double base, int exponent) {
        double r=1;
        if (exponent==0){return 1;}
        if(exponent<0)
        {
            base=1/base;
            exponent=-1*exponent;
        }
        while(exponent>0)
        {
            r = r*base;
            exponent--;
        }
        return r;
     
    }
```

### 13.[调整数组顺序使奇数位于偶数前面](http://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
>

```c++
#include<iostream>
using namespace std;

int main()
{
	
	int num[8] = {1,2,8,9,4,7,11,6};
	int len = sizeof(num)/sizeof(num[0]);
	int *begin = num;
	int *end = num+len-1;

	while(begin < end)
	{
		while(begin < end && *begin % 2 != 0)
			begin++;
		while(begin < end && *end %2 ==0)
			end--;
		if(begin < end)
		{
			int temp = *begin;
			*begin = *end;
			*end = temp;
		}
	}
	for(int i =0 ;i< len ;i++)
	{
	cout<<num[i];
	}
		
		system("pause");
 }
```

### 14.[链表中倒数第k个结点](http://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入一个链表，输出该链表中倒数第k个结点。
>


> 第一个指针先走k步,第二个指针开始走，当第一个指针走到尽头的时候，第二个指针就是倒数第K个结点

```c++
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }


ListNode *FindK(ListNode *head,unsigned int k)
{
	if (head == NULL || k == 0)
	{
		return NULL;
	}

	ListNode *Node = head;
	ListNode *pHeadNode = head;
	ListNode *pFollowNode = head;
	int len ;
	while(pNode)
	{
		len++;
		pNode->next;
	}
	if (k>len)
	{
		return NULL;
	}

	for (int i = 0; i < k-1; ++i)
	{
		if (pHeadNode->next != NULL)
		{
			pHeadNode = pHeadNode->next;
		}
		
	}

	while(pHeadNode->next)
	{
		pHeadNode = pHeadNode->next;
		pFollowNode = pFollowNode->next;
	}

	return pFollowNode;
}
```

### 15.[反转链表](http://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
//头插法
//
struct ListNode{
	int value;
	ListNode *next;
}

ListNode *ReverseList(ListNode *head)
{
	ListNode *newHead = head;
	head = head ->next;

	newHead ->next = NULL;

	while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;

}
```

### 16.[合并两个排序的链表](http://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 递归什么的很难想到，也很难理解

```C++
struct ListNode{
	int value;
	ListNode *next;
}

ListNode *merge(ListNode *head1,ListNode *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}

	if (head2 == NULL)
	{
		return head1;
	}
	ListNode *newHead == NULL;

	if (head1 -> value < head2 ->value)
	{
		newHead = head1;

		newHead ->next = merge(head1->next,head2);
	}else {
		newHead = head2;
		newHead ->next = merge(head2->next,head1);
	}

	return newHead;
}
```

### 17.[树的子结构](http://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

