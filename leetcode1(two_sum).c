#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target);
int main()
{
    int nums[4]={2,7,11,15};
    int* array = twoSum(nums,4,13);
    for(int i=0;i<2;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
int* twoSum(int* nums, int numsSize , int target)
{
    int* a=(int*)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j] == target)
            {
                a[0]=i;
                a[1]=j;
            }
        }
    }
    return a;
}
