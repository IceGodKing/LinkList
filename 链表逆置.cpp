void reverse (LinkList  L)
{  
	//����Lָ����ָ��ĵ�����
	/********** Begin **********/ 
	LinkList p,q;
	p=L->next;
	L->next=NULL;
	while(p)
	{	
		q=p;
		p=p->next;
		q->next=L->next;
		L->next=q;
	}
    
	/********** End **********/
}
