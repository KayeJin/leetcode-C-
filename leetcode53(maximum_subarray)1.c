#include<stdio.h>
int max_subarray(int* nums, int numsSize);
int max(int a, int b);
int main()
{
    int array[9]={-2,1,-3,4,-1,2,1,-5,4};
    int res = max_subarray(array,9);
    printf("%d",res);
    return 0;
}
int max(int a, int b)
{
    if(a>=b)return a;
    else return b;
}
int max_subarray(int* nums, int numsSize)
{
    if(numsSize == 1)return nums[0];
    int max_ending = nums[0];
    int max_so_far = nums[0];
    for(int i = 1;i<numsSize;i++)
    {
        max_ending = max(nums[i],max_ending+nums[i]);
        max_so_far = max(max_so_far, max_ending);
    }
    return max_so_far;
}

