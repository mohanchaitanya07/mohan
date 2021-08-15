#include <stdio.h>
studentinfo
{
   char student_name[20];
   int age;
   char roll[10];
   char address[100];
};
int main()
{
   studentinfo stu;
   printf("enter name:");
   scanf("%s", stu.student_name);
   printf("enter age:");
   scanf("%d", &stu.age);
   printf("enter your roll num:");
   scanf("%s", stu.roll);
   printf("enter address:");
   scanf("%s", stu.address);

   printf("\n studentinfo:\n");
   printf("name\t :%s \nage\t: %d", stu.student_name, stu.age);
   printf("\nroll number: %s \naddress \t : %s\n", stu.roll, stu.address);
}
