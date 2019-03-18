//by heapsort
//too slow
void Build_Max_Heap(int *a, int len);
int Heapsort(int* a, int len);
void Max_Heapify(int *a, int key, int len);//to keep the max_heapify 

void Build_Max_Heap(int *a, int len)
{
    int heapsize=len;
    for(int i=heapsize/2;i>=0;i--)
    {
        Max_Heapify(a,i,len);
    }
}

void Max_Heapify(int *a, int key,int len)
{
    int largest;
    int l=key*2;
    int r=l+1;
    if(l<len && a[l]>a[key]) largest=l;
    else largest =key;
    if(r<len && a[r]>a[largest]) largest=r;
    if(largest != key)
    {
        int temp;
        temp=a[key];
        a[key]=a[largest];
        a[largest]=temp;
        Max_Heapify(a,largest,len);
    } 
}

int Heapsort(int *a ,int len)
{
    int b1[len];
    Build_Max_Heap(a,len);
    int heapsize=len,k=0;
    for(int i=len-1;i>=0;i--)
    {
        int temp=0;
        temp=a[0];
        a[0]=a[i];
        printf("%d ",temp);
        b1[k++]=temp;
        heapsize--;
        Max_Heapify(a,0,heapsize);
    }
    if(b1[len-1]*b1[len-2] > b1[1]*b1[2])
     {
            k=b1[0]*b1[len-1]*b1[len-2];
     }else
     {
            k=b1[0]*b1[1]*b1[2];
    }
    return k;
}


int maximumProduct(int* nums, int numsSize) {
    int k=1;
    if(numsSize<=3)
    {
        for(int i=0;i<numsSize;i++)
        {
            k=k*nums[i];
        }
    }
    else{
        k=Heapsort(nums, numsSize);
    }
    return k;
}


