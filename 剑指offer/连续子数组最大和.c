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
