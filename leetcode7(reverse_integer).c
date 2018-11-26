/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int reverse(int x);
int main()
{
    int n;
    scanf("%d",&n);
    int t = reverse(n);
    printf("%d",t);
    return 0;
}
*/
int reverse(int x)
{
    int l=20,r,p=0,sum=0,temp;
    int* array=(int*)malloc(sizeof(int)*l);
    if(x<0) temp=(-1)*x;
    else temp = x;
    while(temp>0)
    {
        r=temp%10;
        array[p]=r;
        temp=temp/10;
        p++;
    }
    for(int i=0;i<p;i++)
    {
        sum=sum+array[i]*pow(10,p-i-1);
    }
    free(array);
    if(x<0)return (-1)*sum;
    else return sum;
}
