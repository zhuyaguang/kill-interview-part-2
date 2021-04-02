#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 class Node
 {
 public:
	 int data;
	 Node *parent;
	 Node *right;
	 Node *left;
 public:
	 Node():data(-1),parent(NULL),left(NULL),right(NULL){};
	 Node(int num):data(num),parent(NULL),left(NULL),right(NULL){};
 };
 class Tree
 {
 public:
	 Tree(int num[],int len);//创建二叉树，插入数组前len个数据
	 void insertNode1(int data);//二叉树 非递归插入节点

	 void insertNode(int data);//二叉树 递归插入节点
	 Node *searchNode(int data);//二叉树 递归查找节点
	 void deleteNode(int data);//二叉树 递归删除节点
	 void inOrderTreeUnrec();//非递归中序遍历
	 void preOrderTreeUnrec();//非递归先序遍历
	 void postOrderTreeUnrec();//非递归后序遍历
	 void inOrderTree();//递归中序遍历
	 void levelOrderTree();//层次遍历

 private:
	 void insertNode(Node *current,int data);//二叉树 递归插入节点
	 Node *searchNode(Node *current,int data);//二叉树 递归查找节点
	 void deleteNode(Node *current);//二叉树 递归删除节点
	 void inOrderTree(Node *current);//递归中序遍历
 private:
	 Node *root;
 };
 //创建树
 Tree::Tree(int num[],int len)
	 {
		 root = new Node(num[0]);
		 for(int i =1;i<len;i++)
		 {
			 insertNode1(i);
		 }
	 }
 //非递归插入
void Tree::insertNode1(int data)
{
	Node *p,*par;
	Node *newNode = new Node(data);
	p = par =root;
	while(p !=NULL)
	{
		par = p;
		if(data <p->data)
		{
			p = p->left;
		}else if(data >p->data)
		{
			p =p->right;
		}else if(data == p->data)
		{
			delete newNode;
			return ;
		}
		newNode ->parent = par;
		par->data>newNode->data? par->left = newNode:par->right = newNode;


	}
}
//递归插入
void Tree::insertNode(int data)
{
	if(root !=NULL)
	{
		insertNode(root,data);
	}
}
void Tree::insertNode(Node *current,int data)
{
	if(data<current->data)
	{
		if(current->left ==NULL)
		{
			current->left = new Node(data);
			current->left->parent = current;
		}else
			insertNode(current->left,data);

	}
	else if(data>current->data)
	{
		if(current->right ==NULL)
		{
			current->right = new Node(data);
			current->right->parent = current;
		}else
			insertNode(current->right,data);

	}

	return ;

}
//递归搜索
Node *searchNode(Node *current,int data)
{
	if(data <current->data)
	{
		if(current->left ==NULL)
			return NULL;
		return searchNode(current->left,data);
	}else if(data > current->data)
	{
		if(current->right ==NULL)
			return NULL;
		return searchNode(current->right,data);
	}
	return current ;

}
//递归删除
void Tree::deleteNode(int data)
{
	Node *current =NULL;
	current = searchNode(data);
	if(current != NULL)
	{
		deleteNode(current);
	}
}
void Tree::deleteNode(Node *current)
{
	if(current->left ==NULL)
	{
		deleteNode(current->left);
	}
	if(current->right ==NULL)
	{
		deleteNode(current->right);
	}
	if(current ->parent == NULL)
	{
		delete current;
		root =NULL;
		return;
	}
	if(current->data<current->parent->data)
	{
		current->left = NULL;

	}else
	{
		current->parent->right = NULL;
	}
	delete current;
}
//递归的中序遍历
void Tree::inOrderTree()
{
	if(root == NULL)
	{
		return ;
	}
	inOrderTree(root);
}
void Tree::inOrderTree(Node *current)
{
	if(current !=NULL)
	{
		inOrderTree(current->left);
		cout<<current->data<<" ";
		inOrderTree(current->right);
	}
}
//非递归中序遍历
void Tree::inOrderTreeUnrec()
{
	stack<Node *> s;
	Node *p =root;
	while(p!=NULL || !s.empty)
	{
		while(p !=NULL)
		{
			s.push(p);
			p = p->left;
		}

		if(!s.empty())
		{
			p = s.top;
			s.pop();
			cout<<p->data<<" ";
			p = p->right;
		}
	}
	
}
//非递归先序遍历
void Tree::preOrderTreeUnrec()
{
	stack<Node *> s;
	Node *p = root;
	while(p !=NULL || !s.empty)
	{
		while(p !=NULL)
		{
			cout<<p->data<<endl;
			s.push(p);
			p = p->left;
		}

		if(!s.empty)
		{
			p = s.top();
			s.pop();
			p =p->right;
		}
	}
	
}
//非递归后序遍历
void Tree::postOrderTreeUnrec()
{
	stack<Node *> s;
	Node *p = root;
	
	while(p!=NULL||!s.empty)
	{
		while(p!=NULL)
		{
			s.push(p);
			p= p->left;
		}
		if(!s.empty)
		{
			p =s.top();
			if(p->tag)
			{
				cout<<p->data<<endl;
				s.pop();
				p =NULL;//第二次访问说明其右子树已经遍历
			}else
			{
				p->tag = 1;
				p = p->right;
			}
		}
	}
}
//层次遍历
void Tree::levelOrderTree()
{
	queue<Node *> q;
	Node *p = NULL;
	
	q.push(root);
	while（!q.empty())
	{
		p = q.front();
		q.pop();
		cout<<p->data<<endl;

		if(p->left !=NULL)
		{
			q.push(p->left);
		}
		if(p->rirht !=NULL)
		{
			q.push(p->right);
		}
	}
}
void main()
{
	int num[] = {1,2,35,5,7,4,57,9,34};
	Tree tree(num,9);
	tree.inOrderTree();
	system("pause");
}