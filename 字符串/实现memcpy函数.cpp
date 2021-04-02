#include<iostream>
#include<assert.h>
using namespace std;
void *memcpy2(void *memTo,const void *memFrom,size_t size)
{
	assert((memTo != NULL) &&(memFrom != NULL));
	char *tempFrom = (char *)memFrom;
	char *tempTo = (char *)memTo;
	while(size-- > 0)
	{
		*tempTo++ = *tempFrom++;
	}
	return memTo;
	
}
int main()
{
	char strSrc[] = "hello world!";
	char strDest[20];
	strDest[4] = '\0';
	memcpy2(strDest,strSrc,4);
	cout<<strDest<<endl;
	system("pause");
}