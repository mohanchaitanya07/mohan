#include <stdio.h>
#include <stdlib.h>
typedef student
{
    int rollnum;
    char grade;
    float percentage;
    student *next;
}
student;
int count[7] = {0, 0, 0, 0, 0, 0, 0};
void list(student *head, unsigned int n);
void print(student *head);
void arraylist(student *head, student **gradelist);
void printarraylist(student **gradelist);
void freememory(student *node, student **gradelist);
char grading(float p);

int main()
{
    student *head = (student *)malloc(sizeof(student));
    if (head == NULL)
    {
        printf("no memory allocated");
        return 1;
    }
    unsigned int n;
    printf("enter no of students:");
    scanf("%u", &n);
    list(head, n);
    printf("\nstudents list and grade are:\n");
    print(head);
    student **gradelist = (student **)malloc(7 * sizeof(student *));
    for (int i = 0; i < 7; i++)
    {
        gradelist[i] = (student *)malloc(sizeof(student));
        if (gradelist == NULL)
        {
            printf("no memory allocated");
            exit(0);
        }
        gradelist[i]->next = NULL;
    }
    arraylist(head, gradelist);
    printarraylist(gradelist);
    freememory(head, gradelist);
}
void list(student *head, unsigned int n)
{
    if (n == 0)
    {
        exit(0);
    }
    int i = 1;
    head->rollnum = i;
    head->percentage = ((1000 + random() % 9001)) * 0.01;
    head->grade = grading(head->percentage);
    head->next = NULL;
    for (int i = 2; i <= n; i++)
    {
        student *temp = (student *)malloc(sizeof(student));
        if (temp == NULL)
        {
            printf("no memory allocated");
            exit(0);
        }
        head->next = temp;
        head = temp;
        head->rollnum = i;
        head->percentage = ((1000 + (random() % 9001)) * 0.01);
        head->grade = grading(head->percentage);
        head->next = NULL;
    }
}
void print(student *head)
{
    for (head; head != NULL; head = head->next)
    {
        printf("student roll number:%d - percentage:%f - grade: %c \n", head->rollnum, head->percentage, head->grade);
    }
}
char grading(float percent)
{
    if (percent >= 90)
    {
        return 'A';
    }
    else if (percent < 90 && percent >= 80)
    {
        return 'B';
    }
    else if (percent < 80 && percent >= 70)
    {
        return 'C';
    }
    else if (percent < 70 && percent >= 60)
    {
        return 'D';
    }
    else if (percent < 60 && percent >= 50)
    {
        return 'E';
    }
    else if (percent < 50 && percent >= 35)
    {
        return 'P';
    }
    else
    {
        return 'F';
    }
}
char matchgrade(int index)
{
    char grading[7] = {'A', 'B', 'C', 'D', 'E', 'P', 'F'};
    for (int i = 0; i < 7; i++)
    {
        if (i == index)
        {
            return grading[i];
        }
    }
}
int matchindex(char grade)
{
    char grading[7] = {'A', 'B', 'C', 'D', 'E', 'P', 'F'};
    for (int i = 0; i < 7; i++)
    {
        if (grading[i] == grade)
        {
            return i;
        }
    }
}
void arraylist(student *head, student **gradelist)
{
    for (head; head != NULL; head = head->next)
    {
        student *flag_head = NULL;
        int i = matchindex(head->grade);
        flag_head = gradelist[i];
        if (count[i] == 0)
        {
            flag_head->rollnum = head->rollnum;
            flag_head->percentage = head->percentage;
            flag_head->grade = head->grade;
            flag_head->next = NULL;
            count[i]++;
        }
        else
        {
            while (flag_head->next != NULL)
            {
                flag_head = flag_head->next;
            }
            student *temp = (student *)malloc(sizeof(student));
            flag_head->next = temp;
            flag_head = temp;
            flag_head->rollnum = head->rollnum;
            flag_head->percentage = head->percentage;
            flag_head->grade = head->grade;
            flag_head->next = NULL;
            count[i]++;
        }
    }
}
void printarraylist(student **gradelist)
{
    for (int i = 0; i < 7; i++)
    {
        if (count[i] == 0)
        {
            continue;
        }
        printf("students who got '%c' grade:\n", matchgrade(i));
        print(gradelist[i]);
        printf("\n");
    }
}
void freememory(student *head, student **gradelist)
{
    while (head != NULL)
    {
        student *temp = head->next;
        free(head);
        head = temp;
    }
    for (int i = 0; i < 7; i++)
    {
        student *flag_head = gradelist[i];
        while (flag_head != NULL)
        {
            student *temp = flag_head->next;
            free(flag_head);
            flag_head = temp;
        }
    }
    free(gradelist);
}