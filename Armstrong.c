#include<stdio.h>
void main()
{
    int num,originalnum,rem,result=0;
    printf("enter the number:");
    scanf("%d",&num);
    originalnum=num;
    while(originalnum!=0)
    {
        rem=originalnum%10;
        result=result+rem*rem*rem;
        originalnum=originalnum/10;
    }
    if(result==num)
    printf("Armstrong Number");
    else
    printf("Not an Armstrong Number");
}