#include <stdio.h>
#include <stdlib.h>
int max;
int count = 0;
void push(int car_num);
void enque();
int pop();
void deque();
void display();
void del_location(int location);
typedef struct queue
{
  int car;
  struct queue *link;
} queue;
typedef struct stack
{
  int data;
  struct stack *next;
} stack;
queue *rear = NULL;
queue *front = NULL;
queue *head = NULL;
stack *top = NULL;
int main()
{
  int choice = 1;
  int location;
  printf("Enter parking_lot size:- ");
  scanf("%d", &max);
  while (choice != 0)
  {
    printf("\tEnter 1 to Park a car in parking lot from rear end\n");
    printf("\tEnter 2 to leave car from front end\n");
    printf("\tEnter 3 to display the cars in the parking_lot\n");
    printf("\tEnter 4 to leave car which is at a specific location(k) \n");
    printf("\tEnter 0 to exit the data\n");
    printf("choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      break;
    case 1:
      ++count;
      enque();
      break;
    case 2:
      deque();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Enter token no of the car for leaving from parking lot: ");
      scanf("%d", &location);
      del_location(location);
      break;
    default:
      printf("Enter valid choice!\n");
      break;
    }
  }
  return 0;
}
void push(int car_num)
{
  stack *temp = (stack *)malloc(sizeof(stack));
  if (temp == NULL)
  {
    printf(" \nOVERFLOW error\n ");
    exit(0);
  }
  temp->data = car_num;
  temp->next = top;
  top = temp;
}
int pop()
{
  int car_num;
  if (top == NULL)
  {
    printf(" \nUNDERFLOW error\n ");
    exit(1);
  }
  car_num = top->data;
  top = top->next;
  return car_num;
}
void enque() //at rear end
{
  int token_num;
  if (count > max)
    printf("Parking Lot FULL \n ");
  else
  {
    printf("Enter the token number of the car for parking:- ");
    scanf("%d", &token_num);
    queue *new = (queue *)malloc(sizeof(queue));
    new->car = token_num;
    new->link = NULL;
    if (front == NULL)
    {
      front = rear = new;
      head = (queue *)malloc(sizeof(queue));
      head->link = front;
    }
    else
    {
      rear->link = new;
      rear = new;
    }
    head->car = count;
  }
}
void deque()
{
  if (front == NULL)
  {
    printf(" \nno cars in parking_lot! \n ");
  }
  else
  {
    queue *temp = front;
    head->link = front->link;
    front = front->link;
    --count;
    head->car = count;
    free(temp);
  }
}
void del_location(int location)
{
  int flag = 0;
  queue *prev = head;
  while (front != NULL)
  {
    if (front->car == location)
    {
      queue *temp = front;
      prev->link = front->link;
      front = front->link;
      flag = 1;
      --count;
      head->car = count;
      free(temp);
      break;
    }
    else
    {
      push(front->car);
      front = front->link;
      prev = prev->link;
    }
  }
  while (top != NULL)
  {
    queue *new = (queue *)malloc(sizeof(queue));
    new->car = pop();
    new->link = front;
    front = new;
  }
  head->link = front;
  if (flag == 0)
  {
    printf(" \n !!!desired token numbered car is not there in the parking lot!!!\n ");
  }
}
void display()
{
  queue *temp = front;
  printf("total no of avilable cars in parking lot are:- %d \n", head->car);
  printf("token number of Cars in parking lot are: ");
  if (temp == NULL)
  {
    printf("there is no cars in parking lot to display \n");
    exit(0);
  }
  else
  {
    while (temp != NULL)
    {
      printf(" %d ", temp->car);
      temp = temp->link;
    }
  }
  printf(" \n ");
}