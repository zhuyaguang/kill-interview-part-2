## 回溯、DFS

- 回溯是递归的副产品，只要有递归就会有回溯。
- **因为回溯的本质是穷举，穷举所有可能，然后选出我们想要的答案**，如果想让回溯法高效一些，可以加一些剪枝的操作，但也改不了回溯法就是穷举的本质。
- 那么既然回溯法并不高效为什么还要用它呢？
因为没得选，一些问题能暴力搜出来就不错了，撑死了再剪枝一下，还没有更高效的解法。
此时大家应该好奇了，都什么问题，这么牛逼，只能暴力搜索。

- 回溯法解决的问题

回溯法，一般可以解决如下几种问题：

-   组合问题：N个数里面按一定规则找出k个数的集合
-   切割问题：一个字符串按一定规则有几种切割方式
-   子集问题：一个N个数的集合里有多少符合条件的子集
-   排列问题：N个数按一定规则全排列，有几种排列方式
-   棋盘问题：N皇后，解数独等等


组合是不强调元素顺序的，排列是强调元素顺序

### 回溯法公式

```go
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表: 
// 这里的for 循环要用i:=0;i<len(nums);i++ 因为i可以用来当作是否重复选择的依据
// i=startIndex 可以去掉重复组合
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

### 回溯问题思路

* 子集 最通用的组合 ;组合  满足一定条件的子集 ;
  其实子集也是一种组合问题，因为它的集合是无序的，子集{1,2} 和 子集{2,1}是一样的。那么既然是无序，取过的元素不会重复取，写回溯算法的时候，for就要从startIndex开始，而不是从0开始！
  有同学问了，什么时候for可以从0开始呢？
  求排列问题的时候，就要从0开始，因为集合是有序的，{1, 2} 和{2, 1}是两个集合
* 组合和子集都需要一个startindex 来排除索引之前的数字 
* 排列 需要通过contains方法判断是否排除track中已经选过的数字或者维护一个visit []bool 数组 
* 不管是子集组合还是排列，如果有重复都数字需要排序，然后都要判断下相邻是否相同 
* 组合不能解决超时了，就是背包问题

[[77. 组合]]
[[216. 组合总和 III]]  77上加了一个和的条件
[[39. 组合总和]] 可以重复选 
[[40. 组合总和 II]] 有重复元素 

去重一 子集和组合适用
~~~go
//有重复元素  去重
if i>startIndex&&nums[i]==nums[i-1]{
	continue
}
~~~

[[78. 子集]]
[[90. 子集 II]]有重复元素

去重二 子集、组合、排列适用

~~~go
        if i>0 && used[i-1]==false &&nums[i]==nums[i-1]{
            continue
        }
        if used[i]{
            continue
        }
		track =append(track,nums[i])
        used[i]=true
		backtack(nums,i+1,used)
        used[i]=false
~~~

[[46. 全排列]] 
[[47. 全排列 II]]
排列没有startindex


#### 进阶
[131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)
[93. 复原 IP 地址](https://leetcode-cn.com/problems/restore-ip-addresses/)
[491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/)
[332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)

[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)  回溯超时用背包



51.N皇后
37. 解数独


### DFS
[[22. 括号生成]]

#### 字典树加回溯

[211. 添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/)

[212. 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)

#### 二维数组DFS问题

[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

[剑指 Offer 12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)

[剑指 Offer 13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)

