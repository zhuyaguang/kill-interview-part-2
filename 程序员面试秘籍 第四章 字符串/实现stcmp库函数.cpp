#include<iostream>
using namespace std;
int mystrcmp(const char *src, const char *dst)
{
	int ret = 0;
	while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
	{
		++src;
		++dst;
	}
	if(ret < 0)
	{
		ret = -1;
	}else if(ret > 0)
	{
		ret =1;
	}
	return (ret);
}
int main()
{
	cout<<mystrcmp("123","124");
	system("pause");
}