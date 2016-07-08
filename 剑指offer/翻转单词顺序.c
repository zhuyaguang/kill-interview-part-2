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