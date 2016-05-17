#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ListSize 100

 struct ListNode
{
 int data;
 struct ListNode *next; 
};


void Josephus(ListNode *head, int n, int m, int k)
{
 ListNode *p,*q;
 int i;
 p=head;
 /*先找到编号为k的人*/
 for(i=1; i<k; i++)/*从第k个人开始报数*/
  {
   q=p;
   p=p->next;
  }
 /*此时p指向第k个结点*/
 
 while(p->next != p)/*这个是判断是否只剩下一个结点*/
  {
  /*找出报数m的人*/
   for(i=1; i<m; i++)/*数到m的人出列*/
    {
     q=p;
     p=p->next;
    }
   /*此时p指向数到m的结点*/
   /*此时q指向的是m的前驱结点，p指向的是第m个结点*/
   
   q->next = p->next;/*这步就是将m的前驱结点指针域指向
   m的后继结点*/
   printf("%4d",p->data);/*打印出出列的数据*/
   free(p);/*释放出列的结点空间*/
   p=q->next;/*指向下一个结点，重新开始报数*/
  }
 printf("%4d\n", p->data);
 
}
 
/*//////////////////////////////////////////////////////////////////////////////
函数名:       CreateCycList
函数功能:   宏定义和单链表定义
入口参数: int n
出口参数: 
//////////////////////////////////////////////////////////////////////////////*/
ListNode *CreateCycList(int n)
{
 ListNode *head = NULL;
 ListNode *s, *r;
 int i;
 for(i = 1; i <= n; i ++ )
  {
   s = (ListNode *)malloc(sizeof(ListNode));
   s->data = i;
   s->next = NULL;
   if(head == NULL)
    head = s;
   else
    r->next = s;/*本节点指针域指向下一个结点*/
   r = s;/*临时指针指向下一个结点*/
  }
 r->next = head;/*最后一个结点的指针域指向头结点形成环*/
 return head;/*返回头结点的地址*/
}
/*//////////////////////////////////////////////////////////////////////////////
函数名:       main()
函数功能:   主函数
入口参数: 
出口参数: 
//////////////////////////////////////////////////////////////////////////////*/
void main()
{
 ListNode *h;
 int n,k,m;
 printf("输入环中人的个数n=");
 scanf("%d", & n);
 printf("输入开始报数的序号k=");
 scanf("%d", & k);
 printf("报数为m的人出列m=");
 scanf("%d", & m);
 h=CreateCycList(n);
 Josephus(h, n, m, k);
 system("pause");
}