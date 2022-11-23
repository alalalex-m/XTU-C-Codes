//删除重复元素
//data绝对值相同，只保留第一次出现节点
//|data|<=n
void deleteRep(LinkList &L)
{
	LinkList p,q;
	int x;
	int *flaq=new int[n+1];//数组flag，n+1空间，0个空间未用
	for(int i=0;i<n+1;i++)	flag[i]=0;//初始化
	p=L;//指向头节点
	while(p->next!=NULL)
	{
		x=abs(p->next->data)
		if(flag[x]==0)//未出现过
		{
			flag[x]=1;//标记出现过
			p=p->next;//指针后移
		}
		else
		{
			q=p->next;//q指向p下一个节点
			p->next=q->next;//删除重复元素
			delete q;//释放q
		}
	}
	delete []flag;
}
//	deleteRep(La);
//	ShowList(La);
