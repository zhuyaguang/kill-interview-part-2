//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1]
//其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。
 vector<int> multiply(const vector<int>& A) {

 	int n = A.size();

 	vector<int> b(n);

 	int ret = 1;
 	b[0] = 1;

 	for (int i = 0; i < n; ++i)
 	{
 		b[i] = b[i-1] * A[i-1];
 	}

 	for (int i = n-1; i >=1; i--)
 	{
 		b[i] = b[i]*b[0];

 		b[0] = b[0] *a[i];
 	}

 	return B; 
 }