#include<stdio.h>
#define MAX 10
int a[11]={123,56,66,4,5,89,99,0,58,44,12};
int b[10];
void merging (int low,int mid,int high)
{
    int l1,l2,i;
    for(l1=low,l2=mid+1,i=low;l1<=mid && l2<=high;i++)
    {
        if(a[l1]<=a[l2])
        b[i]=a[l1++];
        else
        b[i]=a[l2++];
    }
    while(l1<=mid)
    b[i++]=a[l1++];
    while(l2 <= high)   
      b[i++] = a[l2++];
    for(i=low;i<=high;i++)
    a[i]=b[i];

}
void sort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low + high)/2;
        sort(low,mid);
        sort(mid+1,high);
        merging(low,mid,high);
    }
    else{
        return;

    }
}
int main()
{
    int i;
   // printf("\n enter the unsorted sequence elements");
      //  for(i=0;i<MAX;i++)
//scanf("%d",&a[i]);
printf("list before sorting\n");
        for(i=0;i<MAX;i++)
printf("%d\n",a[i]);
sort(0,MAX);
 
        printf("\n list after sorting \n");
        for(i=1;i<=MAX;i++)
printf("%d\n",a[i]);
return (0);
        
}