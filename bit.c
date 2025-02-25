#include<stdio.h>
#include<string.h>
int main(){
int n,i,j=8,c=0,c1=0,k=8;
char s[100],res[100];
printf("Enter string:");
scanf("%s",s);
n=strlen(s);
strcpy(res,"01111110");
strcat(res,"");
for(i=0;i<n;i++){
res[j]=s[i];
j++;
if(s[i]=='1')
{
c+=1;
if(c==5){
res[j]='0';
j++;
c=0;
}}
else{
c=0;
}}
strcat(res,"01111110");
printf("Stuffed string:");
printf("%s",res);
printf("\nDestuffed string:");
for(i=8;i<strlen(res)-8;i++)
{
if(res[i]=='1'){
c1++;
}
else{
c1=0;
}
printf("%c",res[i]);
if(c1==5){
i++;
c1=0;
}}
res[i]='\0';
}
