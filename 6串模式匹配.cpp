//串模式匹配
//子串T在主串S中第pos个字符后第一次出现位置
//T非空，1<=pos<=s[0],s[0]存放S长度
//BF算法
int index_BF(SString S,SString T,int pos)
{
	int i=pos,j=1,sum=0;
	while(i<=S[0]&&j<=T[0])
	{
		sum++;
		if(S[i]==T[j])//相等，继续比较
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;//i退回上一轮开始下一个字符
			j=1;//j从头开始
		}
	}
	count<<"Count: "<<sum<<endl;
	if(j>T[0])//匹配成功
		return i-T[0];
	else
		return 0;
}

//KMP算法