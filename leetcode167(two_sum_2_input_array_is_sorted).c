#include<stdio.h>
//两种方法，但是时间都很长，还要更好的才行
#include<stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);
int main()
{
    int numbers[4]={2,7,11,15};
    int returnSize;
    int* arr = twoSum(numbers,4,9,&returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int l=10;
    *returnSize = 2;
    int* res=(int*)malloc(sizeof(int)*l);
    for(int i=0;i<numbersSize-1;i++)
    {
        int t = target - numbers[i];
        for(int j = i+1;j<numbersSize;j++)
        {
            if(numbers[j]==t)
            {
                res[0]=i+1;
                res[1]=j+1;
                return res;
                
            }
        }
    }
}
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* res=(int*)malloc(sizeof(int)*(*returnSize));
    int i=0;
    while(numbers[i]<=target/2)
    {
        int t = target-numbers[i];
        for(int j=i+1;j<numbersSize;j++)
        {
            if(numbers[j]==t)
            {
                res[0]=i+1;
                res[1]=j+1;
                return res;
            }
        }
        i++;
    }

}
