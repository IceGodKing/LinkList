void reverse (LinkList  L)
{  
	//逆置L指针所指向的单链表
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
