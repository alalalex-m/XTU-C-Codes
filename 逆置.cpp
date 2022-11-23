//单链表元素顺序逆转，空间复杂度为O(1)

void reverseLlist(LinkList &L)
{
	LinkList p,q;
	p=L->next;//p指向L第一个元素
	L->next=NULL;//头节点next域置空
	while(p)
	{
		q=p->next;//q指向p下一节点，记录断点
		p->next=L->next;//头插法，L下一节点地址赋值给p->next域
		L->next=p;//p地址赋给L->next
		p=q;//p指向q，指针后移
	}
}