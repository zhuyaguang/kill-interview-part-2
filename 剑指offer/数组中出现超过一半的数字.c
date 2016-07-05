

int findTheNumber(vector<int> numbers){
	int length = numbers.size();

	int num = numbers[0]; count = 1;

	for (int i = 1; i < length; ++i)
	{
		if (numbers[i] == num)
		{
			count++;
		}else {
			count--;

			if (count == 0)
		{
			num = numbers[i];
			count = 1;
		}

		}


	}

	count = 0;

	for (int i = 0; i < length; q)
	{
		if (numbers[i] == numbers)
		{
			count++;
		}
	}

	if (count >= n / 2 )
	{
		return num;
	}
}