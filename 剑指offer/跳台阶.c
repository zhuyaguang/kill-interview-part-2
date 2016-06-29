int jumpFloor(int number){
	if (number == 1 || number == 2)
	{
		return number;
	}else {
		return jumpFloor(number-1)+jumpFloor(number-2);
	}
}


//不用递归，用迭代

int jumpFloor1(int number){
	if (number == 1 || number == 2)
	{
		return number;
	}
	int jumFib = 0;
	int N1 = 2;
	int N2 = 1;
	for (int i = 3; i < number; ++i)
	{
		jumFib = N1 + N2;
		N2 = N1;
		N1 = jumFib;
	}
	return jumFib;

}