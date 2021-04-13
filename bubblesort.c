#include<stdio.h>
int main()
{
    int n,a[20],i,j,b;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n-1;i++)
    for(j=1;j<=n-i;j++)
    {
    if(a[j]>a[j+1])
    {
        b=a[j+1];
        a[j+1]=a[j];
        a[j]=b;
    }
    }
    printf("the sorted ascending order is:\n");
     for(i=1;i<=n;i++)
printf("\t%d",a[i]);
printf("\nthe sorted descending order is:\n");
for(i=n;i>=1;i--)
printf("\t%d",a[i]);
return(0);
}