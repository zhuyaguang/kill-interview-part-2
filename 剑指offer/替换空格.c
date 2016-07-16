 void replaceSpace(char *str,int length) {
        int oldstrlength =0;
        int space_number =0;
        int i=0;
        while(str[i]!='\0')
            {
            oldstrlength++;
            if(str[i]==' ')
                {
                space_number++;
            }
            i++;
        }
        int newstrlength = oldstrlength+space_number*2;
        while(oldstrlength>=0)
            {
            if(str[oldstrlength] ==' ')
                {
                str[newstrlength--]='0';
                str[newstrlength--]='2';
                str[newstrlength--]='%';
            }else
                {
                str[newstrlength--]=str[oldstrlength];
            }
            oldstrlength--;
        }
         
    }
    
    
    //my solution
    
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
