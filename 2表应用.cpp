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
		{	r->next=p;
			r=p;
			p=p->next;}
		else//q指的节点串起来
		{	r->next=q;
			r=q;
			q=q->next;}
	}
	r->next=p?p:q;//相当于if(p)	r->next=p; else	r->next=q;
	delete Lb;
}
//	mergeLList(La, Lb, Lc);

//单链表元素顺序逆转，空间复杂度为O(1)
void reverseLlist(LinkList &L)
{
	LinkList p,q;
	p=L->next;//p指向L第一个元素
	L->next=NULL;//头节点next域置空
	while(p)
	{	q=p->next;//q指向p下一节点，记录断点
		p->next=L->next;//头插法，L下一节点地址赋值给p->next域
		L->next=p;//p地址赋给L->next
		p=q;}//p指向q，指针后移
}

//求单链表L中间节点（高效）
LinkList findMiddle(LinkList L)
{
	LinkList p,q;
	p=L;//快
	q=L;//慢
	while(p!=NULL&&p->next!=NULL)
	{	p=p->next->next;//一次两步
		q=q->next;}//一次一步
	return q;//中间指针
}
//cout<<findMiddle(La)->data<<endl;

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
	{	x=abs(p->next->data)
		if(flag[x]==0)//未出现过
		{	flag[x]=1;//标记出现过
			p=p->next;}//指针后移
			else
			{	q=p->next;//q指向p下一个节点
				p->next=q->next;//删除重复元素
				delete q;}}//释放q
	delete []flag;
}
//	deleteRep(La);
//	ShowList(La);

//回文判定
//abba，abcscba
bool palindrome(char *str)
{	SqStack S;
	int len,i;
	char e;
	len=strlen(str);
	initStack(S);
	for(i=0;i<len/2;i++)
	{	push(S,str[i]);}
	if(len%2==1)		i++;
	while(!Empty(S))
	{	pop(S,e);
		if(e!=str[i])	return false;
		else i++;}
	return true;}
/*
char str[100];
cout<<"Input: ";
cin>>str;
*/

//单链表A分为A(奇),B(偶)
LinkList DisCreat_1(LinkList &A)
{//将表A中结点按序号的奇偶性分解到表A或表B中
	i=0;	//i记录表A中结点的序号
	B=(Linklist)malloc(sizeof(LNode));	//创建B表表头
	B->next=NULL;	//B表初始化
	LNode *ra=A,*rb=B; 	//ra和rb将分别指向将创建的A表和B表的尾结点
	p=A->next;	//p为链表工作指针，指向待分解的结点
	A->next=NULL;	//置空新的A表
	while(p!=NULL)
		{	i++;	//序号加1
			if(i%2==0)//处理序号为偶数的链表结点
			{	rb->next=p;	//在B表尾插入新节点
				rb=p;}	//rb指向新的尾结点
			else
				{	ra->next=p; //处理原序号为奇数的结点
					ra=p;}		//在A表为插入新节点
			p=p->next;}	//将B恢复为指向新的待处理结点
	ra->next=NULL;
	rb->next=NULL;
	return B;
}

//带头，递增排序
void sortUp(LinkList &L)
{
	LinkList p,pre,rear;
	p=L->next;
	rear = p->next;//保留p后链表，不断链
	p->next=NULL;//L只剩一个节点，重构L
	p=rear;//遍历剩余
	while(p)
	{	rear=p->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data)
		{	pre = pre->next;  }
		p->next=pre->next;//尾插，p插进新L
		pre->next=p;
		p=rear;}//继续遍历
}