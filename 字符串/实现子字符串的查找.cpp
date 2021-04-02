#include<iostream>
#include<assert.h>
using namespace std;
int index(char *src,char *sub)
{
	int i=0;
	int j=0;
	while(src[i+j] !='\0' && sub[j] !='\0')
	{
		if(src[i+j] == sub[j])
		{
			j++;
		}else
		{
			i++;
			j=0;
		}
	}
	if(sub[j] == '\0')
	{
		return i;
	}else return -1;
}
int main()
{
	char *a="ididndijfser ci";
	char b[4]="idn";
	int index1 = index(a,b);
	
	cout<<index1<<endl;
	system("pause");
}