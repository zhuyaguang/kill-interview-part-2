## 回溯、DFS、背包

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

* 子集 最通用的组合 
*  组合  满足一定条件的子集 
* 组合和子集都需要一个startindex 来排除索引之前的数字 
* 排列 需要通过contains方法判断是否排除track中已经选过的数字或者维护一个visit []bool 数组 
* 不管是子集组合还是排列，如果有重复都数字需要排序，然后都要判断下相邻是否相同 
* 组合不能解决超时了，就是背包问题

[78. 子集](https://leetcode-cn.com/problems/subsets/)

```go
// 子集
var result9 [][]int
var track9 []int
func subsets(nums []int) [][]int {
	result9=[][]int{}
	track9=[]int{}
	backtack(nums,0,track9)
	return result9
}
func backtack(nums []int,startIndex int,track []int)  {
	tmp:=make([]int,len(track))
	copy(tmp,track)
	result9 = append(result9,tmp)
	for i := startIndex; i <len(nums) ; i++ {
		track =append(track,nums[i])
		backtack(nums,i+1,track)
		track=track[:len(track)-1]
	}
}

// 子集含重复数字情况 排序➕去掉重复
var result9 [][]int
var track9 []int
func subsetsWithDup(nums []int) [][]int {
	result9=[][]int{}
	track9=[]int{}
    sort.Ints(nums)
	backtack(nums,0,track9)
	return result9
}
func backtack(nums []int,startIndex int,track []int)  {
	tmp:=make([]int,len(track))
	copy(tmp,track)
	result9 = append(result9,tmp)
	for i := startIndex; i <len(nums) ; i++ {
        if i>startIndex&&nums[i]==nums[i-1]{
            continue
        }
		track =append(track,nums[i])
		backtack(nums,i+1,track)
		track=track[:len(track)-1]
	}
}
```

#### 回溯

[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

[77.组合](https://leetcode-cn.com/problems/combinations/)

[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)

[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)

[216. 组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)

[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)  回溯超时用背包

[46. 全排列](https://leetcode-cn.com/problems/permutations/)

[47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

[剑指 Offer 38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)

[51.N皇后](https://www.notion.so/51-N-9e129f4fe1814e9c866bb4ad647f0371)

[22. 括号生成](https://www.notion.so/22-239b251b4a254b92a01b0167c56fa477)

#### 字典树加回溯

[211. 添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/)

[212. 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)

#### 二维数组DFS问题

[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

[剑指 Offer 12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)

[剑指 Offer 13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)

### [希望用一种规律搞定背包问题](https://leetcode-cn.com/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/)

* 背包问题具备的特征：给定一个target，target可以是数字也可以是字符串，再给定一个数组nums. nums中装的可能是数字，也可能是字符串，问：能否使用nums中的元素做各种排列组合得到target。 

* 常见的背包问题有:
  * 1、组合问题。
  * 2、True、False问题。
  * 3、最大最小问题. 

* 题目给的nums数组中的元素是否可以重复使用,来判断是0-1背包问题还是完全背包问题。 如果是组合问题，是否需要考虑元素之间的顺序。需要考虑顺序有顺序的解法，不需要考虑顺序又有对应的解法。

#### 1、组合问题：

[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)  回溯超时用背包

[494. 目标和](https://leetcode-cn.com/problems/target-sum/description/) 回溯超时用背包 01背包 

[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)  完全背包加组合

```go
组合问题公式
 dp[i] += dp[i-num]
```

#### 2、True、False问题：

[139. 单词拆分](https://leetcode-cn.com/problems/word-break/) 

[416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/) 01背包

```go
True、False问题公式
dp[i] = dp[i] or dp[i-num]
```

#### 3、最大最小问题： 

[474. 一和零](https://leetcode-cn.com/problems/ones-and-zeroes/) 

[322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 完全背包

```go
最大最小问题公式
dp[i] = min(dp[i], dp[i-num]+1)或者dp[i] = max(dp[i], dp[i-num]+1)
```

```go
如果是0-1背包，即数组中的元素不可重复使用，nums放在外循环，target在内循环，且内循环倒序；

0-1背包公式
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    }
}

如果是完全背包，即数组中的元素可重复使用，nums放在外循环，target在内循环。且内循环正序；


如果组合问题需考虑元素之间的顺序，需将target放在外循环，将nums放在内循环。
func combinationSum4(nums []int, target int) int {
    dp := make([]int, target+1)
    dp[0] = 1
    for i := 1; i <= target; i++ {
        for _, num := range nums {
            if num <= i {
                dp[i] += dp[i-num]
            }
        }
    }
    return dp[target]
}
```

