### Heap、堆、优先队列

* [堆的介绍](https://www.cnblogs.com/wangchaowei/p/8288216.html)

* 求前 k 大，用小根堆，求前 k 小，用大根堆。

* 大根堆Less函数 > ,小根堆为<,默认为小根堆

  ```go
  func (h *heapInt)Less(i,j int)bool {return h.IntSlice[i]>h.IntSlice[j]}
  ```

* Push 函数和Pop函数必不可少，Less、Swap、Len自定义堆元素时需要改写

经典例题

1. [剑指 Offer 40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

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
   // > 就是大根堆，golang默认是小根堆
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

   

2. [414. 第三大的数](https://leetcode-cn.com/problems/third-maximum-number/) 

   ```go
   func thirdMax(nums []int) int {
   	if len(nums) == 1 {
   		return nums[0]
   	}
   	if len(nums) == 2 {
   		if nums[0] >= nums[1] {
   			return nums[0]
   		}
   
   		return nums[1]
   	}
   	nMap:=make(map[int]int)
   	for _,v:=range nums{
   		nMap[v]++
   	}
   
   	// 建堆，小根堆
   	d := &heapInt{}
   	max := math.MinInt32
   	for key := range nMap {
   		heap.Push(d, key)
   		if d.Len() > 3 {
   			heap.Pop(d)
   		}
   		if key > max {
   			max = key
   		}
   	}
   	fmt.Println(d.IntSlice,max)
   	if d.Len() < 3 {
   		return max
   	}
   	return heap.Pop(d).(int)
   }
   
   type heapInt struct {
   	sort.IntSlice
   }
   
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

   

3. [703. 数据流中的第 K 大元素](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)  

   ```go
   type KthLargest struct {
       sort.IntSlice
       k int
   }
   
   func Constructor(k int, nums []int) KthLargest {
       kl := KthLargest{k: k}
       for _, val := range nums {
           kl.Add(val)
       }
       return kl
   }
   
   func (kl *KthLargest) Push(v interface{}) {
       kl.IntSlice = append(kl.IntSlice, v.(int))
   }
   
   func (kl *KthLargest) Pop() interface{} {
       a := kl.IntSlice
       v := a[len(a)-1]
       kl.IntSlice = a[:len(a)-1]
       return v
   }
   // 小根堆 取堆顶 下面都比堆顶大，所以是小根堆
   func (kl *KthLargest) Add(val int) int {
       heap.Push(kl, val)
       if kl.Len() > kl.k {
           heap.Pop(kl)
       }
       return kl.IntSlice[0]
   }
   ```

   

4. [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

   ```go
   // 小根堆 取堆顶 下面都比堆顶大，所以是小根堆
   func findKthLargest(nums []int, k int) int {
   	 d := &heapInt{}
   	index:=0
   	for index<len(nums){
   		if index<k{
   			heap.Push(d,nums[index])
   
   		}else{
   			if nums[index]>d.Peek(){
   				heap.Pop(d)
   				heap.Push(d,nums[index])
   			}
   		}
   		index++
   	}
   
   
   	return d.IntSlice[0]
   
   }
   
   type heapInt struct {
   	sort.IntSlice
   }
   
   
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

   

5. [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

   ```go
   // 构造一个小根堆 堆元素为一个两位数组，比较数组的第二个数字 改写Less函数
   func topKFrequent(nums []int, k int) []int {
   
   	nMap := make(map[int]int)
   	hi:=heapInt{}
   	for _, v := range nums {
   		nMap[v]++
   	}
   	for key,v:=range nMap{
   		  heap.Push(&hi,[2]int{key,v})
   		  if len(hi)>k{
   			  heap.Pop(&hi)
   		  }
   	}
   	result:=[]int{}
   	lenk:=0
   	for lenk<k{
   		tmp:=hi.Pop().([2]int)[0]
   		result=append(result, tmp)
   		lenk++
   	}
   	return result
   
   }
   
   type heapInt [][2]int
   
   func (h heapInt)Len() int {
   	return len(h)
   }
   
   func (h heapInt)Less(i,j int)bool{
   	return h[i][1]<h[j][1]
   }
   
   func (h heapInt)Swap(i,j int){
           h[i],h[j]=h[j],h[i]
   }
   
   func (h *heapInt)Push(x interface{} ){
          *h=append(*h, (x).([2]int))
   } 
   func (h *heapInt)Pop()(x interface{}){
   		 t:=*h
   		 x=t[len(t)-1]
   		*h=t[:len(t)-1]
   		 return x
   }
     
   ```

   

6. [692. 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/) 

   ```go
   func topKFrequent(words []string, k int) []string {
   	nMap := make(map[string]int)
   	for _, v := range words {
   		nMap[v]++
   	}
   	hi := &heapInt{}
   	heap.Init(hi)
   	for key, v := range nMap {
   		heap.Push(hi, &wordHeap{key, v})
   		if hi.Len() > k {
   			heap.Pop(hi)//注意heap.pop与 hi.pop手误写错
   		}
   	}
   
       result := make([]string, k)
   	for i := 0; i < k; i++ {
   		result[k-i-1] = heap.Pop(hi).(*wordHeap).word
   	}
   	return result
   }
   
   type wordHeap struct {
   	word string
   	time int
   }
   
   type heapInt []*wordHeap
   
   func (h heapInt) Len() int {
   	return len(h)
   }
   
   func (h heapInt) Less(i, j int) bool {
   	if h[i].time == h[j].time {
   		return h[i].word > h[j].word
   	}
   	return h[i].time < h[j].time
   }
   
   func (h heapInt) Swap(i, j int) {
   	h[i], h[j] = h[j], h[i]
   }
   
   func (h *heapInt) Push(x interface{}) {
   	*h = append(*h, (x).(*wordHeap))
   }
   func (h *heapInt) Pop() (x interface{}) {
   	t := *h
   	x = t[len(t)-1]
   	*h = t[:len(t)-1]
   	return x
   }
   ```

   

7. #### [480. 滑动窗口中位数](https://leetcode-cn.com/problems/sliding-window-median/)

8. #### [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

9. #### [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

10. #### [295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)

