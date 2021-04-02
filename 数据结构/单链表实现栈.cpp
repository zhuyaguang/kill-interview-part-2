#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class MyData  
{  
public:  
    MyData() : data(0), next(NULL){}      //默认构造函数  
    MyData(int value) : data(value), next(NULL){}  //带参数的构造函数  
    int data;               //数据域  
    MyData *next;           //下一个节点  
};  
  
class MyStack  
{  
public:  
    MyStack() : top(NULL) {}    //默认构造函数  
    void push(MyData data);     //进栈  
    void pop(MyData *pData);    //出栈  
    bool IsEmpty();             //是否为空  
    MyData *top;                //栈顶  
};  

void MyStack::push(MyData data)  
{  
    MyData *pData = NULL;  
    pData = new MyData(data.data);  //生成新节点  
    pData->next = top;               //与原来的栈顶节点相连  
    top = pData;                    //栈顶节点为新加入的节点  
}  
  
void MyStack::pop(MyData *data)  
{  
    if(IsEmpty())               //判空  
    {  
        return;  
    }  
    data->data = top->data;  
	//给传出的参数赋值  
    MyData *p = top;            //临时保存原栈顶节点  
    top = top->next;         //移动栈顶，指向下一个节点  
    delete p;                   //释放原栈顶节点内存  
}  
  
bool MyStack::IsEmpty()  
{  
    return (NULL == top);    //如果top为空返回1，否则返回0  
}  
void main()
{
	MyData data(0);  
    MyStack s;  
    s.push(MyData(1));  //进栈  
    s.push(MyData(2));  
    s.push(MyData(3));  
  
    s.pop(&data);       //出栈  
    cout<<"pop "<<data.data<<endl;  
    s.pop(&data);  
    cout<<"pop "<<data.data<<endl;  
    s.pop(&data);  
    cout<<"pop "<<data.data<<endl;  
    cout<<"Empty = "<<s.IsEmpty()<<endl;  
 system("pause");
}