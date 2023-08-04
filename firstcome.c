//CPU SCHEDULING
//FCFS
#include<stdio.h>
#include<string.h>
main()
{
int i,j,np,b[100],wt[100],tat[100],twt=0,temp,l,ttat=0;
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
printf("ENTER BURST TIME FOR %s:",p[i]);
scanf("%d",&b[i]);
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
ttat=ttat+tat[i];
}
awt=(float)twt/(float)np;
printf("\nPROCESS\t BURST TIME\tWAITING TIME\tTURN AROUND TIME:\n");
for(i=0;i<np;i++)
{
printf("%s\t%d\t\t%d\t\t%d\n",p[i],b[i],wt[i],tat[i]);
}
printf("TOTAL WAITING TIME:%d",twt);
printf("\nAVERAGE WAITING TIME:%f",awt);
printf("\ngantt chart:\n");
l=strlen(p[1]);
for(i=0;i<=tat[np-1]+(np*l);i++)
{
printf("-");
}
printf("\n|");
j=0;
for(i=1;i<=tat[np-1]+(np*l);i++)
{
if(i==tat[j])
{
printf("%s|",p[j]);
j++;
}
else
printf(" ");
}
printf("\n");
for(i=0;i<=tat[np-1]+(np*l);i++)
{
printf("-");
}
printf("\n0");
j=0;
for(i=1;i<tat[np-1]+(np*l);i++)
{
if(i==tat[j]+l*(j))
{
printf("%d",tat[j]);
j++;
}
else
printf(" ");
}
}

