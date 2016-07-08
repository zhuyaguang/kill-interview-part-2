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