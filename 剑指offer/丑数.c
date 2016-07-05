
bool isUgly(int number){
	while (number % 2 == 0)
	{
		number = number / 2;
	}

	while (number % 3 == 0)
	{
		number = number / 3;
	}

	while (number % 5 == 0)
	{
		number = number / 5;
	}

	if (number == 1)
	{
		return true;
	}else {
		return false;
	}
}

int getTheUgly(int index){
	if (index <= 0)
	{
		return 0;
	}

	int count = 0;
	int number = 0
	while(count < index){
		if (isUgly(number))
		{
			count++;
		}

		number++;
	}

	return number;
}