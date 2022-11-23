//求单链表L中间节点（高效）

LinkList findMiddle(LinkList L)
{
	LinkList p,q;
	p=L;//快
	q=L;//慢
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next->next;//一次两步
		q=q->next;//一次一步
	}
	return q;//中间指针
}

//cout<<findMiddle(La)->data<<endl;