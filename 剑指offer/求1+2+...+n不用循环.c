int sum(int n){
	int num = n;
while(num){
	num = num + sum(n-1);
}

	return num;
}