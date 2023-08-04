//CPU SCHEDULING 
//priority scheduling
#include<stdio.h>
#include<string.h>
main()
{
int i,j,np,b[100],wt[100],tat[100],twt=0,temp,l,pr[10],t;
float awt=0.0;
char p[10][10],tem[10];
printf("ENTER NO OF PROCESS:");
scanf("%d",&np);
printf("ENTER PROCESS NAME:");
for(i=0;i<np;i++)
{
scanf("%s",p[i]);
}
for(i=0;i<np;i++)
{
printf("ENTER BURST TIME %s:",p[i]);
scanf("%d",&b[i]);
}
for(i=0;i<np;i++)
{
printf("ENTER %s PRIORITY:",p[i]);
scanf("%d",&pr[i]);
}
for(i=0;i<np-1;i++)
{
for(j=i+1;j<np;j++)
{
if(pr[i]>pr[j])
{
temp=b[i];
b[i]=b[j];
b[j]=temp;
strcpy(tem,p[j]);
strcpy(p[j],p[i]);
strcpy(p[i],tem);
t=pr[i];
pr[i]=pr[j];
pr[j]=t;
}
}
}
wt[0]=0;
for(i=1;i<np;i++)
{
wt[i]=wt[i-1]+b[i-1];
twt=twt+wt[i];
}
for(i=0;i<np;i++)
{
tat[i]=wt[i]+b[i];
}
awt=(float)twt/(float)np;
printf("\nPROCESS\t BURST TIME\tWAITING TIME\tTURN AROUND TIME:\n");
for(i=0;i<np;i++)
{
printf("%s\t %d\t\t%d\t\t%d\n",p[i],b[i],wt[i],tat[i]);
}
printf("TOTAL WAITING TIME:%d",twt);
printf("AVERAGE WAITING TIME:%f", awt);
}

