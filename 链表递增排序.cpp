//带头，递增排序
void sortUp(LinkList &L)
{
	LinkList p,pre,rear;
	p=L->next;
	rear = p->next;//保留p后链表，不断链
	p->next=NULL;//L只剩一个节点，重构L
	p=rear;//遍历剩余
	while(p)
	{
		rear=p->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data)
		{
			pre = pre->next;
		}
		p->next=pre->next;//尾插，p插进新L
		pre->next=p;
		p=rear;//继续遍历
	}
}