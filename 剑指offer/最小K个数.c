//冒泡排序，只排前K个数

public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
	ArrayList<Integer> ret = new ArrayList<Integer>();

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < input.length-i-1; ++j)
		{
			if (j[i+1]>j[i])
			{
				int temp = j[i+1];
				j[i+1] = j[i];
				j[i] = temp;
			}

			ret.add(input[input.length-i-1]);
		}
	}

	return ret;
}