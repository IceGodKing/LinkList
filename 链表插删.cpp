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

void LL_InsAt(LinkList L,int i,ElemType e)
// 在带头结点的单链表L中第i个位置插入值为e的新元素，i的取值范围[1,n+1]
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
	LNode *p,*s;
	p=L;
	int j=0;
	while(p&&j<i-1)
	{
	p=p->next;
	j++;
	}
    if(p&&j<i)   
    {  
    s=(LNode *)malloc(sizeof(LNode)); 
    s->data=e; 
    s->next=p->next; p->next=s;
    }  
	/********** End **********/
}

void LL_DelAt(LinkList L,int i)
// 在带头结点的单链表L中，删除第i个元素，i的取值范围[1,n]
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
	LNode *p,*s;
	int j=0;
	p=L;
	while(p->next&&j<i-1)
	{
		p=p->next;
		j++;
	}
    if((p->next)&&j<i) 
    {  
   s=p->next; p->next=s->next; free(s);
    }  
	/********** End **********/
}

void LL_DelValue(LinkList L, ElemType e)
// 删除第一个值为e的数据元素
{
	// 请在这里补充代码，完成本关任务
    /********** Begin *********/
	LNode *p,*s;
	p=L->next;
	s=L;
	while(p&&p->data!=e)
	{
		p=p->next;
		s=s->next;
	}
	if(p)
	{
		s->next=p->next;
		free(p);
	}

	/********** End **********/
}











另一种方法。答案 ： 
 void LL_InsAt(LinkList L,int i,ElemType e)  
// 在带头结点的单链表L中第i个位置插入值为e的新元素，i的取值范围[1,n+1]  
{  
    // 请在这里补充代码，完成本关任务  
    /********** Begin *********/  
    LNode *p,*s; int j;  
    p=L;j=0;   
    while(p&&j<i-1)//查找第i-1个结点，p指向该结点  
    {  
        p=p->next;++j;  
    }  
    if(!p||j>i-1)    //i>n+1或者i<1，i值不合法  
    {  
        printf("LL_InsAt(): The value of 'i' is not in the range [1,n+1].\n"); return;  
    }  
    s=(LNode *)malloc(sizeof(LNode)); //生成新结点s  
    s->data=e; //将结点s的数据域置为e  
    s->next=p->next; p->next=s;  //将结点s插入  
    /********** End **********/  
}
void LL_DelAt(LinkList L,int i)  
// 在带头结点的单链表L中，删除第i个元素，i的取值范围[1,n]  
{  
    // 请在这里补充代码，完成本关任务  
    /********** Begin *********/  
    LNode *p,*s; int j;  
    p=L;j=0;   
    while(p->next &&j<i-1)//查找第i-1个结点，p指向该结点  
    {  
        p=p->next; ++j;   
    }   
    if(!(p->next)||j>i-1) //i>n或者i<1，i值不合法  
    {  
        printf("LL_DelAt(): The value of 'i' is not in the range [1,n].\n"); return;  
    }  
    s=p->next; p->next=s->next; free(s); //删除  
    /********** End **********/  
}
void LL_DelValue(LinkList L, ElemType e)  
// 删除第一个值为e的数据元素  
{  
    // 请在这里补充代码，完成本关任务  
    /********** Begin *********/  
    LNode *p,*q;  
    p=L->next; q=L; //q指向p所指结点的前驱结点  
    while(p&&p->data!=e)  
    {  
        p=p->next; q=q->next;  
    }  
    if(p)//找到值为e的元素          
    {  
        q->next=p->next; free(p); //删除p所指结点  
    }  
    /********** End **********/  
}
