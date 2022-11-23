#include <stdio.h>
#include <stdlib.h>

typedef struct staff
{
    int no; //职工号
    char name[10]; //姓名
    int depno; //部门号
    float salary; //薪水
}StfType; //职工类型

typedef struct node
{
    StfType data; //存放职工信息
    struct node *next; //指向下一个结点的指针
}StfList; // 职工单链表结点类型

/*---------------------------释放职工单链表L----------------------------*/
static void destroyStaff(StfList * &L)// 指针的引用
{
    StfList *pre = L; // pre指向单链表的头结点
    StfList *p = pre->next;// p指向单链表的第一个数据结点
    
    while(p != NULL)
        {
            free(pre);
            pre = p;
            p = p->next;
        }
    free(pre);
}


/*---------------------------读emp.dat文件建立职工单链表L----------------------------*/
// 读取emp.dat文件中所有职工记录并建立带头结点的职工单链表L
static void readFile(StfList *&L)
{
    FILE *fp;
    StfType emp;
    StfList *p;
    StfList *r;
    int n = 0;
    
    // 建立头结点
    L = (StfList *)malloc(sizeof(StfList));
    r = L; // r指向新建立的头结点
    if((fp = fopen("emp.dat", "rb")) == NULL) // 不存在emp.dat文件
    {
        if((fp = fopen("emp.dat", "wb")) == NULL)
            {
                printf("提示:不能创建emp.dat文件\n");
            }
    }
    else // 若存在emp.dat文件
    {
        while(fread(&emp, sizeof(StfType), 1, fp) == 1)
            {
                // 采用尾插法建立单链表L
                p = (StfList *)malloc(sizeof(StfList)); // 新建结点p,分配内存空间
                p->data = emp;
                r->next = p;
                r = p; // r指向新建的结点p
                n++;
            }
    }
    r->next = NULL;
    printf("提示:职工单链表L建立完毕,有%d个记录\n", n);
    fclose(fp);
}

/*---------------------------添加一个职工记录----------------------------*/
// 向单链表L中添加一个职工记录
static void addStaff(StfList *&L)
{
    StfType p;
    StfList *s;
    
    printf(">>输入职工号(-1返回):");
    scanf("%d", &p.no);
    if(p.no == -1)
        return;
    printf(">>输入姓名    部门号     薪水:");
    scanf("%s %d %f", &p.name, &p.depno, &p.salary);
    
    // 创建新结点s
    s = (StfList *)malloc(sizeof(StfList));// 分配内存空间
    s->data = p;
    // 采用头插法插入结点s
    s->next = L->next;
    L->next = s;
    printf("提示:添加成功\n");
}

/*---------------------------输出所有职工记录----------------------------*/
// 显示单链表L中的所有职工记录
static void displayStaff(StfList *L)
{
    StfList *p = L->next; // p指向链表中的第一个数据结点
    
    if(p == NULL)
        {
            printf("提示:没有任何职工记录\n");
        }
    else
        {
            printf("    职工号     姓名      部门号     薪水\n");
            printf("    ----------------------------------------------\n");
            while(p != NULL)
                {
                    printf("    %3d   %10s      %-8d %7.2f\n", p->data.no, p->data.name, p->data.depno, p->data.salary);
                    p = p->next;
                }
            printf("    ----------------------------------------------\n");
        }
}

/*---------------------------采用直接插入法对单链表L按职工编号递增有序排列----------------------------*/
static void sortNo(StfList *&L) //指针的引用
{
    StfList *p;
    StfList *pre;
    StfList *q;
    
    p = L->next->next; // p指向单链表L中的第二个数据结点
    if(p != NULL)
        {
            L->next->next = NULL;
            while(p != NULL)
                {
                    q = p->next;
                    pre = L;
                    while(pre->next != NULL && pre->next->data.no < p->data.no)
                        pre = pre->next;
                    p->next = pre->next;
                    pre->next = p;
                    p = q;
                }
        }
    printf("提示:按no递增排序完毕\n");
}

/*---------------------------采用直接插入法对单链表L按部门编号递增有序排列----------------------------*/
static void sortDepno(StfList *&L) //指针的引用
{
    StfList *p;
    StfList *pre;
    StfList *q;
    
    p = L->next->next; // p指向单链表L的第二个数据结点
    if(p != NULL)
        {
            L->next->next = NULL;
            while(p != NULL)
                {
                    q = p->next;
                    pre = L;
                    while(pre->next != NULL && pre->next->data.depno < p->data.depno)
                        pre = pre->next;
                    p->next = pre->next;
                    pre->next = p;
                    p = q;
                }
        }
    printf("提示:按depno递增排序完毕\n");
}

/*---------------------------采用直接插入法对单链表L按薪水递增有序排列----------------------------*/
static void sortSalary(StfList *&L) //指针的引用
{
    StfList *p;
    StfList *pre;
    StfList *q;
    
    p = L->next->next; // p指向单链表L的第二个数据结点
    if(p != NULL)
        {
            L->next->next = NULL;
            while(p != NULL)
                {
                    q = p->next;
                    pre = L;
                    while(pre->next != NULL && pre->next->data.salary < p->data.salary)
                        pre = pre->next;
                    p->next = pre->next;
                    pre->next = p;
                    p = q;
                }
        }
    printf("提示:按salary递增排序完毕\n");
}

/*---------------------------删除一个职工记录----------------------------*/
// 从单链表L中删除一个职工记录(根据职工编号删除职工记录)
static void deleteStaff(StfList *&L)
{
    StfList *pre = L; //pre指向单链表L的头结点
    StfList *p = L->next; //p指向单链表L的第一个数据结点
    int no;// 职工编号
    
    printf(">>输入职工号(-1返回):");
    scanf("%d", &no);
    if(no == -1)
        return;
    while(p != NULL && p->data.no != no)
        {
            pre = p;
            p = p->next;
        }
    
    if(p == NULL)
        printf("提示:指定的职工记录不存在\n");
    else
        {
            // 释放p结点,从单链表L中删除
            pre->next = p->next;
            free(p);
            printf("提示:删除成功\n");
        }
}

/*---------------------------删除职工文件中的全部记录----------------------------*/
static void deleteAll(StfList*&L) // 指针的引用
{
    FILE *fp = NULL;
    
    // "wb" 只写打开或建立一个二进制文件,只允许写数据
    // "rb" 只读打开一个二进制文件,只允许读数据
    fp = fopen("emp.dat", "wb");
    if(fp == NULL) // 重写清空emp.dat文件
    {
        printf("提示:不能打开职工文件\n");
        return;
    }
    fclose(fp);
    // 释放职工单链表
    destroyStaff(L);
    // 建立一个空的职工单链表L
    L = (StfList *)malloc(sizeof(StfList));
    L->next = NULL;
    printf("提示:职工数据清除完毕\n");
}

/*---------------------------将职工单链表数据存入数据文件----------------------------*/
// 将职工单链表L中所有数据存入到职工文件emp.dat中
static void saveFile(StfList *L)
{
    StfList *p = L->next;
    FILE *fp = NULL;
    int n = 0;

    fp = fopen("emp.dat", "wb");
    if(fp == NULL)
    {
        printf("提示:不能创建文件emp.dat\n");
        return;
    }

    while(p != NULL)
    {
        fwrite(&p->data, sizeof(StfType), 1, fp);
        p = p->next;
        n++;
    }
    fclose(fp);

    // 释放职工单链表L
    destroyStaff(L);

    if(n > 0)
    {
        printf("提示:%d个职工记录写入emp.dat文件\n", n);
    }
    else
    {
        printf("提示:没有任何职工记录写入emp.dat文件\n");
    }
}



int main()
{
    StfList *L;
    int selection;

    printf("由emp.dat文件建立职工单链表L\n");
    readFile(L);
    do
    {
        printf(">1:添加 2:显示 3:按职工号排序 4:按部门号排序 5:按薪水排序\n>6:删除单个职工信息 9:删除全部职工信息 0:退出\n请选择:");
        scanf("%d", &selection);
        switch(selection)
        {
        case 9:
            deleteAll(L);
            break;
        case 1:
            addStaff(L);
            break;
        case 2:
            displayStaff(L);
            break;
        case 3:
            sortNo(L);
            break;
        case 4:
            sortDepno(L);
            break;
        case 5:
            sortSalary(L);
            break;
        case 6:
            deleteStaff(L);
            break;
        }
    }while(selection != 0);

    saveFile(L);

    return 0;
}
