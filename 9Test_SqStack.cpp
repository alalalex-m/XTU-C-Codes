#include <iostream>
using namespace std;
#define Maxsize 4

typedef struct SqStack
{
	int *base;
	int *top;
}SqStack;

bool initStack(SqStack &S)//构造空栈S
{
	S.base = new int[Maxsize];
	if(!S.base)	return false;
	S.top=S.base;//top初始为基地址base，空栈
	return true;
}

bool push(SqStack &S, int e)
{
	if(S.top-S.base==Maxsize)	return false;//栈满
	*S.top++=e;//新元素e压入栈顶，栈顶指针+1
	//等价于*S.top=e;S.top++
	return true;
}

bool pop(SqStack &S, int &e)
{
	if(S.base==S.top)	return false;//栈空
	e=*--S.top;//top-1，再将栈顶元素赋给e
	//S.top--;e=*S.top
	return true;
}

int getTop(SqStack S)
{
	if(S.top!=S.base)	return *(S.top-1);
	else	return -1;
}

int main()
{
	SqStack S;
	int in,out;
	initStack(S);
	cout<<"Push in:"<<endl;
	for(int i=0;i<Maxsize;i++)
	{
		cin>>in;
		push(S,in);
	}
	cout<<"Pop out:"<<endl;
	pop(S,out);
	cout<<out<<endl;
	cout<<"Top:"<<endl;
	cout<<getTop(S)<<endl;
	return 0;
}