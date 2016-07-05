 // * 解题思路：
 // * 先将整型数组转换成String数组，然后将String数组排序，最后将排好序的字符串数组拼接出来。关键就是制定排序规则。
 // * 排序规则如下：
 // * 若ab > ba 则 a > b，
 // * 若ab < ba 则 a < b，
 // * 若ab = ba 则 a = b；
 // * 解释说明：
 // * 比如 "3" < "31"但是 "331" > "313"，所以要将二者拼接起来进行比较
static bool compare(const string str1,const string str2)
{
    string combined1,combined2;
    combined1=str1+str2;
    combined2=str2+str1;
    return combined1<combined2;
}
string PrintMinNumber(vector<int> numbers){
     
    vector<string> strvec;
    for (int i=0;i<numbers.size();i++)
    {
        string str;
        //stringstream由iostream派生而来
        stringstream ss;
        ss<<numbers[i];
        ss>>str;
        strvec.push_back(str); 
    }
 
    sort(strvec.begin(),strvec.end(),compare);
 
    string orderStr;
    for (int i=0;i<strvec.size();i++)
    {
        str.append(strvec[i]);
    }
    return orderStr;
 
}