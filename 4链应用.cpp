//十进制n变2进制
void binaryConv(int n)
{
	SqStack S;//定义顺序栈S
	int e;
	initStack(S);//初始化空栈
	while(n)//n!=0时循环
	{
		push(S,n%2);//入栈
		n=n/2;//更新
	}
	while(!Empty(S))//栈不空
	{
		pop(S,e);//出栈
		cout<<e<<endl;//输出栈顶元素
	}
}
/*
int n;
cin>>n;
*/

//两链表公共节点
LinkList (LinkList headA, LinkList headB)
{	if(headA==null || headB==null)	return null;
	LinkList cur1=headA;
	LinkList cur2=headB;
	int k1=0;
	int k2=0;
	boolean bol=true;//为true认为h1长;如果h2长后面代码将bol置为false
	while(cur1!=null ||cur2!=null)
		{	if(cur1!=null)
			{	k1++;
				cur1=cur1.next;}
			if(cur2!=null)
				{	k2++;
					cur2=cur2.next; 
					if(cur1==null)	bol=false;
					//cur1为空，cur2不为空的时候表示链表B长，将bol置为false
				}
		}
	int len=k1>k2?(k1-k2):(k2-k1);//长度差值
	cur1=(bol==true?headA:headB);//存的是链表节点比较长的
	cur2=(bol==true?headB:headA);
	while(len>0)
		{	cur1=cur1.next;
			len--;
		}
	while(cur2!=cur1 && cur1!=null &&cur2!=null)
		{	cur2=cur2.next;
			cur1=cur1.next;
		}
	return cur1;
}