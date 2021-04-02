#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
//普通逆序
char *reverse(char *str)
{
	//将q指向字符串最后一个字符
	char *p = str;
	while(*p++);
	p=p-2;
	 //分配空间，存储逆序后的字符串。
	char *q = new char[sizeof(char) * (p-str+2)];
	char *r=q;
	// 逆序存储
	while(p>=str)
	{
		*q++=*p--;
	}
	*q='\0';//没有结束标识符的话，会打印垃圾数据
	return r;
}
//原地逆序
char *reverse2(char *str)
{
	char *p = str;
	char *q =str;
	while(*q)
	{
		++q;
	}
	q--;

	while(q>p)
	{
		/*char t;
		 t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;*/

		/* char t = *p ;
        *p++ = *q ;
        *q-- = t ;*/

		swap(*p++,*q--);
	}
	return str;
}
//非递归逆序
char *reverse3(char *str,int left,int right)
{
	if(left >= right)
	{
		return str;
	}
	char t;
	t = str[left];
	str[left++] = str[right];
	str[right--] = t;
	return str;

}
//递归逆序
char *reverse4(char *str,int left,int right)
{
	if(left >= right)
	{
		return str;
	}
	char t;
	t = str[left];
	str[left] = str[right];
	str[right] = t;
	reverse4(str,left++,right--);

}
// 将句子按单词逆序
char* ReverseSentence(char *s)
{
    // 这两个指针用来确定一个单词的首尾边界
    char *start = s ;    // 指向单词的首字符
    char *end = s ;    // 指向空格或者 '\0'
	char *ptr =s;
    while(*ptr++ != '\0')
    {
        if (*ptr == ' '||*ptr =='\0')//最后一个单词为‘\0’
        {
			end = ptr-1;
			while(start < end)
            {
				swap(*start++, *end--) ;
			}
            start = end = ptr+1 ; // 指向下一个单词首字符
        }
       
    }
	//end = ptr-1;
 //   swap(*start++, *end--) ; // 对最后一个单词逆序
	start = s; end = ptr -2;
	while(start < end)
    {
		swap(*start++, *end--) ; // 对整个句子逆序
	}
    return s ;
}
//
void reversepart(char *str,int num)
{
	char *start =str;//头指针

	char *end2 =str;
	while(*end2++);
	end2 = end2 -2;//尾指针


	char *end1 =start+num-1;
	char *start2 =start+num;
	char *end3 = end2;
	while(start < end1)
	swap(*start++,*end1--);//前半段交换

	while(start2 < end3)
	swap(*start2++,*end3--);//后半段交换
	
	start = str;
	while(start < end2)
	swap(*start++,*end2--);//整体交换

}
int main()
{
	//char *a="ididndijfser cl";
	char a[]="123456789";
	cout<<a<<endl;
	//int len = strlen(a);
	/*cout<<len<<endl;*/
	//cout<<reverse(a)<<endl;
	//cout<<reverse2(a)<<endl;
	/*reverse_word(a);*/
	/*cout<<reverse3(a,0,len)<<endl;*/
	/*cout<<ReverseSentence(a)<<endl;*/
	reversepart(a,3);
	cout<<a;
	system("pause");
}