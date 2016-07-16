#include<iostream>
using namespace std;
int tail_num_0(int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j % 5 == 0)
		{
			count++;
			j=j/5;
		}
	}
	return count;
}
void main()
{
	cout<<tail_num_0(10)<<endl;
	system("pause");
}

//
#include<iostream>
using namespace std;

int numofzero(int num)
{
    int count = 0;
    while (num) {
        if (num % 5 ==0) {
            count++;
            
        }
        num = num /5 ;
    }
    
    return count;
}

int jie(int num)
{
    if (num == 0) {
        return 1;
    }
    return num * jie(num -1 );
}
int main(){
   
    int num;
    cin>>num;
    
    cout<<numofzero(jie(num));

}
