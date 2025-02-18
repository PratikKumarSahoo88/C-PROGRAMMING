#include<stdio.h>
#include<string.h>

void main()
{
int i,k=0,n,j=6;
char s[100],res[100]="",a[100]="";
printf("enter the string:");

fgets(s,sizeof(s),stdin);
strcpy(res,"dlestx");
for(i=0;s[i]!='\0';i++)
{
if(s[i]=='d' &&  s[i+1]=='l' && s[i+2]=='e')
{
res[j]='d';
res[j+1]='l';
res[j+2]='e';
j=j+3;
}
res[j]=s[i];
j++;
}
strcat(res,"dleetx");
printf("Stuffed char:%s",res);
n=strlen(res);
for(i=6;i<n-6;i++)
{
if(s[i]=='d' &&  s[i+1]=='l' && s[i+2]=='e')
{
i=i+3;
}
a[k]=res[i];
k++;
}
printf("\nDestuffed char:%s",a);
}

