#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
 struct LNode 
{
	int data;
	struct LNode *next;
};

 LNode *creat(int n)
{
	int i;
	LNode *head,*p1,*p2;
	head = ( LNode*)malloc(sizeof( LNode));
	head->next = NULL;
	int x;
	for( i = 1;i<=n;i++)
	{
		
		p1 = ( LNode*)malloc(sizeof( LNode));
		cout<<"请输入链表中第"<<i<<"个数：";
		cin>>x;
		p1->data = x;

		if(head->next == NULL)
				{
					head->next = p1;
					p2 =p1;
				}
			else
				{
					p2->next =p1;
					p2 = p1;
				}

			p2->next = NULL;
	}
	return head;
}
void print( LNode *q)
{
	LNode *p = q->next;
	while(p !=NULL)
	{
		cout<<p->data;
		p = p->next;
	}
}
int len(LNode *q)
{
	LNode *p = q->next;
	int lennode =0;
	while(p !=NULL)
	{
		lennode++;
		p = p->next;
	}
	return lennode;
}
int find(LNode *q,int src)
{
	LNode *p = q->next;
	int index =0;
	int cout = 0;
	while(p!=NULL)
	{
		if(p->data == src)
			 index =1;
		p = p->next;
		cout++;
	}
	return index;
}
LNode *insert(LNode *head,int pos,int data)
{
	LNode *temp = NULL;
	LNode *p=head;
	temp =(LNode *)malloc(sizeof(LNode));
	temp->data = data;
	if(pos == 0)
	{
		head->next = temp;
		return head;
	}
	while(--pos)
	{
		p=p->next;
	}
	if(p->next ==NULL)
	{
		p->next = temp;
	}else if(p !=NULL)
	{
		temp->next = p->next;
		p->next = temp;
	}
	return head;
}
LNode *reverse(LNode *head)
{
	LNode *p,*q,*r;
	if(head->next == NULL)
	{
		return head;
	}
	p = head->next;
	q = p->next;
	p->next = NULL;
	while(q!=NULL)
	{
		r = q ->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next =p;
	return head;
}
LNode *merge(LNode *head1,LNode *head2)
{	
	
	LNode *head= NULL;
	if(head1 ==NULL)
	{
		return head2;
	}
	if(head2 ==NULL)
	{
		return head1;
	}
	if(head1->data < head2->data)
	{
		head = head1;
		head->next = merge(head1->next,head2);
	}else
	{
		head = head2;
		head->next = merge(head1,head2->next);
	}
	return head;
}
int  main()
{
	int n;
	 LNode *q;
	cout<<"请输入链表的长度：";
	cin>>n;
	q = creat(n);
	cout<<"创建的链表为：";
	print(q);
	cout<<endl;
	cout<<"创建的链表长度为：";
	cout<<len(q)<<endl;
	cout<<"请输入查找的数字：";
	int src ;
	cin>>src;
	cout<<find(q,src)<<endl;
	cout<<"逆序链表：";
	LNode *insert_node = reverse(q);
	print(insert_node);
	cout<<endl;
	cout<<"插入链表：";
	int inset_num;
	cin>>inset_num;
	LNode *insert_node1 = insert(q,2,inset_num);
	print(insert_node1);
	cout<<endl;
	LNode *q2;
	LNode *q4;
	q2= creat(3);
	q4= creat(3);
	cout<<endl;
	LNode *q3;
	cout<<"合并的链表：";
	q3 = merge(q2,q4);
	print(q3->next);
	system("pause");
	
}