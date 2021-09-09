#include<stdio.h>
#include<stdlib.h>
int max, car_count = 0;
struct queue
{
  int car;
  struct queue *link;
};
struct queue *front = NULL;
struct queue *rear = NULL;
struct queue *header = NULL;
//special header node to store number of cars in the parking lot
struct stack
{
  int data;
  struct stack *next;
};
struct stack *top = NULL;
//push function to store car tokens in stack while deleting a car at the sepecific location
void push(int car_num)
{
  struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
  if (temp == NULL)
  {
    printf(" \n OVERFLOW IN STACK \n ");
    exit(0);
  }
  temp->data = car_num;
  temp->next = top;
  top = temp;
}
//pop which returns the stored car tokens in stack
int pop()
{
  int car_num;
  if (top == NULL)
  {
    printf(" \n UNDERFLOW IN STACK \n ");
    exit(1);
  }
  car_num = top->data;
  top = top->next;
  return car_num;
}
//inserts the car at the rear end
void insertion()
{
  int car_token;
  if (car_count > max)
    printf("Parking Lot FULL \n ");
  else
  {
    printf("Enter the token number of the car you wanna park: ");
    scanf("%d", &car_token);
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->car = car_token;
    new->link = NULL;
    if (front == NULL)
    {
      front = rear = new; //initial stage when there are no cars
      header = (struct queue *)malloc(sizeof(struct queue));
      header->link = front; //header link which stores the car-count
    }
    else
    {
      rear->link = new;
      rear = new; //rear moving forwards
    }
    header->car = car_count; //updating car count in header
  }
}
//deletes the car at the front end
void deletion_front()
{
  if (front == NULL)
  {
    printf(" \n ---------There are no cars----------- \n ");
  }
  else
  {
    struct queue *temp = front;
    header->link = front->link;
    front = front->link;
    --car_count;
    header->car = car_count;
    free(temp);
  }
}
//deletes the car at the specified location
void deletion_location(int location)
{
  int flag = 0; //to check whether desired token is found or not
  struct queue *prev = header;
  while (front != NULL)
  {
    if (front->car == location)
    {
      struct queue *temp = front;
      prev->link = front->link;
      front = front->link;
      flag = 1;
      --car_count;
      header->car = car_count;
      free(temp);
      break;
    }
    else
    {
      push(front->car); //stores token in stack
      front = front->link;
      prev = prev->link;
    }
  }
  while (top != NULL)
  {
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->car = pop(); //pops the car token from stack
    new->link = front;
    front = new;
  }
  header->link = front;
  //updating the header link due to changes or deletions
  if (flag == 0)
  {
    printf(" \n ------------Entered token numbered car is not there in the parking lot---------- \n ");
  }
}
void display()
{
  struct queue *temp = front;
  printf("\ntotal no of avilable cars in the  parking lot are: %d \n", header->car);
  printf("token number of Cars in the parking lot are: ");
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
int main()
{
  int choice = 1;
  int location;
  printf("Enter the size of parking lot: ");
  scanf("%d", &max);
  printf(" \n ");
  while (choice != 0)
  {

    printf("Enter 1 to Park a car into parking lot from rear end: \n ");
    printf("Enter 2 to leave the car from front end: \n ");
    printf("Enter 3 to display the cars in the parking lot: \n ");
    printf("Enter 4 to leave the car in the car in specific location(k): \n ");
    printf("Enter 0 to exit out of data: \n ");
    printf(" \n choice: ");
    scanf("%d", &choice);
    printf(" \n ");
    switch (choice)
    {
    case 0:
      break;
    case 1:
      ++car_count;
      insertion();
      printf(" \n ");
      break;
    case 2:
      deletion_front();
      printf(" \n ");
      break;
    case 3:
      printf(" \n ");
      display();
      printf(" \n ");
      break;
    case 4:
      printf(" \n Enter the token no.of the car you wanna leave from parking lot: ");
      scanf("%d", &location);
      deletion_location(location);
      printf(" \n ");
      break;
    default:
      printf(" \n ");
      printf("-------------Enter a valid choice: --------------- \n\n ");
      break;
    }
  }
  return 0;
}