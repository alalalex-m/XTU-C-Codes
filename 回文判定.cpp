//回文判定
//abba，abcscba
bool palindrome(char *str)
{
	SqStack S;
	int len,i;
	char e;
	len=strlen(str);
	initStack(S);
	for(i=0;i<len/2;i++)
	{
		push(S,str[i]);
	}
	if(len%2==1)		i++;
	while(!Empty(S))
	{
		pop(S,e);
		if(e!=str[i])	return false;
		else i++;
	}
	return true;
}
/*
char str[100];
cout<<"Input: ";
cin>>str;
*/