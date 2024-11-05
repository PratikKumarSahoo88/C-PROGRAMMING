#include<stdio.h>
void main()
{
    int i,j,n,temp,num[50];
    printf("Enter the number ");
    scanf("%d",&n);
    printf("Enter the array elements");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
            for ( i = 1; i <= n; i++){
                for(j=i;j>0&&num[j-1]>num[j];j--)
                {
                    temp=num[j];
                    num[j]=num[j-1];
                    num[j-1]=temp;
                }
            }
             printf("The sorted element is");
    for ( i = 0; i < n; i++){
        printf("%d",num[i]);
    }

    }
    
}