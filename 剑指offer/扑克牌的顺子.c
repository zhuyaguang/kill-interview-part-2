bool isContinuous(int *numbers,int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers);

	int numberofzero = 0;
	int numberofgap =0;

	for (int i = 0; i < length && numbers[i] == 0; ++i)
	{
		numberofzero++;
	}

	int small = numberofzero;
	int big = small+1;
	while(big < length){
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberofgap += numbers[big] - numbers[small] -1;
		small = big;
		big++;
	}

	return numberofgap > numberofzero ? false :true;
}