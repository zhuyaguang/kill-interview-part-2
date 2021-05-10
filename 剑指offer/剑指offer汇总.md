## 剑指offer汇总

> 4,6.10-1,10-2,10-3,10-4,12

### 1.[剑指 Offer 04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

> 同[240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)相同

#### 解法一：暴力

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

#### 解法二:从左下角或者右上角查找

```Go
func findNumberIn2DArray(matrix [][]int, target int) bool {
    m:=len(matrix)
    if m==0{
        return false
    }
    n:=len(matrix[0])
    i:=m-1
    j:=0
    for i>=0&&j<n{
        if matrix[i][j]>target{
            i--
        }else if matrix[i][j]<target{
            j++
        }else if matrix[i][j]==target{
            return true
        }
    }
    return false
}

```



### 2.[剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)

Go版本

```go
func replaceSpace(s string) string {
        return strings.ReplaceAll(s," ","%20")
}

// 使用 strings.Builder
func replaceSpace(s string) string {
	var res strings.Builder
    for i:=range s{
    	if s[i]==' '{
			res.WriteString("%20")
		}else {
			res.WriteByte(s[i])
		}
	}
	return res.String()
}
```

C++版本

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

### 3.[从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

```go
func reversePrint(head *ListNode) []int {
  arr:=[]int{}
  cur:=head
  for cur !=nil{
  	arr =append(arr,cur.Val)
  	cur=cur.Next
  }
  return reverseArr(arr)
}

func reverseArr(arr []int)[]int{

	for i,j:=0,len(arr)-1;i<=j;i,j=i+1,j-1{
		arr[i],arr[j]=arr[j],arr[i]
	}
	return arr
}
```



### 4.[重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)

> 同[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)相同



### 5.[用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

```go
type CQueue struct {
  arr []int

}


func Constructor() CQueue {
return CQueue{
     }
}


func (this *CQueue) AppendTail(value int)  {
        this.arr=append(this.arr,value)
}


func (this *CQueue) DeleteHead() int {
    if len(this.arr)==0{
        return -1
    }
        resu:=this.arr[0]
        this.arr=this.arr[1:]
        return resu
}
```



### 6.[旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

> 二分查找

### 7.[斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)

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

### 8.[跳台阶](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)

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

Go版本dp解法

```go
func numWays(n int) int {

    if n==0{
        return 1
    }
    if n==1{
        return 1
    }

    if n==2{
        return 2
    }

	dp:=make([]int,n+1)
	dp[0]=0
	dp[1]=1
	dp[2]=2
	for i:=3;i<=n;i++{
		dp[i]=dp[i-1]+dp[i-2]
        dp[i]=dp[i]%1000000007
	}
	return dp[n]
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

### 10-1.[剑指 Offer 12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)

### 10-2.[剑指 Offer 13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)

### 10-3.[剑指 Offer 14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)

### 10-4.[剑指 Offer 14- II. 剪绳子 II](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/)



### 11.[二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)

Go版本

```go
func hammingWeight(num uint32) int {
    if num==0{
        return 0
    }
    count:=0

    for ;num>0;num&=num-1{
        count++
    }
    return count
}
```

C++

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

### 12.[数值的整数次方](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)

Go版本

```go
func myPow(x float64, n int) float64 {
    if n==0{
        return 1
    }

    if n==1{
        return x
    }

    if n<0{
        return 1.0/myPow(x,-n)
    }else{
        y:=myPow(x,n/2)
        if n%2==0{
            return y*y
        }else{
            return x*y*y
        }
    }

}
```



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

> 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
>

```C++
#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	}

bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
	if (pRoot2 == NULL)
	{
		return true;
	}

	if (pRoot1 == NULL && pRoot2 == NULL)
	{
		return false;
	}

	if (pRoot1->val == pRoot2->val)
	{
		return isSubTree(pRoot1->left,pRoot2->left) && isSubTree(pRoot1->right,pRoot2->right);
	}
	else return false;
}


//第一步寻找1中是否有2根节点一样值的点
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    		bool flag = false;

    if (pRoot2 == NULL)
	{
		return false;
	}

	if (pRoot1 == NULL && pRoot2 != NULL)
	{
		return false;
	}

	if (pRoot1->val == pRoot2->val)
	{
		//找到值一样的点后，就判断结构是不是一样
		flag = isSubTree(pRoot1,pRoot2);
	}

	if (!flag)
	{
		flag = HasSubtree(pRoot1->left,pRoot2);
	}
	if (!flag)
	{
		flag = HasSubtree(pRoot1->right,pRoot2);
	}

	return flag;
}
```

### 18.[二叉树的镜像](http://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 操作给定的二叉树，将其变换为源二叉树的镜像。
>

```c++
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    }

   void Mirror(TreeNode *pRoot) {
        
          if(pRoot == NULL){
            return ;
        }
         
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
         
        if(pRoot->left){
            Mirror(pRoot->left);
        }
         
        if(pRoot->right){
            Mirror(pRoot->right);
        }

    }
```

### 19.[顺时针打印矩阵](http://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
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
```

### 20.[包含min函数的栈](http://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
>

```C++ 
 stack<int> m_data, m_min;
     
    void push(int value) {
        m_data.push(value);
        if(m_min.size() == 0 || m_min.top() > value){
            m_min.push(value);
        }else {
            m_min.push(m_min.top());
        }
    }
    void pop() {
        assert(m_data.size() >0 && m_min.size() > 0);
        m_data.pop();
        m_min.pop();
    }
    int top() {
        assert(m_data.size() > 0 && m_min.size() > 0);
        return m_data.top();
    }
    int min() {
        assert(m_data.size() > 0 && m_min.size() > 0);
        return m_min.top();
    }
```

### 21.[栈的压入、弹出序列](http://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
>

```C++
bool isPopOrder(int pushStack[],int popList[])
{
	if (pushStack.length == 0 || popList.length == 0)
	{
		return false;
	}

	Stack<int> stack  = new Stack<int>();
	int j = 0;
	for (int i = 0; i < pushStack.length; ++i)
	{
		stack.push(pushStack[i]);

		while(j<pushStack.length && pushStack.top ==popList[j])
		{
			pushStack.pop();
			j++;
		}
	}
}
```

### 22.[从上往下打印二叉树](http://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
>

```c++
//借助一个队列，先将头节点放进去 把节点值放到数组，出队列。再将节点左右节点压入队列。


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	}

vector<int> PrintFromTopToBottom(TreeNode *root) {

	queue<TreeNode*> queue;
	vector<int> r;
	q.push(root);

	while(!q.empty()){
		TreeNode *node = q.frount();
		q.pop();
		

		if (!node)
		{
			continue;
		}

		r.push_back(node->value);
		q.push(node->left);
		q.push(node->right);

	}

	return r;

    }
```

### 23.[二叉搜索树的后序遍历序列](http://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
bool judge(int a[],int l,int r){
	if (l>=r)
	{
		return true;
	}

	int i = r;
	while (i>1 && a[i-1] > a[r]) --i;

		for (int j = i-1; j >1; j--)
		{
			if (a[j] > a[r])
			{
				return false;
			}

			return judge(a,l,i-1) && judge(a,i,r-1);
		}
}

 bool VerifySquenceOfBST(int a[]) {
        if(!a.size()) return false;

        return judge(a, 0, a.size() - 1);
   }
```

### 24.[二叉树中和为某一值的路径](http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
vector<vector<int>> allRes;
vector<int> tmp;

void  dfsFind(TreeNode *node,int left){
	temp.push_back(node->value);
	if (left-node->value == 0 && node->left == NULL && node->right == NULL)
	{
		allRes.push_back(tmp);
	}else {
		if (node->left != NULL)
		{
			dfsFind(node->left,left-node->value);
		}

		if (node->right != NULL)
		{
			dfsFind(node->right,left-node->value);
		}
	}
}

 vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
 				if (root)
 				{
 					dfsFind(root,expectNumber);
 				}

 				return allRes;
    }
```

### 25.[复杂链表的复制](http://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
>

```c++
//分三步走，1.复制next节点放在原链表后面2.复制随机节点，按照原链表的顺序3.把两个链表分开

 RandomListNode* Clone(RandomListNode* pHead)
    {
    	//1
        RandomListNode* currentNode = pHead;
        while(currentNode)
        {
        	RandomListNode *node = new RandomListNode(currentNode->label);
        	node->next = currentNode->next;
        	currentNode->next = node;
        	currentNode = node->next;
        }
        //2
        currentNode = pHead;

        while(currentNode->random)
        {
        	currentNode->next->random=currentNode->random->next;
        	currentNode = currentNode->next->next;
        }

        //3
        RandomListNode* copyHead = pHead->next;

        currentNode = pHead;

        RandomListNode *tmp;

        while(currentNode->next){
        	tmp = currentNode ->next;
        	currentNode->next = tmp->next;
        	currentNode = tmp;
        }

        return copyHead;
    }
```

### 26.[二叉搜索树与双向链表](http://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 27.[字符串的排列](http://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 28.[数组中出现次数超过一半的数字](http://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
#include <iostream>
using namespace std;

int main(){
    int num[13]={1,2,3,4,4,4,4,4,4,4,5,6,7};
    
    int index[10]={0};
    
    for (int i = 0; i<13; i++) {
        index[num[i]]++;
    }
    
    for (int i = 0; i<10; i++) {
        if (index[i] > 13 /2 ) {
            cout<<i;
        }
    }
}
```

### 29.[最小的K个数](http://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
>

```c++
//冒泡排序，只排前K个数

public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
	ArrayList<Integer> ret = new ArrayList<Integer>();

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < input.length-i-1; ++j)
		{
			if (j[i+1]>j[i])
			{
				int temp = j[i+1];
				j[i+1] = j[i];
				j[i] = temp;
			}

			ret.add(input[input.length-i-1]);
		}
	}

	return ret;
}
```

### 30.[连续子数组的最大和](http://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int FindGreatestSumOfSubArray(vector<int> array) {

		int curSum =0;
		int GreatSum =0x80000000;
		for (int i = 0; i < array.length; ++i)
		{
			if (array[i] <= 0)
			{
				curSum = array[i];
			}else{
				curSum = curSum+array[i];
			}

			if (curSum > GreatSum)
			{
				GreatSum = curSum;
			}
		}

		return GreatSum;

}
```

### 31.[整数中1出现的次数（从1到n整数中1出现的次数）](http://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int find_1_num(int n){
for (int i = 1; i < n; ++i)
{
	int count = 0;

	while(i){
		if (i % 10 == 1)
		{
			count++;
		}
		i = i/10;
	}


}

return count;
}
```

### 32.[把数组排成最小的数](http://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
 // * 解题思路：
 // * 先将整型数组转换成String数组，然后将String数组排序，最后将排好序的字符串数组拼接出来。关键就是制定排序规则。
 // * 排序规则如下：
 // * 若ab > ba 则 a > b，
 // * 若ab < ba 则 a < b，
 // * 若ab = ba 则 a = b；
 // * 解释说明：
 // * 比如 "3" < "31"但是 "331" > "313"，所以要将二者拼接起来进行比较
static bool compare(const string str1,const string str2)
{
    string combined1,combined2;
    combined1=str1+str2;
    combined2=str2+str1;
    return combined1<combined2;
}
string PrintMinNumber(vector<int> numbers){
     
    vector<string> strvec;
    for (int i=0;i<numbers.size();i++)
    {
        string str;
        //stringstream由iostream派生而来
        stringstream ss;
        ss<<numbers[i];
        ss>>str;
        strvec.push_back(str); 
    }
 
    sort(strvec.begin(),strvec.end(),compare);
 
    string orderStr;
    for (int i=0;i<strvec.size();i++)
    {
        str.append(strvec[i]);
    }
    return orderStr;
 
}
```

### 33.[丑数](http://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```C++
bool isUgly(int number){
	while (number % 2 == 0)
	{
		number = number / 2;
	}

	while (number % 3 == 0)
	{
		number = number / 3;
	}

	while (number % 5 == 0)
	{
		number = number / 5;
	}

	if (number == 1)
	{
		return true;
	}else {
		return false;
	}
}

int getTheUgly(int index){
	if (index <= 0)
	{
		return 0;
	}

	int count = 0;
	int number = 0
	while(count < index){
		if (isUgly(number))
		{
			count++;
		}

		number++;
	}

	return number;
}
```

### 34.[第一个只出现一次的字符位置](http://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int FirstNotRepeatingChar(char * str) {
        if (str == NULL)
        {
        	return '\0'
        }

        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for (int i = 0; i < tableSize; ++i)
        {
        	hashTable[i] = 0;
        }

        char *hashKey = str;

        while(hashKey != '\0'){
        	hashTable[hashKey]++;
        	hashKey++;
        }

        hashKey = str;

        while(hashKey != '\0'){
        	if (hashTable[hashKey] == 1)
        	{
        		return *hashKey;
        	}else {
        		hashKey++;
        	}
        }
    }
```

### 35.[数组中的逆序对](http://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
//利用归并的思想好难，先用暴力解决下吧

int InversePairs(vector<int> data) {
	int count = 0;
        for (int i = 0; i < data.size(); ++i)
        {
        	for (int j = 0; j < i; ++j)
        	{
        		if (data[i]>data[j])
        		{
        			count++;
        		}
        	}
        }

        return count;
}

//归并排序思想
int InversePairs(vector<int> data) {
        int length  = data.size();
        return mergeSort(data, 0, length-1);
    }
 
    int mergeSort(vector<int>& data, int start, int end) {
        // 递归终止条件
        if(start >= end) {
            return 0;
        }
 
        // 递归
        int mid = (start + end) / 2;
        int leftCounts = mergeSort(data, start, mid);
        int rightCounts = mergeSort(data, mid+1, end);
 
        // 归并排序，并计算本次逆序对数
        vector<int> copy(data); // 数组副本，用于归并排序
        int foreIdx = mid;      // 前半部分的指标
        int backIdx = end;      // 后半部分的指标
        int counts = 0;         // 记录本次逆序对数
        int idxCopy = end;      // 辅助数组的下标
        while(foreIdx>=start && backIdx >= mid+1) {
            if(data[foreIdx] > data[backIdx]) {
                copy[idxCopy--] = data[foreIdx--];
                counts += backIdx - mid;
            } else {
                copy[idxCopy--] = data[backIdx--];
            }
        }
        while(foreIdx >= start) {
            copy[idxCopy--] = data[foreIdx--];
        }
        while(backIdx >= mid+1) {
            copy[idxCopy--] = data[backIdx--];
        }
        for(int i=start; i<=end; i++) {
            data[i] = copy[i];
        }
 
        return (leftCounts+rightCounts+counts);
    }
```

### 36.[两个链表的第一个公共结点](http://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```C++
//牛客网一位大神的解法，真心6
//用两个指针扫描”两个链表“，最终两个指针到达 null 或者到达公共结点。
 ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1;
        ListNode *p2;
        while(p1 != p2){
        	p1 = (p1 == NULL ? pHead2 :p1->next);
        	p2 = (p2 == NULL ? pHead1 :p2->next);
        }

        return p1;
    }



//常规解法
/*
找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
（因为2个链表用公共的尾部）
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = findListLenth(pHead1);
        int len2 = findListLenth(pHead2);
        if(len1 > len2){
            pHead1 = walkStep(pHead1,len1 - len2);
        }else{
            pHead2 = walkStep(pHead2,len2 - len1);
        }
        while(pHead1 != NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
     
    int findListLenth(ListNode *pHead1){
        if(pHead1 == NULL) return 0;
        int sum = 1;
        while(pHead1 = pHead1->next) sum++;
        return sum;
    }
     
    ListNode* walkStep(ListNode *pHead1, int step){
        while(step--){
            pHead1 = pHead1->next;
        }
        return pHead1;
    }
};
```

### 37.[数字在排序数组中出现的次数](http://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
 int GetNumberOfK(int* data ,int k) {

 	int length = data.size();
 	int number = 0;
 	if (data != NULL && length > 0)
 	{
 		int first = findFirstK(data,length,k,0,length-1);
 		int last = findLastK(data,length,k,0,length-1);

 		if (first > -1 && last > -1)
 		{
 			number = last - first +1;
 		}
 	}

 	return number;
        
    }

 int  findFirstK(int* data,int length,int k,int start,int end)
 {
 	int mid = (start + end)/2;
 	if (data[mid] == k)
 	{
 		if ( mid == 0 || mid >0 && data[mid -1] != k)
 		{
 			return mid;
 		}else{
 			end = mid -1;
 		}
 	}else if (data[mid] > k)
 	{
 		end = mid -1;
 	}else {
 		start = mid +1;
 	}

 	return findFirstK(data,length,k,start,end);
 }

 int findLastK(int* data ,int length,int k,int start,int end){

 	int mid = (start + end)/2;
 	if (data[mid] == k)
 	{
 		if ( mid == length -1 || mid <length -1 && data[mid +1] != k)
 		{
 			return mid;
 		}else{
 			start = mid +1;
 		}
 	}else if (data[mid] > k)
 	{
 		end = mid -1;
 	}else {
 		start = mid +1;
 	}

 	return findLastK(data,length,k,start,end);
 }
```

### 38.[二叉树的深度](http://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
int TreeDepth(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);

	return (left > right) ? (left+1):(right+1);
}
```

### 39.[平衡二叉树](http://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
bool IsBalanced = true;
bool IsBalanced_Solution(TreeNode* pRoot) {
		getDepth(pRoot);

		return IsBalanced;
    }

int getDepth(TreeNode* pRoot){

	if (pRoot == NULL)
	{
		return 0;
	}

	int left = getDepth(pRoot->left);

	int right = getDepth(pRoot->right);

	if (left - right < -1 || left-right > 1)
	{
		return false;
	}

	return left>right ? left+1 :right+1;

}
```

### 40.[数组中只出现一次的数字](http://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
#include <iostream>
using namespace std;

void calc(int* arr,int n)
{
	int result = 0;
	int a=0,b=0;
	for (int i = 0; i < n; ++i)
	{
		result = result^arr[i];
	}

	while(result)
	{
		if (result & 1 == 0)
		{
			index++;
			result = result>>1;
		}
		else break;
	}

	int cmp = 1<<index;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] & cmp)
		{
			a = a^arr[i];
		}else {
			b = b^arr[i];
		}
	}

	cout<<a<<" "<<b<<endl;
}
```

### 41.[和为S的连续正数序列](http://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
>
> ```
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
> ```

```C++
void findContinuousSequence(int sum){
	int small=1;
	int big = 2;
	int mid = sum /2;
	int cursum = small + big;
	while(small < mid){
		
		if (cursum = sum)
		{
			printResult(small,big);
		}else if(cursum > sum){
			cursum = cursum - small;
			small++;
		}else{

		big++;
		cursum = cursum + big;
		}
	}
}

void printResult(int small,int big){
	for (int i = small; i < big; ++i)
	{
		printf("%d",i );
	}
}
```

### 42.[和为S的两个数字](http://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
>
> ```
> 对应每个测试案例，输出两个数，小的先输出。
> ```

```c++
void findNumber(int data[],int length,int sum){
	

	 int start = 0;
	 int end = length-1;

	  int min = data[start];
	  int max = data[end];

	 while(start < end){

	 	if (min + max = sum)
	 	{
	 		cout<<min<<" "<<max<<endl;
	 	}else if (min + max > sum)
	 	{
	 		end --;
	 	}else{
	 		start ++；
	 	}
	 }
}
```

### 43.[左旋转字符串](http://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
>

```c++
void Reverse(char *start,char *end){
	if (start == NULL || end == NULL)
	{
		return;
	}

	while(start < end ){
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

char * leftRotateString(char *ptr,int n){
	int length = strlen(ptr);

	char *start1 = ptr;
	char *end1 = ptr+n-1;
	char *start2 = ptr+n;
	char *end2 = ptr+length-1;

	Reverse(start1,end1);
	Reverse(start2,end2);
	Reverse(start1,end2);
}
```

### 44.[翻转单词顺序列](http://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
char* ReverseSentence(char *s)
{
// 这两个指针用来确定一个单词的首尾边界
    char *start = s ;    // 指向单词的首字符
    char *end = s ;    // 指向空格或者 '\0'
	char *ptr =s;
    while(*ptr++ != '\0')
    {
        if (*ptr == ' '||*ptr =='\0')//最后一个单词为‘\0’
        {
			end = ptr-1;
			while(start < end)
            {
				swap(*start++, *end--) ;
			}
            start = end = ptr+1 ; // 指向下一个单词首字符
        }
       
    }
	//end = ptr-1;
 //   swap(*start++, *end--) ; // 对最后一个单词逆序
	start = s; end = ptr -2;
	while(start < end)
    {
		swap(*start++, *end--) ; // 对整个句子逆序
	}
    return s ;
}
```

### 45.[扑克牌顺子](http://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
>

```c++
bool isContinuous(int *numbers,int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers);

	int numberofzero = 0;
	int numberofgap =0;

	for (int i = 0; i < length && numbers[i] == 0; ++i)
	{
		numberofzero++;
	}

	int small = numberofzero;
	int big = small+1;
	while(big < length){
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberofgap += numbers[big] - numbers[small] -1;
		small = big;
		big++;
	}

	return numberofgap > numberofzero ? false :true;
}
```

### 46.[孩子们的游戏(圆圈中最后剩下的数)](http://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
>

```c++
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ListSize 100

 struct ListNode
{
 int data;
 struct ListNode *next; 
};


void Josephus(ListNode *head, int n, int m, int k)
{
 ListNode *p,*q;
 int i;
 p=head;
 /*先找到编号为k的人*/
 for(i=1; i<k; i++)/*从第k个人开始报数*/
  {
   q=p;
   p=p->next;
  }
 /*此时p指向第k个结点*/
 
 while(p->next != p)/*这个是判断是否只剩下一个结点*/
  {
  /*找出报数m的人*/
   for(i=1; i<m; i++)/*数到m的人出列*/
    {
     q=p;
     p=p->next;
    }
   /*此时p指向数到m的结点*/
   /*此时q指向的是m的前驱结点，p指向的是第m个结点*/
   
   q->next = p->next;/*这步就是将m的前驱结点指针域指向
   m的后继结点*/
   printf("%4d",p->data);/*打印出出列的数据*/
   free(p);/*释放出列的结点空间*/
   p=q->next;/*指向下一个结点，重新开始报数*/
  }
 printf("%4d\n", p->data);
 
}
 
/*//////////////////////////////////////////////////////////////////////////////
函数名:       CreateCycList
函数功能:   宏定义和单链表定义
入口参数: int n
出口参数: 
//////////////////////////////////////////////////////////////////////////////*/
ListNode *CreateCycList(int n)
{
 ListNode *head = NULL;
 ListNode *s, *r;
 int i;
 for(i = 1; i <= n; i ++ )
  {
   s = (ListNode *)malloc(sizeof(ListNode));
   s->data = i;
   s->next = NULL;
   if(head == NULL)
    head = s;
   else
    r->next = s;/*本节点指针域指向下一个结点*/
   r = s;/*临时指针指向下一个结点*/
  }
 r->next = head;/*最后一个结点的指针域指向头结点形成环*/
 return head;/*返回头结点的地址*/
}
/*//////////////////////////////////////////////////////////////////////////////
函数名:       main()
函数功能:   主函数
入口参数: 
出口参数: 
//////////////////////////////////////////////////////////////////////////////*/
void main()
{
 ListNode *h;
 int n,k,m;
 printf("输入环中人的个数n=");
 scanf("%d", & n);
 printf("输入开始报数的序号k=");
 scanf("%d", & k);
 printf("报数为m的人出列m=");
 scanf("%d", & m);
 h=CreateCycList(n);
 Josephus(h, n, m, k);
 system("pause");
}
```

### 47.[求1+2+3+...+n](http://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
int sum(int n){
	int num = n;
while(num){
	num = num + sum(n-1);
}

	return num;
}
```

### 48.[不用加减乘除做加法](http://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
>

```
  int Add(int num1, int num2)
    {
        while(num2!=0)
        {
            int temp=num1^num2;
            num2=(num1&num2)<<1;
            num1=temp;
        }
        return num1;
    }
```

### 49.[把字符串转换成整数](http://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
#include<iostream>
using namespace std;

int str2int(const char *str)
{
	const char *ptr = str;
	int temp = 0;
	if(*str == '+'|| *str == '-')
	{
		str++;
	}
	while(*str != 0)
	{
		if(*str < '0' || *str > '9')
		{
			break;
		}

		temp = temp * 10 + (*str - '0');
		str++;
	}

	if(*ptr == '-')
	{
		temp = -temp;
	}
	return temp;
}
int main()
{
	while(1)
	{
		int n = 0;
	char s[20];
	cin>>s;
	n = str2int(s);
	cout<<n<<endl;
	}
	
	 system("pause");
}
```

### 50.[数组中重复的数字](http://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
>

```c++
int find(int *numbers,int length)
{
	for (int i = 0; i < length; ++i)
	{
		int index = numbers[i];
		if (index > length)
		{
			index = index -length;
		}

		if (numbers[index] > length)
		{
			return index;
		}

		numbers[index] = numbers[index] + length;
	}

	return -1;
}
```

### 51.[构建乘积数组](http://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
>

```c++
 vector<int> multiply(const vector<int>& A) {

 	int n = A.size();

 	vector<int> b(n);

 	int ret = 1;
 	b[0] = 1;

 	for (int i = 0; i < n; ++i)
 	{
 		b[i] = b[i-1] * A[i-1];
 	}

 	for (int i = n-1; i >=1; i--)
 	{
 		b[i] = b[i]*b[0];

 		b[0] = b[0] *a[i];
 	}

 	return B; 
 }
```

### 52.[正则表达式匹配](http://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
>

### 53.[表示数值的字符串](http://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
>

### 54.[字符流中第一个不重复的字符](http://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
>
> ```
> 如果当前字符流没有存在出现一次的字符，返回#字符。
> ```

```c++
int FirstNotRepeatingChar(char * str) {
        if (str == NULL)
        {
        	return '\0'
        }

        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for (int i = 0; i < tableSize; ++i)
        {
        	hashTable[i] = 0;
        }

        char *hashKey = str;

        while(hashKey != '\0'){
        	hashTable[hashKey]++;
        	hashKey++;
        }

        hashKey = str;

        while(hashKey != '\0'){
        	if (hashTable[hashKey] == 1)
        	{
        		return *hashKey;
        	}else {
        		hashKey++;
        	}
        }
    }
```

### 55.[链表中环的入口结点](http://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 一个链表中包含环，请找出该链表的环的入口结点。
>

```c++
//第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，直到p1==p2找到在环中的相汇点。
//第二步，找环的入口。接上步，当p1==p2时，p2所经过节点数为2x,p1所经过节点数为x
//设环中有n个节点,p2比p1多走一圈有2x=n+x; n=x;可以看出p1实际走了一个环的步数
//再让p2指向链表头部，p1位置不变，p1,p2每次走一步直到p1==p2; 此时p1指向环的入口。
 ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	ListNode *p1 = pHead;
    	ListNode *p2 = pHead;

    	while(p2 != NULL && p2.next!= NULL)
    	{
    		p1 = p1->next;
    		p2 = p2->next->next;
    		if (p1 == p2)
    		{
    			p2 = pHead;

    			while(p1 = p2)
    			{
    				p1 = p1->next;
    				p2 = p2->next;
    			}

    			if (p1 = p2)
    			{
    				return p1;
    			}
    		}
    	}

    	return NULL;

    }
```

### 56.[删除链表中重复的结点](http://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
>

### 57.[二叉树的下一个结点](http://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
  TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
        {
        	return NULL;
        }

        if (pNode->right != NULL)
        {
        	pNode = pNode->right;

        	while(pNode->left != NULL)
        	{
        		pNode = pNode->left;
        	}

        	return pNode;
        }

        while(p->next != NULL){
        	if (pNode == pNode->next->left)
        	{
        		return pNode->next;
        	}

        	pNode = pNode->next;
        }

        return NULL;
    }
```

### 58.[对称的二叉树](http://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
>

```c++
bool isSymmetrical(TreeNode* pRoot)
    {
    	if (pRoot == NULL)
    	{
    		return true;
    	}

    	return f(pRoot->left,pRoot->right);
    }


bool f(TreeNode* p1,TreeNode* p2)
{
	if (p1 == NULL && p2 == NULL)
	{
		return true;
	}

	if (p1 != NULL && p2 != NULL)
	{
			return p1->val==p2->val && f(p1->left,p1->right) && f(p2->left,p2->right);
	}

	return false;
}
```

### 59.[按之字形顺序打印二叉树](http://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 60.[把二叉树打印成多行](http://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 61.[序列化二叉树](http://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

### 62.[二叉搜索树的第k个结点](http://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

```c++
TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == NULL)
        {
        	return NULL;
        }

        if (pRoot->left != NULL)
        {
        	TreeNode* p = KthNode(pRoot->left,k);
        	if (p != NULL)
        	{
        		return p;
        	}
        }

        if (k == 1)
        {
        	return pRoot;
        }else{
        	k--;
        }

        if (pRoot->right != NULL)
        {
        	TreeNode* p = KthNode(pRoot->right,k);
        	if (p != NULL)
        	{
        		return p;
        	}
        }
        return NULL;
    }
```

### 63.[数据流中的中位数](http://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
>

### 64.[滑动窗口的最大值](http://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
>

### 65.[矩阵中的路径](http://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
>

### 66.[机器人的运动范围](http://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
>

