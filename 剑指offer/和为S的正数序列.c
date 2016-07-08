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

