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