#include<stdio.h>

int maxSubArray(int* nums,int numsSize);
int findMaxSubArray(int* nums,int low,int high);
int findMaxCrossingSubArray(int* nums,int low,int mid,int high,int leftsum,int rightsum);

int main()
{
    int nums[9]={-2,1,-3,4,-1,2,1,-5,4};
    int t = maxSubArray(nums,9);
    printf("%d",t);
    return 0;
}
int maxSubArray(int* nums,int numsSize)
{
    if(numsSize==1)return nums[0];
    return findMaxSubArray(nums,0,numsSize-1);
}
int  findMaxSubArray(int* nums,int low,int high)
{
    int leftsum=0,rightsum=0,crosssum=0;
    if(high ==low)return nums[high];
    else 
    { 
        int mid = (low+high)/2;
        leftsum = findMaxSubArray(nums,low,mid);
        rightsum = findMaxSubArray(nums,mid+1,high);
        crosssum = findMaxCrossingSubArray(nums,low,mid,high,leftsum,rightsum);
    }
    if(leftsum>=rightsum && leftsum>=crosssum) return leftsum;
    else if(rightsum>=leftsum && rightsum>= crosssum) return rightsum;
    else return crosssum;
}

int findMaxCrossingSubArray(int* nums,int low,int mid,int high,int leftsum,int rightsum)
{
    int sum=0;
    for(int i = mid;i>=low;i--)
    {
        sum = sum+nums[i];
        if(sum > leftsum)
        {
            leftsum = sum;
        }
    }
    sum=0;
    for(int k = mid+1;k<high;k++)
    {
        sum =sum+ nums[k];
        if(sum>rightsum)
        {
            rightsum = sum;
        }
    }
    return leftsum+rightsum;
}
