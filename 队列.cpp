//队列queue

//顺序队列
#include<stdio.h>
#include<stdlib.h>
//结点定义
typedef struct node{
	int data;
	struct node *next;
}node;
//队列定义，队首指针和队尾指针
typedef struct queue{
	node *front;
	node *rear;
}queue;

//初始化结点
node *init_node(){
	node *n=(node*)malloc(sizeof(node));
	if(n==NULL){    //建立失败，退出
		exit(0);
	}
	return n;
}

//初始化队列
queue *init_queue(){
	queue *q=(queue*)malloc(sizeof(queue));
	if(q==NULL){    //建立失败，退出
		exit(0);
	}
	//头尾结点均赋值NULL
	q->front=NULL;  
	q->rear=NULL;
	return q;
}

//队列判空
int empty(queue *q){
	if(q->front==NULL){
		return 1;   //1--表示真，说明队列非空
	}else{
		return 0;   //0--表示假，说明队列为空
	}
}

//入队操作
void push(queue *q,int data){
	node *n =init_node();
	n->data=data;
	n->next=NULL;   //采用尾插入法
	//if(q->rear==NULL){  
	if(empty(q)){
		q->front=n;
		q->rear=n;
	}else{
		q->rear->next=n;    //n成为当前尾结点的下一结点
		q->rear=n;  //让尾指针指向n
	}
}

//出队操作
void pop(queue *q){
	node *n=q->front;
	if(empty(q)){
		return ;    //此时队列为空，直接返回函数结束
	}
	if(q->front==q->rear){
		q->front=NULL;  //只有一个元素时直接将两端指向制空即可
		q->rear=NULL;
		free(n);        //记得归还内存空间
	}else{
		q->front=q->front->next;
		free(n);
	}
}

//打印队列元素
void print_queue(queue *q){
	node *n = init_node();
	n=q->front;
	if(empty(q)){
		return ;    //此时队列为空，直接返回函数结束
	}
	while (n!=NULL)
		{
			printf("%d\t",n->data);
			n=n->next;
		}
	printf("\n");   //记得换行
}

//主函数调用，这里只是简单介绍用法
int main(){
	queue *q=init_queue();
	printf("入队\n");
	for(int i=1;i<=5;i++){
		push(q,i);
		print_queue(q);
	}
	printf("出队\n");
	for(int i=1;i<=5;i++){
		pop(q);
		print_queue(q);
	}
	return 0;
}

//循环队列
Q.rear==Q.front//队空
(Q.rear+1)%Maxsize==Q.front//队满
//队列长度
int queueLength(SqQueue Q)
{
	return (Q.rear-Q.front+Maxsize)%Maxsize;
}
//队列倒置
void reverse(queue &Q)
{
	int e;
	if(!queueEmpty(Q))
	{
		e=DeQueue(Q);
		reverse(Q);
		EnQueue(Q,e);
	}
}

//链队列
#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;
typedef struct LinkQueuenode
{
	elemtype data;
	struct LinkQueuenode *next;
}LinkQueue;
typedef struct LQueue
{
	LinkQueue *front;
	LinkQueue *rear;
}LQueue;

//初始化队列
LQueue *init_LinkQueue()
{
	LinkQueue *head;
	LQueue *Q;
	Q = (LQueue *)malloc(sizeof(LQueue));
	head = (LinkQueue *)malloc(sizeof(LinkQueue));
	if(0 == Q || 0 == head){
		return Q;
	}
	head -> next = NULL;
	Q -> front = head;
	Q -> rear = head;
	head -> data = 0;
	return Q;
}
//入队列
void enter_LinkQueue(LQueue *Q,elemtype x)
{
	LinkQueue *p;
	p = (LinkQueue *)malloc(sizeof(LinkQueue));
	if(0 == p){
		return;
	}
	p -> data = x;
	p -> next = NULL;
	Q -> front -> data ++;//记录节点的个数
	Q -> rear -> next = p;
	Q -> rear = p;
	return;
}

//出队列
void delete_LinkQueue(LQueue *Q,elemtype *x)
{
	LinkQueue *node;
	node = Q -> front -> next;//首结点
	if(Q -> front == Q -> rear){
		return;
	}
	
	*x = node -> data;
	Q -> front -> next  = node -> next;
	if(node == Q -> rear){
		Q -> rear = Q -> front;
	}
	free(node);
	Q -> front -> data --;
	return;
}

//输出
void print(LQueue *Q)
{
	elemtype *x;
	int k;
	x = &k;
	printf("出队结果为:");
	while(Q -> front != Q -> rear){
		delete_LinkQueue(Q,x);
		printf("%d ",*x);
	}
	printf("\n");
}

//带头循环链表做队列，只设尾指针，入队
void EQueue(LNode *rear, int e)
{
	LNode *new;
	new=(LNode *)malloc(sizeof(LNode));
	if(!new)	return ERROR;
	new->data=e;
	new->next=rear->next;
	rear->next=new;
	rear=new;
}

int main()
{
	LQueue *Q;
	elemtype x;
	Q = init_LinkQueue();
	printf("请输入您想输入的数据(输入-100结束):");
	while(x != -100){
		scanf("%d",&x);
		if(x == -100){
			break;
		}
		enter_LinkQueue(Q,x);
	}
	printf("\n");
	print(Q);
}