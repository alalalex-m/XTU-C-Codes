#include <iostream>
using namespace std;

#define N 4
#define M 10
/* ----------------------输入矩阵a,b   n表示矩阵所含的行数------------- */
static void input(int n, int a[], int b[])
{
    for(int k=0;k<n*(n+1)/2;k++){
        cin>>a[k];
    }
    for(int k=0;k<n*(n+1)/2;k++){
        cin>>b[k];
    }
}
/*-----------------------返回压缩存储a中a[i][j]的值-----------------------*/
/**
*   算法思路
*       对称矩阵M的第i行和第j列的元素的数据存储在一维数组a中的位置k的计算公式:
*   1、当i大于或等于j时，k = (i * (i + 1)) / 2 + j (下三角)
*   2、当i小于j时，k = (j * (j + 1)) / 2 + i (上三角)
*
*/
static int value(int a[], int i,int j)
{
    if (i>=j)
        return a[i*(i+1)/2+j];
    else
        return a[j*(j+1)/2+i];
}
/*-----------------------求压缩存储a和b的和-----------------------*/
static void madd(int a[],int b[],int c[][N])
{
    for (int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            c[i][j]=value(a,i,j)+value(b,i,j);
        }
    }
}
/*-----------------------求压缩存储a和b的乘积-----------------------*/
static void mult(int a[],int b[],int c[][N])
{
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int sum = 0;
            for (int k=0;k<N;k++){
                sum=sum+value(a,i,k)*value(b,k,j);
            }
            c[i][j]=sum;
        }
    }
}
/*-----------------------输出压缩存储a-----------------------*/
static void disp1(int a[])
{
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout<<value(a,i,j)<<" ";
        }
        cout<<endl;
    }
}
/*-----------------------输出对称矩阵c-----------------------*/
static void disp2(int c[][N])
{
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
/* 主函数 */
int main()
{
    int n;
    cout<<"行数："<<endl;
    cin>>n;
    int a[n*(n+1)/2],b[n*(n+1)/2];
    int c1[N][N],c2[N][N];
    cout<<"输入上三角："<<endl;
    input(n,a,b);
    cout<<"两个矩阵之和"<<endl;
    madd(a,b,c1);
    disp2(c1);
    cout<<"两个矩阵之积"<<endl;
    mult(a,b,c2);
    disp2(c2);
    return 0;
}
