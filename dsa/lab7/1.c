#include <stdio.h>
#include <stdlib.h>
#define max 3
int queue[max];
int rear = -1, front = -1;
void enque(int value);
void deque();
void display();
int main()
{
    int option = 1, value;
    while (option < 4 && option > 0)
    {
        printf("enter 1 for inserting or enter 2 for deletion\n");
        printf("enter 3 for display or enter any key to exit\n");
        printf("enter your option:-\t");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter the value to insert:");
            scanf("%d", &value);
            enque(value);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        }
    }
    return 0;
}
void enque(int value)
{
    if (rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = value;
    }
    else if (front == (rear + 1) % max)
    {
        printf("\n---overflow---\n");
        exit(0);
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = value;
    }
}
void deque()
{
    if (front == -1)
    {
        printf("---underflow---");
        exit(0);
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("---queue is empty---\n");
    }
    else
    {
        printf("\nqueue is ---------------------------->\t");
        while (i <= rear)
        {
            printf(" %d \t", queue[i]);
            i = (i + 1) % max;
        }
        printf("\n");
    }
    printf("\n");
}