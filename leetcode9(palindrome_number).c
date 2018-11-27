#include<stdio.h>
#include<stdlib.h>
//if true return 1;else return 0;
int isPalindrome(int x);
int main()
{
    int n;
    scanf("%d",&n);
    int t = isPalindrome(n);
    if(t==1)printf("true");
    if(t==0)printf("no");
    return 0;
}
int isPalindrome(int x)
{
    if(x<0) return 0;
    int r,l=20,p=0;
    int* array=(int*)malloc(sizeof(int)*l);
    while(x>0)
    {
        r=x%10;
        array[p]=r;
        p++;
        x=x/10;
    }
    for(int i=0;i<=p/2;i++)
    {
        if(array[i]!=array[p-1-i])
        {
            return 0;
        }
    }
    free(array);
    return 1;

}

