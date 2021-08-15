#include<stdio.h>
#include<string.h>
int main()
{
int i,l,flag=0;
char str[10];
printf("enter a string\n");
scanf("%s",str);
     l=strlen(str);
for(i=0;i<l;i++)
if(str[i] != str[l-i-1])
   {
            flag = 1;
            break;
   }
  if (flag) 
    {
        printf("%s is not a palindrome", str);
    }    
    else 
    {
       printf("%s is a palindrome", str);
    }
    return 0;
}








