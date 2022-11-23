//双端队列遍历
void traverse(DuQueue Q)
{
	if(isEmpty(Q))
	{
		cout<<"DuQueue is empty"<<endl;
		return;
	}
	int temp=Q.front;
	while(temp!=Q.rear)
	{
		cout<<Q.base[temp]<<"\t"<<endl;
		temp=(temp+1)%Maxsize;
	}
	cout<<"OVER"<<endl;
}