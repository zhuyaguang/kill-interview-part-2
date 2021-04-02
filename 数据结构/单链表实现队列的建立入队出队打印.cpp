#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct myQueue
{
	node *front;
	node *rear;
};
myQueue *createQueue()
{
	myQueue *q=(myQueue *)malloc(sizeof(myQueue));
	q->front = NULL;
	q->rear =NULL;
	return q;
}
myQueue *enQueue(myQueue *q,int data)
{
	node *newp =NULL;
	newp = (node *)malloc(sizeof(node));
	newp->data =data;
	newp->next = NULL;
	if(q->rear =NULL)
	{
		q->front = q->rear = newp;
	}else
	{
		q->rear->next = newp;
		q->rear = newp;
	}
	return q;
}
myQueue *deQueue(myQueue *q)
{
	node *newp =NULL;
	newp = q->front;
	if(newp ==NULL)
	{
		printf("队列是空的\n");
	}
	else
	{
		q->front = q->front->next;
		if(q->front == NULL)
		{
			q->rear = NULL;
		}
		free(newp);
	}
	return q;
}
int len(myQueue *q)
{
	int qlen = 0;
	node *newp = q->front;
	while(newp != q->rear)
	{
		newp =newp->next;
		qlen++;
	}
	return qlen;
}
void printQueue(myQueue *q)
{
	node *newp =q->front;
	printf("data:");
	while(newp!=q->rear)
	{
		printf("%d ",newp->data);
		newp = newp->next;
	}
	printf("%d",newp->data);
}
void main()
{
	myQueue *hp = createQueue();
	enQueue(hp,1);
	enQueue(hp,2);
	enQueue(hp,3);
	enQueue(hp,4);
	enQueue(hp,5);
	int nlen = 0;
	nlen = len(hp);
	printf("队列长度为：%d",nlen);
	printQueue(hp);
	deQueue(hp);
	deQueue(hp);
	nlen = len(hp);
	printf("队列长度为：%d",nlen);
	printQueue(hp);
 system("pause");
}