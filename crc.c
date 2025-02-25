#include<stdio.h>
#include<string.h>
void main()
{
char s[100],p[100],d[30];
int k,len,i;
printf("enter frame");
fgets(s,sizeof(s),stdin);
printf("enter gen");
fgets(d,sizeof(d),stdin);
k=strlen(d)-1;
len=strlen(s);
p[i]='0';
p[i]='\0';
printf("msg after appending %d zero bits:",k);
puts(p);
printf("order of process is:\n");
while(strlen(p)>k)
{
if(p[0]=='1')
for(i=0;d[i]!='\0';i++)
p[i]=(p[i]-'0')^(d[i]-'0')+'0';
else
for(i=0;p[i]!='\0';i++)
p[i]=p[i+1];
puts(p);
}
strcat(s,p);
puts("transmitted frame is:");
printf("\t \t");
puts(s);
}
