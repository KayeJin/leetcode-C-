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
    int a_size,b_size,i=0,j=0;
    int* array_a,array_b;
    int a_size = factorial(a,array_a);
    int b_size= factorial(b,array_b);

    for( ;  a_size<0 || b_size<0;  a_size--,b_size--)
    {
        sum=((array_a[a_size-1])XOR(array_b[b_size-1]));
        carry = ((array_a[a_size-1])&(array_b[b_size-1]));
        if(sum==0 && carry==1)
        {

        }


    }
    
}


