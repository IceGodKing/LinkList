#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void LL_Initiate(LinkList &L)
//单链表的初始化，即：构造一个带头结点的空的单链表
{
	L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
} 

void LL_Free(LinkList &L)
// 释放链表中各个结点。
{
	LinkList p;
	while(L)
	{
		p=L;
		L=L->next;
		free(p);
	}
}

bool LL_IsEmpty(LinkList L)
// 判断链表是否为空。
{
    return L->next==NULL;
}

void LL_Create_H(LinkList &L,int n)
// 输入n个数据元素，采用头插法，创建一个带头结点的单链表L。
{
	LNode *s; int i;
	L=(LNode *)malloc(sizeof(LNode));	L->next=NULL; //建立一个带头结点的空链表
	for(i=0;i<n;i++)
	{
		s=(LNode *)malloc(sizeof(LNode)); //生成新结点
		scanf("%d", &s->data); //输入元素值		
		s->next=L->next;   L->next=s;  //插入到表头			
	}
}

void LL_Create_R(LinkList &L,int n)
// 输入n个数据元素，采用尾插法，创建一个带头结点的单链表L。
{    
	LNode *r,*s; int i;
	L=(LNode *)malloc(sizeof(LNode));	L->next=NULL; //建立一个带头结点的空链表 
	r=L;  //尾指针r指向头结点
	for(i=0;i<n;i++)
	{
		s=(LNode *)malloc(sizeof(LNode)); //生成新结点
		scanf("%d", &s->data); //输入元素值		
		s->next=NULL; r->next=s; //插入到表尾 
		r=s;  //r指向新的尾结点		
	}	
}

void LL_Print(LinkList L)
// 输出整个线性表。
{
    LNode *p;
	p=L->next;
	while(p)
	{
		printf("%d  ",p->data); p=p->next;
	}
	printf("\n");
}

void LL_GetAt(LinkList L, int i, ElemType &e)
// 在带头结点的单链表L中获取第i个元素的值赋给e，i的取值范围[1,n]
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p&&j<=i)
		e=p->data;
	/********** End **********/
}

LNode *LL_FindValue(LinkList L, ElemType e,int &i)
//在带头结点的单链表L中查找第一个值为e的元素，
//找到则将该元素在链表中的位置赋给i，并返回该结点指针，否则i赋值为0并返回空指针
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p)
	{
		i=j;
	return p;	
	}
	else
	{
	i=0;
	return 0;	
	}
	
	/********** End **********/
}
