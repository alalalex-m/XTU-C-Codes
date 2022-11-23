//单链表A分为A(奇),B(偶)
LinkList DisCreat_1(LinkList &A)
{
	//将表A中结点按序号的奇偶性分解到表A或表B中
	i=0;	//i记录表A中结点的序号
	B=(Linklist)malloc(sizeof(LNode));	//创建B表表头
	B->next=NULL;	//B表初始化
	LNode *ra=A,*rb=B; 	//ra和rb将分别指向将创建的A表和B表的尾结点
	p=A->next;	//p为链表工作指针，指向待分解的结点
	A->next=NULL;	//置空新的A表
	while(p!=NULL)
	{
		i++;	//序号加1
		if(i%2==0)
		{		//处理序号为偶数的链表结点
			rb->next=p;	//在B表尾插入新节点
			rb=p;	//rb指向新的尾结点
		}
		else
		{
			ra->next=p; //处理原序号为奇数的结点
			ra=p;		//在A表为插入新节点
		}
		p=p->next;	//将B恢复为指向新的待处理结点
	}				//while结束
	ra->next=NULL;
	rb->next=NULL;
	return B;
}