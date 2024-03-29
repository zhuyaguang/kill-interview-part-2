## 剑指offer汇总

### 1.[剑指 Offer 04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

#### 解法一：暴力

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
// 使用rune 数组
func replaceSpace(s string) string {
    arr :=[]rune(s)
    result :=""
    for _,v :=range arr{
       if v!=32{
           result = result+string(v)
       }else{
           result = result+"%20"
       }
    }
    return result
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

~~~go
func buildTree(preorder []int, inorder []int) *TreeNode {
   if len(inorder)==0 || len(preorder)==0{
        return nil
    }

    rootVal :=preorder[0]
     
    rootIndex :=0

      for i,v :=range inorder{
          if v == rootVal{
              rootIndex = i
          }
      }
      leftArr :=inorder[:rootIndex]
      rightArr :=inorder[rootIndex+1:]
      postLeft :=preorder[1:len(leftArr)+1]
      postRight :=preorder[len(leftArr)+1:len(preorder)]
      rootNode :=&TreeNode{
          Val:rootVal,
      }
     rootNode.Left = buildTree(postLeft,leftArr)
     rootNode.Right = buildTree(postRight,rightArr)

     return rootNode
}
~~~



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

~~~go
func findMin(nums []int) int {
	left :=0
	right :=len(nums)-1

	for left<right{
		mid :=left+(right-left)/2
            if nums[mid]>nums[right]{
            	left=mid+1
			}else if nums[mid]<nums[right]{
			right=mid
		}else if nums[mid]==nums[right]{
			right--
		}
	}

	return nums[left]

}
~~~



### 7.[斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)

```go
//我的解法

long long Fibonacci(int n){
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;

	return Fibonacci(n-1)+Fibonacci(n-2);

}


//大神的解法 动态规划
func fib(n int) int {
    if n==0{
        return 0
    }
    if n==1{
        return 1
    }
    
      dp:=make([]int,n+1)
      dp[0]=0
      dp[1]=1
      for i:=2;i<=n;i++{
          dp[i]=dp[i-1]+dp[i-2]
          dp[i] %= 1000000007
      }
      return dp[n]
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

### 10-3.[剑指 Offer 14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)

### 10-4.[剑指 Offer 14- II. 剪绳子 II](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/)



### 11.[二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)

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



### 12.[数值的整数次方](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)

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

### 13.[调整数组顺序使奇数位于偶数前面](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/)

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

```go
func exchange(nums []int) []int {
	n:=len(nums)
	i:=0
	j:=n-1
	for i<j{
		if nums[i]%2!=0{
			i++
			continue
		}
		if nums[j]%2==0{
			j--
			continue
		}

		nums[i],nums[j]=nums[j],nums[i]
	}
	return nums

}

```



### 14.[链表中倒数第k个结点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

1.第一个指针先走k步,第二个指针开始走，当第一个指针走到尽头的时候，第二个指针就是倒数第K个结点

2.

```go

func getKthFromEnd(head *ListNode, k int) *ListNode {
    if k==0{
        return head
    }
    len:=0
    cur :=head
    result:=head
    for cur!=nil{
        len++
        cur=cur.Next
    }
    index:=len-k
    for result!=nil&&index>0{
        index--
        result=result.Next
    }
   return result
}
```



### 15.[反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

```go

// 迭代法

func reverseList(head *ListNode) *ListNode {
    var prev *ListNode
    curr := head
    for curr != nil {
        next := curr.Next
        curr.Next = prev
        prev = curr
        curr = next
    }
    return prev
}
//递归法
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    newHead := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil
    return newHead
}
```



### 16.[合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

```go
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1==nil&&l2==nil{
		return nil
	}
	if l1==nil{
		return l2
	}
	if l2==nil{
		return l1
	}
          fake :=&ListNode{
			  Val:   0,
		  }
		  cur :=fake
		  for l1!=nil&&l2!=nil{
		  	if l1.Val<l2.Val{
		  		cur.Next=l1
		  		l1=l1.Next
			}else{
				cur.Next=l2
				l2=l2.Next
			}
            cur=cur.Next
		  }
		  if l1==nil{
		  	cur.Next=l2
		  }
		  if l2==nil{
		  	cur.Next=l1
		  }
    return fake.Next
}

```

### 17.[树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)

```go
func isSubStructure(A *TreeNode, B *TreeNode) bool {
    res:=false
    if A==nil || B==nil{
        return false
    }
    if A.Val==B.Val{
        res=issub(A,B)
    }
    if res!=true{
 res =isSubStructure(A.Left,B)
    }
   
   if res!=true{
res =isSubStructure(A.Right,B)
   }
        return res
}


func issub(A *TreeNode, B *TreeNode) bool{
         if B==nil{
             return true
         }

         if A==nil{
             return false
         }

         if A.Val!=B.Val{
             return false
         }

         return issub(A.Left,B.Left)&&issub(A.Right,B.Right)
}

```



### 18.[二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)

```go
func mirrorTree(root *TreeNode) *TreeNode {
    if root==nil{
    	return nil
	}
	left :=mirrorTree(root.Left)
	right :=mirrorTree(root.Right)
	root.Right=left
	root.Left=right
	return root
}
```

### 19.[顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)

```go
func spiralOrder(matrix [][]int) []int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return []int{}
    }
    var (
        rows, columns = len(matrix), len(matrix[0])
        order = make([]int, rows * columns)
        index = 0
        left, right, top, bottom = 0, columns - 1, 0, rows - 1
    )

    for left <= right && top <= bottom {
        for column := left; column <= right; column++ {
            order[index] = matrix[top][column]
            index++
        }
        for row := top + 1; row <= bottom; row++ {
            order[index] = matrix[row][right]
            index++
        }
        if left < right && top < bottom {
            for column := right - 1; column > left; column-- {
                order[index] = matrix[bottom][column]
                index++
            }
            for row := bottom; row > top; row-- {
                order[index] = matrix[row][left]
                index++
            }
        }
        left++
        right--
        top++
        bottom--
    }
    return order
}
```

### 20.[包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

```go
type MinStack struct {
    stack []int
    minStack []int
}

func Constructor() MinStack {
    return MinStack{
        stack: []int{},
        minStack: []int{math.MaxInt64},
    }
}

func (this *MinStack) Push(x int)  {
    this.stack = append(this.stack, x)
    top := this.minStack[len(this.minStack)-1]
    this.minStack = append(this.minStack, min(x, top))
}

func (this *MinStack) Pop()  {
    this.stack = this.stack[:len(this.stack)-1]
    this.minStack = this.minStack[:len(this.minStack)-1]
}

func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1]
}

func (this *MinStack) Min() int {
    return this.minStack[len(this.minStack)-1]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

### 21.[栈的压入、弹出序列](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)

```go
func validateStackSequences(pushed []int, popped []int) bool {
	stackA:=[]int{}

	for _,v:=range pushed{
		stackA=append(stackA,v)

		for  stackA[len(stackA)-1]==popped[0]{
				stackA=stackA[:len(stackA)-1]
				popped=popped[1:]
				if len(stackA)==0{
					break
				}
		}
	}
	return  len(stackA)==0

}
```

### 22.[从上往下打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)

```go
func levelOrder(root *TreeNode) []int {
        if root==nil{
        	return []int{}
		}
		result:=[]int{}
		queue :=[]*TreeNode{root}
		for len(queue)>0{
			index:=len(queue)
			for i:=0;i<index;i++{
                if queue[i]!=nil{
				result=append(result,queue[i].Val)
				queue=append(queue,queue[i].Left)
				queue=append(queue,queue[i].Right)
                }
				
			}
			queue=queue[index:]
		}

		return result
}

```

### 23.[二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

```go
func verifyPostorder(postorder []int) bool {
	n:=len(postorder)
	if n==0{
		return true
	}
	root :=postorder[n-1]
	index:=-1
	for i:=0;i<n-1;i++{
		if postorder[i]>root{
			index=i
			break
		}
	}
	if index!=-1{
		for i:=index;i<n-1;i++{
			if postorder[i]<root{
				return false
			}
		}
	}
	if index==-1{
		return verifyPostorder(postorder[:n-1])
	}

	return verifyPostorder(postorder[:index])&&verifyPostorder(postorder[index:n-1])
}

```

### 24.[二叉树中和为某一值的路径](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)

```go
var trace []int
var result [][]int
func pathSum(root *TreeNode, target int) [][]int {
	trace=[]int{}
	result=[][]int{}
	if root==nil{
		return result
	}
	dfs1(root,trace,target)

   return result
}

func dfs1(root *TreeNode,trace []int,tar int)  {
    if root==nil{
        return
    }
    trace=append(trace,root.Val)
    tar=tar-root.Val
	if tar==0&&root.Left==nil&&root.Right==nil{
		tmp:=make([]int,len(trace))
		copy(tmp,trace)
		result=append(result,tmp)
		return
	}
	
    dfs1(root.Left,trace,tar)
	dfs1(root.Right,trace,tar)
	trace=trace[:len(trace)-1]

}

```

### 25.[复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)

```go
func copyRandomList(head *Node) *Node {
     nMap:=make(map[*Node]*Node)
     cur :=head
     next:=head
     for cur!=nil{
     	tmp:=&Node{
			Val:    cur.Val,
		}
     	nMap[cur]=tmp
     	cur=cur.Next
	 }
	 for next!=nil{
	 	nMap[next].Random=nMap[next.Random]
		nMap[next].Next=nMap[next.Next]
        next=next.Next
	 }
	 return nMap[head]
}
```

### 26.[二叉搜索树与双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

```go
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var pre *TreeNode
var head *TreeNode

func treeToDoublyList(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	pre = nil
	head = nil
	convert(root)
	pre.Right = head
	head.Left = pre
	return head
}

func convert(root *TreeNode) {
	if root == nil {
		return
	}
	convert(root.Left)
	if pre == nil {
		head = root
	}else {
		pre.Right = root
		root.Left = pre
	}
	pre = root
	convert(root.Right)
}
```



### 27.[字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)

```go
var resultS []string
var traces string
func permutation(s string) []string {
	if len(s) == 0 {
		return nil
	}
     resultS=[]string{}
     traces = ""
     stringArr :=[]string{}
     for _,v:=range s{
     	stringArr = append(stringArr,string(v))
	 }
	 sort.Strings(stringArr)
     visit :=make([]bool,len(stringArr))

	backtracks(stringArr,traces,visit)

	return resultS
}

func backtracks(s []string ,traces string,visit []bool)  {
	if len(traces)==len(s){
		resultS=append(resultS,traces)
		return
	}
	for i:=0;i<len(s);i++{
		if i>0 && !visit[i-1] && s[i]==s[i-1]{
			continue
		}
		if visit[i]{
			continue
		}

			traces=traces+s[i]
			visit[i]=true
			backtracks(s,traces,visit)
			traces=traces[:len(traces)-1]
			visit[i]=false
	}
}
```



### 28.[数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/)

```go
func majorityElement(nums []int) int {
    n:=len(nums)
    target:=0
    if n%2==0{
           target=n/2
    }else{
        target=n/2+1
    }
    rMap:=make(map[int]int)
    for _,v:=range nums{
        rMap[v]++
        if rMap[v]==target{
            return v
        }
    }
    return 0

}
```

### 29.[最小的K个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

```go
func getLeastNumbers(arr []int, k int) []int {
	if len(arr) == 0 || k == 0 {
		return nil
	}

	// 建堆，大根堆
	d := &heapInt{}
	for _, v := range arr {
		if d.Len() < k {
			heap.Push(d, v)
		} else {
			if d.Peek() > v {
				heap.Pop(d)
				heap.Push(d, v)
			}
		}
	}
	return d.IntSlice

}

type heapInt struct {
	sort.IntSlice
}

func (h *heapInt)Less(i,j int)bool {return h.IntSlice[i]>h.IntSlice[j]}

func (h *heapInt) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
func (h *heapInt) Pop() interface{} {
	a := h.IntSlice
	t := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return t
}
func (h *heapInt) Peek() int {
	return h.IntSlice[0]
}
```

### 30.[连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)

```go
func maxSubArray(nums []int) int {
    if len(nums) == 1{
        return nums[0]
    }
    max:=nums[0]
    dp :=make([]int,len(nums))
    dp[0]=nums[0]
    for i:=1;i<len(nums);i++{ 
        if dp[i-1]+nums[i] >= nums[i] {
            dp[i]=dp[i-1]+nums[i]
            if dp[i]>=max{
                max = dp[i]
            }
        }else {
            dp[i]=nums[i]
            if dp[i]>=max{
                max = dp[i]
            }
        }
        
    }
    return max
}
```

### 31.[整数中1出现的次数（从1到n整数中1出现的次数)](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)

```go
func countDigitOne(n int) int {
	// 这里 digitNum 为 digit 所在位 对应的可能性
	// 其实位为个位 因此 digitNum = 1  1乘以任何数 = 任何数
	digitNum, sum := 1, 0
	high, cur, low := n/10, n%10, 0
	for high != 0 || cur != 0 {
		// 固定位 计算数量
		if cur < 1 {
			sum += high * digitNum
		} else if cur == 1 {
			sum += high*digitNum + low + 1
		} else {
			sum += (high + 1) * digitNum
		}
		// 换下一位 更新高低位 及digit数量级
		low = low + cur*digitNum
		high, cur = high/10, high%10
		digitNum = digitNum * 10
	}
	return sum
}
```

### 31-1[剑指 Offer 44. 数字序列中某一位的数字](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)



### 32.[把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)

```go
func minNumber(nums []int) string {
        for i:=0;i<len(nums)-1;i++{
			for j:=i+1;j<len(nums);j++ {
				if compare(nums[i],nums[j]){
					nums[i],nums[j]=nums[j],nums[i]
				}
			}
		}
		s:=""
		
		for i:=range nums{
			s=s+strconv.Itoa(nums[i])
		}
		return s
}


func compare(a,b int)bool{
	sa:= strconv.Itoa(a)+strconv.Itoa(b)
	sb:= strconv.Itoa(b)+strconv.Itoa(a)
	na,_:=strconv.Atoi(sa)
	nb,_:=strconv.Atoi(sb)

	return na>nb
}
```

32-1.[剑指 Offer 46. 把数字翻译成字符串](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)

~~~go
func translateNum(num int) int {
    if num <=9{
        return 1
    }
    ba :=num%100
    if ba <=9 || ba >=26{
        return translateNum(num/10)
    }else{
        return translateNum(num/10)+translateNum(num/100)
    }

}
~~~

32-2.[剑指 Offer 47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)

~~~go
// 二维的dp数组
func maxValue(grid [][]int) int {
        m:=len(grid)
        n:=len(grid[0])
        for i:=1;i<n;i++{
            grid[0][i]+=grid[0][i-1]
        }
        for i:=1;i<m;i++{
            grid[i][0]+=grid[i-1][0]
        }
        fmt.Print(grid)
        for i:=1;i<m;i++{
            for j:=1;j<n;j++{
                grid[i][j]+=max(grid[i-1][j],grid[i][j-1])
            }
        }
        return grid[m-1][n-1]
}

func max(a,b int)int{
    if a>=b{
        return a
    }else {
        return b
    }
}
~~~

32-3.[剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)

~~~go
func lengthOfLongestSubstring(s string) int {
	if len(s)==0{
		return 0
	}
	if len(s)==1{
		return 1
	}

	windows :=make(map[string]int)
	left :=0
	right :=0
	max :=-1
	for right < len(s){
		c :=s[right:right+1]
        right++
		windows[c]++
		for windows[c]>1{
			c2 :=s[left:left+1]
			left++
			windows[c2]--
		}
		if right-left>max{
			max = right-left
		}
	}
	if max == -1{
		max = len(s)
	}
	return max
}
~~~



### 33.[丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)

### 34.[第一个只出现一次的字符位置](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)

~~~go
func firstUniqChar(s string) byte {
    n:=len(s)
    if n==0{
        return ' '
    }
    bMap:=make(map[byte]int)
    for i,_:=range s{
        bMap[s[i]]++
    }

    for i,_:=range s{
        if bMap[s[i]]==1{
            return s[i]
        }
    }
  
     return ' '

}
~~~

### 35.[数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

暴力

### 36.[两个链表的第一个公共结点](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)

```go

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA==nil||headB==nil{
		return nil
	}
    if headA==headB{
		return headA
	}
	startA:=headA
	startB:=headB
	lenA:=0
	lenB:=0
	gap:=0
	for startA!=nil{
		lenA++
		startA=startA.Next
	}
	for startB!=nil{
		lenB++
		startB=startB.Next
	}
	if lenA>lenB{
		gap=lenA-lenB
		for gap>0{
			headA=headA.Next
			gap--
		}
	}else{
		gap=lenB-lenA
		for gap>0{
			headB=headB.Next
			gap--
		}
	}
    	if headA==headB{
		return headA
	}
       for headA.Next!=nil&&headB.Next!=nil{
       	   if headA.Next==headB.Next{
       	   	return headA.Next
		   }
		   headA=headA.Next
		   headB=headB.Next
	   }

	   return nil
}
```

36-2.[剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/)

~~~go
func missingNumber(nums []int) int {
    n := len(nums)
    sum := 0
    for _,v:=range nums{
        sum = sum + v
    }
    sum2 :=n*(n+1)/2
    if sum == sum2{
        return 0
    }else{
         return sum2-sum
    }
    return 0
   
}
~~~



### 37.[数字在排序数组中出现的次数](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

遍历一次

### 38.[二叉树的深度](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/)

```go
func maxDepth(root *TreeNode) int {
if root ==nil{
    return 0
}

return max(maxDepth(root.Left),maxDepth(root.Right))+1
    
}

func max(a,b int)int{
    if a>=b{
        return a
    }

    return b
}
```

### 39.[平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)

1深度差>2就是不平衡的

### 40.[数组中只出现一次的数字](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)

map

40-1.[剑指 Offer 56 - II. 数组中数字出现的次数 II](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)

map 

### 41.[和为S的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

 ~~~go
 func findContinuousSequence(target int) [][]int {
 	if target == 0{
 		return [][]int{}
 	}
 	windows :=[]int{}
 	result :=[][]int{}
 	right :=1
 	windows = append(windows,1)
 	for right <= target/2+1{
              sum := sumA(windows)
              if sum < target{
 				 right++
              	windows = append(windows,right)
 
 			 }else if sum > target{
 			 	windows = windows[1:]
 			 }else {
 			 	if len(windows)!=1{
 					result = append(result,windows)
 					windows = windows[1:]
 				}else {
 					break
 				}
 			 }
 	}
 
 	return result
 }
 
 func sumA(A []int) int {
 	sum :=0
 	for _,v:=range A{
 		sum = sum+v
 	}
 	return sum
 }
 ~~~



### 42.[和为S的两个数字](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

~~~go
// 直接遍历会超时，双指针
func twoSum(nums []int, target int) []int {
    sort.Ints(nums)
     n:=len(nums)
     i,j:=0,n-1
     result:=[]int{}
     for i<j{
         if nums[i]+nums[j]>target{
             j--
         }
        if nums[i]+nums[j]==target{
             return []int{nums[i],nums[j]}
         }
        if nums[i]+nums[j]<target{
            i++
         }
     }
     return result

}
~~~



### 43.[左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

~~~go
func reverseLeftWords(s string, n int) string {
   return s[n:]+s[0:n]

}
~~~

### 44.[翻转单词顺序列](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)

~~~go
func reverseWords(s string) string {
	if len(s)==0{
		return ""
	}
	  arrayS :=strings.Split(s," ")
	  s2:=""
	  for i:=len(arrayS)-1;i>=0;i--{
	  	if arrayS[i]==""{
	  		continue
		}else{
			s2=s2+" "+arrayS[i]
		}

	  }
	 if len(s2)==0{
	 	return ""
	 }
	  s2=s2[1:]
	  return s2
}
~~~



### 45.[扑克牌顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

~~~go
func isStraight(nums []int) bool {
    sort.Ints(nums)
    joker :=0
    for i:=0;i<4;i++{
        if nums[i]==0{
            joker++
            continue
        }else{
            if nums[i]==nums[i+1]{
            return false
        }
        }       
    }
    return nums[4]-nums[joker] < 5

}
~~~



### 46.[圆圈中最后剩下的数](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)

~~~go
func lastRemaining(n int, m int) int {
     result :=0
     for i:=2;i<=n;i++{
         result=(result+m)%i
     }
     return result
}
~~~



### 46-1.[剑指 Offer 63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)

~~~go
// 动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
func maxProfit(prices []int) int {
     
     length :=len(prices)
     dp :=make([]int,length)
     cost :=prices[0]
     
     for i:=1;i<length;i++{
         cost = min(prices[i],cost)
         dp[i] = max(dp[i-1],prices[i]-cost)
         
     }

     return dp[length-1]
}


func min(a,b int)int{
    if a>=b{
        return b
    }
    return a
}

func max(a,b int)int{
    if a>=b{
        return a
    }
    return b
}

~~~



### 47.[求1+2+3+...+n](https://leetcode-cn.com/problems/qiu-12n-lcof/)

```c++
int sum(int n){
	int num = n;
while(num){
	num = num + sum(n-1);
}
	return num;
}
```

### 48.[不用加减乘除做加法](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/)

~~~go
func add(a int, b int) int {
             n := a^b
             c := (a&b)<<1

             return n+c
}

~~~

### 48.[最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)

~~~go
func lengthOfNonRepeatingSubStr(s string) int {
	lastOccurred := make(map[rune]int)
	start := 0
	maxLength := 0

	for i, ch := range []rune(s) {
		if lastI, ok := lastOccurred[ch]; ok && lastI >= start {
			start = lastI + 1
		}
		if i-start+1 > maxLength {
			maxLength = i - start + 1
		}
		lastOccurred[ch] = i
	}

	return maxLength
}
~~~



### 49.[把字符串转换成整数](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/)

~~~go
func strToInt(str string) int {
   str=strings.TrimSpace(str)
   res:=0
   flag:=1


   for i,v:=range str{
   	   if v>='0'&&v<='9'{
   	   	res=res*10+int(v-'0')
	   }else if v=='-' && i==0{
   	flag=-1
   }else if v=='+'&& i==0{
   	flag=1
   }else {
       break
   }
      if res>math.MaxInt32{
   	if flag==-1{
   		return  math.MinInt32
	}else{
		return math.MaxInt32
	}
   }

   }
   
   return flag*res
}
~~~



### 50.[数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

Map

### 51.[构建乘积数组](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/)

动态规划

~~~go
func constructArr(a []int) []int {
     length :=len(a)
     if length ==0 {
         return []int{}
     }
     b :=make([]int,length)
     b[0]=1
     for i:=1;i<length;i++{
         b[i]=b[i-1]*a[i-1]
     }
     tmp :=1
     for j:=length-2;j>=0;j--{
         tmp=tmp * a[j+1]
         b[j]=b[j]*tmp
     }

     return b
}
~~~



### 52.[正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)

### 53.[表示数值的字符串](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)

### 54.[字符流中第一个不重复的字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

~~~go
func firstUniqChar(s string) int {
    cnt := [26]int{}
    for _, ch := range s {
        cnt[ch-'a']++
    }
    for i, ch := range s {
        if cnt[ch-'a'] == 1 {
            return i
        }
    }
    return -1
}
~~~

### 55.[链表中环的入口结点](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

 ~~~go
 func detectCycle(head *ListNode) *ListNode {
     LMap:=map[*ListNode]int{}
     for head!=nil{
         if _,ok:=LMap[head];ok{
             return head
         }
         LMap[head]++
         head=head.Next
     }
     return nil
 }
 ~~~



### 56.[删除链表中重复的结点](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

~~~go
func deleteDuplicates(head *ListNode) *ListNode {
    if head==nil{
        return nil
    }
    pre:=head
    cur:=head.Next

    for cur!=nil{
        if pre.Val==cur.Val{
            pre.Next=cur.Next
            cur=pre.Next
        }else{
            pre=cur
            cur=cur.Next
        }
    }

    return head
}
~~~



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

### 58.[对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)

~~~go
// 先把找到数的镜像树，然后再判断是否相等
func isSymmetric(root *TreeNode) bool {
	if root==nil{
		return true
	}
	tmp:=root
	mi:=mirow(root)

	return same(tmp,mi)

}

func same(root,mi *TreeNode) bool  {
	if root==nil&&mi==nil{
		return true
	}
	if root==nil{
		return false
	}
	if mi==nil{
		return false
	}

	if root.Val!=mi.Val{
		return false
	}
	return same(root.Left,mi.Left)&&same(root.Right,mi.Right)
}

func mirow(root *TreeNode)  *TreeNode {
	if root==nil{
		return nil
	}
	p:=&TreeNode{
		Val:   root.Val,
		Left:  nil,
		Right: nil,
	}
	left:=mirow(root.Left)
	right:=mirow(root.Right)
	p.Left=right
	p.Right=left
	return p
}

// 递归
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }

    return helper(root.Left,root.Right)

}

func helper(root1,root2 *TreeNode) bool{
    if root1==nil && root2==nil{
        return true
    }
    if root1 ==nil || root2 == nil{
        return false
    }

    return root1.Val==root2.Val && helper(root1.Left,root2.Right) && helper(root1.Right,root2.Left)
}
~~~



### 59.[按之字形顺序打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)

层次遍历可以默写

### 60.[把二叉树打印成多行](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

层次遍历

### 61.[序列化二叉树](https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/)

### 62.[二叉搜索树的第k个结点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)

中序遍历

### 63.[数据流中的中位数](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)

### 64.[滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

### 65.[矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)

~~~go
func exist(board [][]byte, word string) bool {
	m:=len(board)
	n:=len(board[0])
	for i:=0;i<m;i++{
		for j:=0;j<n;j++{
			if dfs(board,word,i,j,0){
				return true
			}
		}
	}

	return false


}

func dfs(board [][]byte, word string,i,j,k int)bool{
	if i>= len(board)||i<0||j>=len(board[0])||j<0||board[i][j]!=word[k]{
		return false
	}
	if k==len(word)-1{
		return true
	}
	board[i][j]='*'
	res:=dfs(board,word,i+1,j,k+1)||dfs(board,word,i-1,j,k+1)||dfs(board,word,i,j-1,k+1)||dfs(board,word,i,j+1,k+1)
    board[i][j]=word[k]
	return res

}
~~~



### 66.[机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)



#### [剑指 Offer 68 - I. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

#### [剑指 Offer 68 - II. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)
