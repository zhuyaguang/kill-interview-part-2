## 剑指offer汇总

### 1.二维数组中的查找

> 我的暴力方法，双重循环查找

```c++
#include<iostream>
using namespace std;

int main()
{
	
	int num[4][4] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int tar;
	cin>>tar;
	int flag = 0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(num[i][j]==tar)
			{
				flag = 1;
				break;
			}
		}
		cout<<flag;
		system("pause");
 }
```

### 2.替换空格

> 同样是我的方法，利用了sstream

```c++
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<string> a;
    string s;
    getline(cin,s);
    
    for (int i = 0; i<s.length(); i++) {
        stringstream stream;
        stream << s[i];
        string tep = stream.str();
        a.push_back(tep);
    }
    
    
    int len = int(a.size()-1);
    
    for (int  i = 0; i<len; i++) {
        if(a[i] == " ")
        {
            a[i] = "%20";
        }
    }
    
     for (int  i = 0; i<=len; i++) {
         cout<<a[i];
     }
    
    return 0;
}
```

### 3.从尾到头打印链表

