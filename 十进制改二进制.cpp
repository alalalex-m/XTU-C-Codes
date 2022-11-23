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