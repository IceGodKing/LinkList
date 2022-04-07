#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void LL_Initiate(LinkList &L)
//������ĳ�ʼ������������һ����ͷ���Ŀյĵ�����
{
	L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
} 

void LL_Free(LinkList &L)
// �ͷ������и�����㡣
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
// �ж������Ƿ�Ϊ�ա�
{
    return L->next==NULL;
}

void LL_Create_H(LinkList &L,int n)
// ����n������Ԫ�أ�����ͷ�巨������һ����ͷ���ĵ�����L��
{
	LNode *s; int i;
	L=(LNode *)malloc(sizeof(LNode));	L->next=NULL; //����һ����ͷ���Ŀ�����
	for(i=0;i<n;i++)
	{
		s=(LNode *)malloc(sizeof(LNode)); //�����½��
		scanf("%d", &s->data); //����Ԫ��ֵ		
		s->next=L->next;   L->next=s;  //���뵽��ͷ			
	}
}

void LL_Create_R(LinkList &L,int n)
// ����n������Ԫ�أ�����β�巨������һ����ͷ���ĵ�����L��
{    
	LNode *r,*s; int i;
	L=(LNode *)malloc(sizeof(LNode));	L->next=NULL; //����һ����ͷ���Ŀ����� 
	r=L;  //βָ��rָ��ͷ���
	for(i=0;i<n;i++)
	{
		s=(LNode *)malloc(sizeof(LNode)); //�����½��
		scanf("%d", &s->data); //����Ԫ��ֵ		
		s->next=NULL; r->next=s; //���뵽��β 
		r=s;  //rָ���µ�β���		
	}	
}

void LL_Print(LinkList L)
// ����������Ա�
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
// �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe����Ԫ�أ�i��ȡֵ��Χ[1,n+1]
{
	// �������ﲹ����룬��ɱ�������
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
// �ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�i��ȡֵ��Χ[1,n]
{
	// �������ﲹ����룬��ɱ�������
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
// ɾ����һ��ֵΪe������Ԫ��
{
	// �������ﲹ����룬��ɱ�������
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











��һ�ַ������� �� 
 void LL_InsAt(LinkList L,int i,ElemType e)  
// �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe����Ԫ�أ�i��ȡֵ��Χ[1,n+1]  
{  
    // �������ﲹ����룬��ɱ�������  
    /********** Begin *********/  
    LNode *p,*s; int j;  
    p=L;j=0;   
    while(p&&j<i-1)//���ҵ�i-1����㣬pָ��ý��  
    {  
        p=p->next;++j;  
    }  
    if(!p||j>i-1)    //i>n+1����i<1��iֵ���Ϸ�  
    {  
        printf("LL_InsAt(): The value of 'i' is not in the range [1,n+1].\n"); return;  
    }  
    s=(LNode *)malloc(sizeof(LNode)); //�����½��s  
    s->data=e; //�����s����������Ϊe  
    s->next=p->next; p->next=s;  //�����s����  
    /********** End **********/  
}
void LL_DelAt(LinkList L,int i)  
// �ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�i��ȡֵ��Χ[1,n]  
{  
    // �������ﲹ����룬��ɱ�������  
    /********** Begin *********/  
    LNode *p,*s; int j;  
    p=L;j=0;   
    while(p->next &&j<i-1)//���ҵ�i-1����㣬pָ��ý��  
    {  
        p=p->next; ++j;   
    }   
    if(!(p->next)||j>i-1) //i>n����i<1��iֵ���Ϸ�  
    {  
        printf("LL_DelAt(): The value of 'i' is not in the range [1,n].\n"); return;  
    }  
    s=p->next; p->next=s->next; free(s); //ɾ��  
    /********** End **********/  
}
void LL_DelValue(LinkList L, ElemType e)  
// ɾ����һ��ֵΪe������Ԫ��  
{  
    // �������ﲹ����룬��ɱ�������  
    /********** Begin *********/  
    LNode *p,*q;  
    p=L->next; q=L; //qָ��p��ָ����ǰ�����  
    while(p&&p->data!=e)  
    {  
        p=p->next; q=q->next;  
    }  
    if(p)//�ҵ�ֵΪe��Ԫ��          
    {  
        q->next=p->next; free(p); //ɾ��p��ָ���  
    }  
    /********** End **********/  
}
