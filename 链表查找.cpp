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

void LL_GetAt(LinkList L, int i, ElemType &e)
// �ڴ�ͷ���ĵ�����L�л�ȡ��i��Ԫ�ص�ֵ����e��i��ȡֵ��Χ[1,n]
{
	// �������ﲹ����룬��ɱ�������
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
//�ڴ�ͷ���ĵ�����L�в��ҵ�һ��ֵΪe��Ԫ�أ�
//�ҵ��򽫸�Ԫ���������е�λ�ø���i�������ظý��ָ�룬����i��ֵΪ0�����ؿ�ָ��
{
	// �������ﲹ����룬��ɱ�������
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
