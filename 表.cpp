#include<iostream>
using namespace std;
#define Maxsize 4

//表

// 顺序表--SqList--sequence list
typedef struct sqList
{
	int * elem;
	int length;
	int size;
}SqList;

// 初始化
bool initList(SqList &L)
{
	L.elem = new int[Maxsize];//分配空间 new int[5]
	if (!L.elem)	return false;//分配失败
	L.length = 0;//顺序表长度为0
	return true;
}
//创建
bool creatList(SqList &L)
{
	int x,i=0;
	cout<<"Start?"<<endl;
	cin>>x;
	while(x!=-1)//输入-1停止输入
	{
		if(L.length==Maxsize)
		{
			cout<<"SqList is full"<<endl;
			return false;
		}
		cout<<"Input:";
		cin>>x;//输入元素
		L.elem[i++]=x;//现存再i++
		//或可用
		//L.elem[i]=x;	i++;
		L.length++;//SqList长度+1
		cout<<"Continue?"<<endl;
		cin>>x;//输入一个数据元素
	}
	return true;
}
//取值
bool getElem(SqList L,int i,int &e)
{
	if(i<1||i>L.length)	return false;//判断i合理
	e = L.elem[i-1];//i-1存第i个数据
	return true;
}
//插入
bool insertSqlist(SqList &L,int i,int e)
{
	if(i<1||i>L.length)	return false;
	if(L.length == Maxsize)	return false;//空间已满
	for (int j=L.length-1;j>=i-1;j--)//从最后一个开始到第i个元素，后移
	{
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;//表长加1
	return true;
}
//删除
bool deleteSqlist(SqList &L,int i,int &e)
{
	if(i<1||i>L.length)	return false;
	e=L.elem[i-1];
	for(int j=i;j<=L.length;j++)//被删之后前移
	{
		L.elem[j-1]=L.elem[j];
	}
	L.length--;
	return true;
}

//单链表--LinkList
typedef struct linkNode
{
	int data;
	struct linkNode *next;//指针域
}LinkNode,*LinkList;

//创建-头插---数据与输入顺序相反
void createLListF(LinkList &L)
{
	int n;
	LinkList s;//定义指针变量
	L=new LNode;
	L->next=NULL;//建立带头节点的空链表
	cout<<"Enter elem count"<<endl;
	cin>>n;
	cout<<"头插法"<<endl;
	while(n--)//n!=0时
	{
		s=new LNode;//生成新节点
		cout<<"Enter data"<<endl;
		cin>>s->data;//该节点数据
		s->next=L->next;
		L->next=s;//新节点s插入头节点后
	}
}
//创建-尾插---数据与输入顺序相同
void createLListR(LinkList &L)
{
	int n;
	LinkList s,r;//定义指针变量,s-插入,r-尾指针
	L=new LNode;
	L->next=NULL;//建立带头节点的空链表
	r=L;//尾指针r指向头节点
	cout<<"Enter elem count"<<endl;
	cin>>n;
	cout<<"尾插法"<<endl;
	while(n--)
	{
		s=new LNode;//新节点
		cout<<"Enter data"<<endl;
		cin>>s->data;//节点数据
		s->next=NULL;
		r->next=s;//新节点s插入尾节点r后
		r=s;//指向新尾节点s
	}
}

//输出链表内容
void ShowList(LinkList L)
{
	L=L->next;//跳过头节点
	while(L)
		{
			cout<<L->data<<endl;
			L=L->next;
		}
}

//查找
bool locateElem_L(LinkList L,int e)//查找值为e元素
{
	LinkList p;
	p=L->next;
	while(p&&p->data!=e)
	{
		p=p->next;
	}
	if(!p)	return false;
	return true;
}
//插入
bool insertLlist(LinkList &L,int i,int e)
{
	int j=0;
	LinkList p,s;//p-目标位置，s-插入节点
	p=L;
	while(p&&j<i-1)
	{
		p=p->next;
		j=j+1;
	}
	if(!p||j>i-1)	return false;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//删除第i个
bool ListDelete_L(LinkList &L,int i)
{//带头节点，删除第i个位置（q）
	LinkList p,q;
	int j=0;
	p=L;
	while((p->next)&&(j<i-1))//查找第i-1节点，p指向它
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i+1))//i>n或i<1不合理
		return false;
	q=p->next;//临时保存被删节点地址
	p->next=q->next;//q下一节点赋给p
	delete q;//释放被删节点空间
	retrun true;
}
//删除值为x
void Del_x(Linklist &L, ElemType x)
{
	LinkNode *p=L->next, *pre=L, *q; 
	//p用来遍历链表
	//pre指向前趋
	//q指针指向结点x，标记它并删除它
	while(p!=Null){
		if(p->data==x)
		{//p所指的data域为x，即找到了x
			q=p;
			p=p->next;//用p覆盖q，q就没了
			pre->=p;
			free(q);
		}
		else
		{
			pre=p;//若没有找到x，则p和pre两个结点向后移动一位
			p=p->next;
		}
	}
}

//双向链表
typedef struct duaNode
{
	ElemType data;
	struct *prior, *next;
}duaNode, *duaLinkList;

//插入
bool insertDuaList(DuaLinkList &L,int i,int e)
{
	int j=0;
	duaLinkList p,s;
	while (p&&j<i)
	{
		p=p->next;
		j=j+1;
	}
	if(!p||j>i)	return false;
	s=new duaNode;
	s->data = e;
	p->prior->next = s;
	s->prior = p->prior;
	s->next = p;
	p->prior = s;
	return true;
}
//删除
p->next->prior=p->prior;
p->prior->next=p->next;
//循环双向p后插q
q->prior=p;
q->next=p->next;
p->next->prior=q;
p->next=q;

//循环链表