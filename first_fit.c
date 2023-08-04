//memory allocation technique-FIRST FIT
#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
int i, j;
int allocation[n];
{
allocation[i] = -1;
}
for (i = 0; i < n; i++) //here, n -> number of processes
{
for (j = 0; j < m; j++) //here, m -> number of blocks
{
if (blockSize[j] >= processSize[i])
{
// allocating block j to the ith process allocation[i] = j;
// Reduce available memory in this block. blockSize[j] -= processSize[i];
break; //go to the next process in the queue
}
}
}
printf("\nProcess No.\tProcess Size\tBlock no.\n"); for (int i = 0; i < n; i++)
{
printf(" %i\t\t\t", i+1); printf("%i\t", processSize[i]); if (allocation[i] != -1)
printf("%i", allocation[i] + 1);
else
printf("Not Allocated");
printf("\n");
}
}
int main()
{
int m; //number of blocks in the memory
int n; //number of processes in the input queue
int blockSize[] = {100, 500, 200, 300, 600};
int processSize[] = {212, 417, 112, 426};
m = sizeof(blockSize) / sizeof(blockSize[0]);
n = sizeof(processSize) / sizeof(processSize[0]);
firstFit(blockSize, m, processSize, n);
return 0 ;
}
