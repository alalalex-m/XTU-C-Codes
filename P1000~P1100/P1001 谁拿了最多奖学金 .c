#include<stdio.h>
#include<string.h>

struct student
{
	char name[21];
	int final;
	int class;
	char work;
	char west;
	int paper;
	int money;
};

int main()
{
	int n,MAX=0,X=0,ALL=0;
	scanf("%d",&n);
	struct student stu[101];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s %d %d %c %c %d",stu[i].name,&stu[i].final,&stu[i].class,&stu[i].work,&stu[i].west,&stu[i].paper);
	}
	for(i=0;i<n;i++)
	{
		stu[i].money=0;
		if(stu[i].final>80&&stu[i].paper>=1)
			stu[i].money+=8000;
		if(stu[i].final>85&&stu[i].class>80)
			stu[i].money+=4000;
		if(stu[i].final>90)
			stu[i].money+=2000;
		if(stu[i].final>85&&stu[i].west=='Y')
			stu[i].money+=1000;
		if(stu[i].class>80&&stu[i].work=='Y')
			stu[i].money+=850;
	}
	for(i=0;i<n;i++)
	{
		if(stu[i].money>MAX)
			{
				MAX=stu[i].money;
				X=i;
			}
		
		ALL+=stu[i].money;
	}
	printf("%s\n%d\n%d",stu[X].name,stu[X].money,ALL);
	return 0;
}