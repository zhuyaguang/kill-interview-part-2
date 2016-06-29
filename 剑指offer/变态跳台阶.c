//规律是1,2,4,8,16……，就是2^n


int jumpFloor(int number){
	if (number == 1 || number == 2)
	{
		return number;
	}else {
		return 2 * jumpFloor(number-1);
	}
}


