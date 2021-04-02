### 快速排序

```go
// 快速排序
func main() {
	var  n int
	fmt.Scanln(&n)
	maxt := make([]int, n)

	for i := 0; i < n; i++ {
			fmt.Scan(&maxt[i])
	}
	//maxt:=[]int{1,2,3,4,5}
	fmt.Println(maxt)
	quickSort(maxt,0,n-1)
	fmt.Println(maxt)



}

func quickSort(nums []int,l,r int)  {
	if l>=r{
		return
	}
	p:=nums[(l+r)>>1]
	i:=l-1
	j:=r+1

	for i<j{
           for {
           	i++
           	if nums[i]>=p{
           		break
			}
		   }
		for {
			j--
			if nums[j]<=p{
				break
			}
		}
		if i<j{
			nums[i],nums[j]=nums[j],nums[i]
		}
	}
	quickSort(nums,l,j)
	quickSort(nums,j+1,r)

}
```

