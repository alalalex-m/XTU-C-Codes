#include<iostream>
using namespace std;

typedef struct linkNode
{
	int data;
	struct linkNode *next;//指针域
}LinkNode,*LinkList;

void createLListR(LinkList &L)
{
	int n;
	LinkList s,r;//定义指针变量,s-插入,r-尾指针
	L=new LinkNode;
	L->next=NULL;//建立带头节点的空链表
	r=L;//尾指针r指向头节点
	cout<<"Enter elem count"<<endl;
	cin>>n;
	cout<<"尾插法"<<endl;
	while(n--)
		{
			s=new LinkNode;//新节点
			cout<<"Enter data"<<endl;
			cin>>s->data;//节点数据
			s->next=NULL;
			r->next=s;//新节点s插入尾节点r后
			r=s;//指向新尾节点s
		}
}

void ShowList(LinkList L)
{
	L=L->next;//跳过头节点
	while(L)
		{
			printf("%d\n",L->data);
			L=L->next;
		}
}

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
	if(p)	r->next=p; 
	else	r->next=q;
	delete Lb;
}

LinkList findMiddle(LinkList L)
{
	LinkList p,q;
	p=L;//快
	q=L;//慢
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next->next;//一次两步
		q=q->next;//一次一步
	}
	return q;//中间指针
}

void deleteRep(LinkList &L)
{
	LinkList p,q;
	int x;
	int *flag=new int[5+1];//数组flag，n+1空间，0个空间未用
	for(int i=0;i<5+1;i++)	flag[i]=0;//初始化
	p=L;//指向头节点
	while(p->next!=NULL)
		{
			x=abs(p->next->data);
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

int main()
{
	LinkList La,Lb,Lc;
	cout<<"Create La"<<endl;
	createLListR(La);
/*	cout<<"Create Lb"<<endl;
	createLListR(Lb);
	cout<<"Merge Lc"<<endl;
	mergeLList(La, Lb, Lc);
	cout<<"La:"<<endl;
	ShowList(La);
	cout<<"Lb:"<<endl;
	ShowList(Lb);
	cout<<"Lc:"<<endl;
	ShowList(Lc);
	cout<<findMiddle(La)->data<<endl;*/
	deleteRep(La);
	ShowList(La);
	return 0;
}