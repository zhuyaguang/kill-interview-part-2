#include<iostream>
using namespace std;
int find(int a[],int N)
{
	int dst =0;
	int Ntimes = 0;
	for(int i=0;i<N;i++)
	{
		if(Ntimes == 0)
		{
			dst = a[i];
			Ntimes =1;
		}
		if(dst == a[i])
		{
			Ntimes++;
		}else
		{
			Ntimes--;
		}
	}
	return dst;
}
void main()
{
	int num[]={1,2,3,1,3,4,5,1,1,1,3,1,1,1,1};
	cout<<find(num,15)<<endl;
	system("pause");
}
// 我的另一种方法
#include <iostream>
using namespace std;

int main(){
    int num[13]={1,2,3,4,4,4,4,4,4,4,5,6,7};
    
    int index[10]={0};
    
    for (int i = 0; i<13; i++) {
        index[num[i]]++;
    }
    
    for (int i = 0; i<10; i++) {
        if (index[i] > 13 /2 ) {
            cout<<i;
        }
    }
}
