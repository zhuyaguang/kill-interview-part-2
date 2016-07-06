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