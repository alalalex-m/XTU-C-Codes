//合并有序顺序表
//已知有序顺序表La,Lb元素按值非递减排列
//合并得到Lc元素按值非递减排列

void mergeSqList(Sqlist La, SqList Lb, SqList &Lc)
{
	int i=0,j=0,k=0;
	Lc.length=La.length+Lb.length;//c长度为a,b之和
	Lc.elem = new int[Lc.length];//为合并后新表分配maxsize=c长度
	while(i<La.length&&j<Lb.length)//两表均非空
	{//依次取两表中较小值放入Lc
		if(La.elem[i]<=Lb.elem[j])	Lc.elem[k++]=La.elem[i++];
		Lc.elem[k++]=Lb.elem[j++];
	 //先赋值，再++
	}
	while(i<La.length)//La有剩余，放入Lc尾部
		Lc.elem[k++]=La.elem[i++];
	while(i<Lb.length)//Lb有剩余，放入Lc尾部
		Lc.elem[k++]=Lb.elem[j++];
}

//合并有序链表
void mergeLList(LinkList La,LinkList Lb,LinkList &Lc)
{
	LinkList p,q,r;
	p=La->next;//p指向La第一个数据元素节点
	q=Lb->next;
	Lc=La;//Lc指向La头节点
	r=Lc;//r指向Lc尾部
	while(p&&q)
		{
			if(p->data<=q->data)//p指的节点串起来
			{
				r->next=p;
				r=p;
				p=p->next;
			}
			else//q指的节点串起来
			{
				r->next=q;
				r=q;
				q=q->next;
			}
		}
	r->next=p?p:q;//相当于if(p)	r->next=p; else	r->next=q;
	delete Lb;
}
//	mergeLList(La, Lb, Lc);
