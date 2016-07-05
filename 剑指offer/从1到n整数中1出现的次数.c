int find_1_num(int n){
for (int i = 1; i < n; ++i)
{
	int count = 0;

	while(i){
		if (i % 10 == 1)
		{
			count++;
		}
		i = i/10;
	}


}

return count;
}