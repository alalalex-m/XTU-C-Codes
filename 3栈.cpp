//栈
//顺序栈
#include<iostream>
using namespace std;
#define Maxsize 4

typedef struct SqStack
{
	int *base;
	int *top;
}SqStack;

//初始化
bool initStack(SqStack &S)//构造空栈S
{
	S.base = new int[Maxsize];
	if(!S.base)	return false;
	S.top=S.base;//top初始为基地址base，空栈条件
	return true;
}

//入栈
bool push(SqStack &S, int e)
{
	if(S.top-S.base==Maxsize)	return false;//栈满
	*S.top++=e;//新元素e压入栈顶，栈顶指针+1
	//等价于*S.top=e;S.top++
	return true;
}

//出栈
bool pop(SqStack &S, int &e)
{
	if(S.base==S.top)	return false;//栈空
	e=*--S.top;//top-1，再将栈顶元素赋给e
	//S.top--;e=*S.top
	return true;
}

//取栈顶元素
int getTop(SqStack S)
{
	if(S.top!=S.base)//栈非空
		return *(S.top-1);//返回栈顶元素
	else
		return -1;
}
//栈空？
bool Empty(SqStack S)
{
	if(S.base==S.top)	return true;
	else	return false;
}

//链栈
typedef struct sNode
{
	int data;
	struct sNode *next;
}sNode, *LinkStack;

//入栈
bool push(LinkStack &S, int e)
{
	LinkStack p;
	p=new sNode;//新节点
	p->data=e;//e存入新节点
	p->next=S;//S地址赋值给新节点指针域
	S=p;//新栈顶指针为p
	return true;
}

//出栈
bool pop(LinkStack &S, int &e)
{
	LinkStack p;
	if(S==NULL)	return false;//栈空
	e=S->data;//用e留存栈顶元素
	p=S;//用p保存栈顶地址，以备释放
	S=S->next;//修改栈顶指针，指向下一节点
	delete p;//释放p
	return true;
}

//取栈顶元素
int getTop(LinkStack S)
{
	if(S!=NULL)
		return S->data;//非空，返回栈顶元素
	else
		return-1;
}


