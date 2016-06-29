//我的解法

long long Fibonacci(int n){
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;

	return Fibonacci(n-1)+Fibonacci(n-2);

}


//大神的解法 C++动态规划

 int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n--) {
            g += f;
            f = g - f;
        }
        return f;
    }

int main()
{
	
	
	cout<<Fibonacci(4);
	
	system("pause");
}
