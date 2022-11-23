#include <iostream>
using namespace std;

#define Maxsize 20

typedef struct sqList
{
	int * elem;
	int length;
}SqList;

bool initList(SqList &L)
{
	L.elem = new int[Maxsize];//分配空间 new int[5]
	if (!L.elem)	return false;//分配失败
	L.length = 0;//顺序表长度为0
	return true;
}

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

void mergeSqList(SqList La, SqList Lb, SqList &Lc)
{
	int i=0,j=0,k=0;
	Lc.length=La.length+Lb.length;//c长度为a,b之和
	Lc.elem = new int[Lc.length];//为合并后新表分配maxsize=c长度
	while(i<La.length&&j<Lb.length)//两表均非空
	{//依次取两表中较小值放入Lc
		if(La.elem[i]<=Lb.elem[j])
			Lc.elem[k++]=La.elem[i++];
		
		Lc.elem[k++]=Lb.elem[j++];
		
		//先赋值，再++
	}
	while(i<La.length)//La有剩余，放入Lc尾部
	Lc.elem[k++]=La.elem[i++];
	while(i<Lb.length)//Lb有剩余，放入Lc尾部
	Lc.elem[k++]=Lb.elem[j++];
}

bool getElem(SqList L,int i,int &e)
{
	if(i<1||i>L.length)	return false;//判断i合理
	e = L.elem[i-1];//i-1存第i个数据
	return true;
}

int main ()
{
	SqList La,Lb,Lc;
	initList(La);
	initList(Lb);
	cout<<"录入La"<<endl;
	creatList(La);
	cout<<"录入Lb"<<endl;
	creatList(Lb);
	cout<<"生成Lc"<<endl;
	mergeSqList(La, Lb, Lc);
	for(int i=1;i<Lc.length+1;i++)
	{
		int e=0;
		getElem(Lc,i,e);
//		cout<<"Lc"<<endl;
		cout<<e<<endl;
	}
/*	for(int i=1;i<La.length+1;i++)
	{
		int e=0;
		getElem(La,i,e);
		cout<<"La"<<endl;
		cout<<e<<endl;
	}
	for(int i=1;i<Lb.length+1;i++)
	{
		int e=0;
		getElem(Lb,i,e);
		cout<<"Lb"<<endl;
		cout<<e<<endl;
	}*/
	return 0;
}
