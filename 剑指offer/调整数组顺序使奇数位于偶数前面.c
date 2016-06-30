#include<iostream>
using namespace std;

void Recoder(int *Data,unsigned int length)
{
	int *p_begin = Data;
	int *p_end = Data+length-1;

	while(p_begin<p_end){
		while(p_begin<p_end && *p_begin % 2 == 1)
		{
			p_begin++;
		}

		while(p_begin<p_end && *p_end % 2 == 0){
		p_end--;
		}

		int temp = *p_begin;
			*p_begin = *p_end;
			*p_end = temp;
	}
}



int main(int argc, char const *argv[])
{
	int num[] = {1,3,4,6,2,8,5,7,10,9};

	Recoder(num,10);
	for(int i=0;i<10;i++)
	{
	cout<<num[i]<<",";
	}
	system("pause");
}

