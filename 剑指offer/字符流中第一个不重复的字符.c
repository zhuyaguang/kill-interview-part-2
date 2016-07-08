//请实现一个函数用来找出字符流中第一个只出现一次的字符。
//例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

int [] occurence = new int[256];

int index = 0;

	public Solution(){
		for (int i = 0; i < 256; ++i)
		{
			occurence[i] = -1;
		}
	}
//Insert one char from stringstream
    void Insert(char ch)
    {
         if (occurence[ch] == -1)
         {
         	occurence[ch] = index;
         }else if (occurence[i] > 0)
         {
         		occurence[ch] = -2;
         }
         index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	char ch = " ";
    	for (int i = 0; i < 256; ++i)
    	{
    		if (occurence[i] > 0)
    		{
    			ch = (char)i;
    		}
    	}
    	if (ch = " ")
    	{
    		return '#';
    	}else return ch;
    }