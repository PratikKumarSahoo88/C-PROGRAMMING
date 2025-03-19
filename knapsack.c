#include<stdio.h>
void knapsack(int [],int [],int,int);
void main(){
    int v[20],w[20],i,j,n,W;
    
    printf("No of objects=");
    scanf("%d",&n);
    printf("capacity of knapsack=");
    scanf("%d",&W);
    for(i=1;i<=n;i++)
    {
        printf("enter weight and value of object%d=",i);
        scanf("%d",&w[i]);
        scanf("%d",&v[i]);
    }
    knapsack(v,w,n,W);
}
void knapsack(int v[],int w[],int n,int W){
    int k[20][20],i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0){
                k[i][j]=0;
            }
            else if(j<w[i])
            {
                k[i][j]=k[i-1][j];
            }
            else{
                if(k[i-1][j]>k[i-1][j-w[i]]+v[i]){
                    k[i][j]=k[i-1][j];
                }
                else{
                    k[i][j]=k[i-1][j-w[i]]+v[i];
                }
            }
        }
    }
    for(i=0;i<=n;i++){
         for(j=0;j<=W;j++){
            printf("%d",k[i][j]);
         }
         printf("\n");
    }
    printf("-------------");
    printf("\n maximum possible profit=%d",k[n][W]);
    printf("\n      ");
}