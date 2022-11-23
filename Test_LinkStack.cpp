#include <iostream>
using namespace std;

typedef struct sNode
{
	int data;
	struct sNode *next;
}sNode, *LinkStack;

bool push(LinkStack &S, int e)
{
	LinkStack p;
	p=new sNode;//新节点
	p->data=e;//e存入新节点
	p->next=S;//S地址赋值给新节点指针域
	S=p;//新栈顶指针为p
	return true;
}

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

int getTop(LinkStack S)
{
	if(S!=NULL)
		return S->data;//非空，返回栈顶元素
	else
		return-1;
}

int main()
{
	LinkStack s;
	int in,out;
	int i=0;
	while(i<4)
	{
		cout<<"Input: ";
		cin>>in;
		push(s,in);
		i++;
	}
	cout<<"TOP: "<<getTop(s)<<endl;
	pop(s,out);
	cout<<"DELETED: "<<out<<endl;
	cout<<"TOP: "<<getTop(s)<<endl;
	return 0;
}