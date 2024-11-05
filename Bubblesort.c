#include <stdio.h>

void bubblesort(int array[],int size) 
{
    for(int step=0;step<size-1;++step)
    {
        for(int i=0;i<size-step;++i)
        {
            if(array[i]>array[i+1])
            {
                int temp;
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
    
}
void print(int array[],int size)
{
    for(int i=0;i<size;++i)
    {
        printf("%d\n",array[i]);
    }
   
}
void main()
{
    int data[]={5,10,0,12,6};
    int size=(sizeof(data)/sizeof data[0]);
    bubblesort(data,size);
    printf("sorted array is:");
    print(data,size);
}