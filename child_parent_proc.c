/*child process be assigned the task of 
checking if two input strings are Isomorphic strings and the parent be checking if two input strings 
are Anagrams */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
void sort(char *string)
{
char temp;
 int i, j;
 int n = strlen(string);
 for (i = 0; i < n-1; i++) {
 for (j = i+1; j < n; j++) {
 if (string[i] > string[j]) {
 temp = string[i];
 string[i] = string[j];
 string[j] = temp;
 }
 }
 }
}
void forkexample(char *str1, char *str2)
{
int flag = 0;
// child process because return value zero
if (fork() == 0)
{
printf("Hello from Child!-->");
if (strlen(str1) != strlen(str2))
{
printf("Not isomorphic");
}
int arr1[256] = { 0 }, arr2[256] = { 0 };
for (int i = 0; i < strlen(str1); i++)
{
// If current characters don't map
if (arr1[(int)str1[i]] != arr2[(int)str2[i]]) {
flag = 1;
}
arr1[(int)str1[i]]++;
arr2[(int)str2[i]]++;
}
if(flag == 0)
printf("ISOMPORPHIC Strings\n");
else
printf("NON-ISOMORPHIC Strings\n");
 
}
 
// parent process because return value non-zero.
else
{
printf("Hello from Parent!-->");
sort(str1);
sort(str2);
if (strlen(str1) != strlen(str2))
{
printf("Not isomorphic");
}
for (int i = 0; i < strlen(str1); i++)
{
// If current characters don't map
if (str1[i] != str2[i])
{
flag = 1;
}
}
if(flag == 0)
printf("ANAGRAMS\n");
else
printf("NOT ANAGRAMS\n");
 
}
}
int main()
{
char str1[] = "aab";
char str2[] = "xxy";
forkexample(str1,str2);
return 0;
}
