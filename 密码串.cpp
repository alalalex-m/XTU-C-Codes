#include<stdio.h>
#include<string.h>
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}HString;
 
void strAssign(HString &T,char *chars)//生成一个其值等于串常量chars的串T
{
	int i=0;
	for(;chars[i]!='\0';i++)
	{
		T.data[i]=chars[i];
	}
	T.length=i;
}
 
void strDisplay(HString s)//显示串
{
	int i;
	if(s.length>0)
	{
		for(i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		printf("\n");
	}
}
 
HString strEncrypt(HString A,HString B,HString T)//输入字母映射表和要加密的串
{
	int i=0,j;//j为A串中的下标
	HString str;//创建新串,为T加密后的串
	while(i<T.length)
	{
		for(j=0;T.data[i]!=A.data[j];j++);
		if(j>=A.length)printf("出错了！");
		else str.data[i]=B.data[j];
		i++;
	}
	str.length=T.length;
	return str;
}
 
HString strUnencrypt(HString A,HString B,HString T)//输入字母映射表和要解密的串
{
	int i=0,j;
	HString str;
	while(i<T.length)
	{
		for(j=0;T.data[i]!=B.data[j];j++);
		if(j>=A.length)printf("出错了！");
		else str.data[i]=A.data[j];
		i++;
	}
	str.length=T.length;
	return str;
}
 
int main()
{
	HString A,B,S2,S1,S3;
	char str[MaxSize];
	strAssign(A,"abcdefghijklmnopqrstuvwxyz");
	strAssign(B,"ngzqtcobmuhelkpdawxfyivrsj");
	printf("请输入要加密的串>>");
	gets(str);
	strAssign(S1,str);
	S2=strEncrypt(A,B,S1);
	printf("加密后>>");
	strDisplay(S2);
	printf("解密后>>");
	S3=strUnencrypt(A,B,S2);
	strDisplay(S3);
}