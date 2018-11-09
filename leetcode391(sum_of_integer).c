#include<stdio.h>
#include<stdlib.h>

int* factorial(int n,int* array);
int getSum(int a, int b);

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int t = getSum(a,b);
    printf("%d ",t);
    return 0;
}
int factorial(int n,int* array)
{
    int r,l=20,p=0;
    array =(int*)malloc(sizeof(int)*l);
    while(n>0)
    {
      r=r%10;
      n=n/10;
      array[p]=r;
      p++;
    }
    return p;
}
int getSum(int a,int b)
{
    int a_size,b_size,sum_size,sum1_size,sum=0;
    int* array_a,array_b;
    int a_size = factorial(a,array_a);
    int b_size= factorial(b,array_b);

    if(a_size >= b_size) sum_size = a_size;
    else sum_size = b_size;
    sum1_size = sum_size;
    int* array_sum=(int*)malloc(sizeof(int)*sum_size);
    array_sum[sum_size]=0;
    for( ;  a_size<0 || b_size<0;  a_size--,b_size--)
    {
        array_sum[sum_size-1]=array_sum[sum_size-1]+((array_a[a_size-1])XOR(array_b[b_size-1]));
        carry = ((array_a[a_size-1])&(array_b[b_size-1]));
        if(array_sum[sum_size-1]==0 && carry==1)
        {
            array_sum[sum_size-2]=1;
        }
        sum_size--;
    }
    while(a_size>=0)
    {
       array_sum[a_size]=array_a[a_size];
       a_size--; 
    }
    while(b_size>=0)
    {
        array_sum[b_size]=array_b[b_size];
        b_size--;
    }
    for(int i=0;i<sum1_size-1;i++) 
    {
        sum=sum+array_sum[sum1_size-1]*pow(2,i);
        sum1_size--;
    }
    return sum1_size;
}

