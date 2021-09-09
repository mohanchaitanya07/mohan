#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node
{
  char data;
  struct node *link;
};
struct node *stack = NULL;
struct exp
{
  int num;
  struct exp *next;
};
struct exp *numbers = NULL;
int operator(char ch)
{
  int flag = 0;
  char op[] = {'+', '-', '/', '*', '^', '(', ')'};
  for (int i = 0; i < 7; i++)
  {
    if (ch == op[i])
      flag = 1;
  }
  if (flag)
    return 0;
  else
    return 1;
}
void strrev(char *str)
{
  int i = 0;
  int j = strlen(str) - 1;
  char temp;
  while (i < j)
  {
    temp = *(str + i);
    *(str + i) = *(str + j);
    *(str + j) = temp;
    ++i;
    --j;
  }
}
void printlist()
{
  printf("stack: \n");
  struct node *temp = stack;
  while (temp != NULL)
  {
    printf("%c", temp->data);
    temp = temp->link;
  }
  printf("\n");
}
void pushfn(char ch)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->data = ch;
  temp->link = stack;
  stack = temp;
}
void pushfn_num(int n)
{
  struct exp *temp = (struct exp *)malloc(sizeof(struct exp));
  if (temp == NULL)
  {
    printf("Overflow");
    exit(0);
  }
  temp->num = n;
  temp->next = numbers;
  numbers = temp;
}
char popfn()
{
  if (stack == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }
  char ch;
  ch = stack->data;
  stack = stack->link;
  return ch;
}
int popfn_num()
{
  if (numbers == NULL)
  {
    printf("UNDERFLOW");
    exit(0);
  }
  int n;
  n = numbers->num;
  numbers = numbers->next;
  return n;
}
int precedence(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '^')
    return 3;
  if (ch == '(' || ch == ')')
    return 4;
}
void prefix(char *str, char *exp)
{
  strrev(str);
  int s = 0, e = 0;
  for (s = 0; s < strlen(str); ++s)
  {
    if (*(str + s) == '(')
    {
      *(str + s) = ')';
    }
    else if (*(str + s) == ')')
    {
      *(str + s) = '(';
    }
    if (operator(*(str + s)))
    {
      *(exp + e) = *(str + s);
      ++e;
    }
    else if (*(str + s) == '(')
    {
      pushfn(*(str + s));
    }
    else if (*(str + s) == ')')
    {
      do
      {
        *(exp + e) = popfn();
        ++e;

      } while (stack->data != '(');
      popfn();
    }
    else
    {
      if (stack == NULL)
      {
        pushfn(*(str + s));
      }
      else if (precedence(*(str + s)) > precedence(stack->data))
      {
        pushfn(*(str + s));
      }
      else if (precedence(*(str + s)) == precedence(stack->data) && *(str + s) == '^')
      {
        while (precedence(*(str + s)) == precedence(stack->data) && *(str + s) == '^')
        {
          *(exp + e) = popfn();
          ++e;
        }
      }
      else if (precedence(*(str + s)) == precedence(stack->data))
      {
        pushfn(*(str + s));
      }
      else if (precedence(*(str + s)) < precedence(stack->data))
      {
        if (stack->data == '(')
        {
          pushfn(*(str + s));
          continue;
        }
        do
        {

          *(exp + e) = popfn();
          ++e;
        } while (stack != NULL && precedence(*(str + s)) < precedence(stack->data));
        pushfn(*(str + s));
      }
    }
  }
  --e;

  while (stack != NULL)
  {
    ++e;
    *(exp + e) = popfn();
  }
  ++e;
  *(exp + e) = '\0';
  strrev(exp);
}
int expression(int A, char ch, int B)
{
  if (ch == '+')
    return (A + B);
  if (ch == '-')
    return (A - B);
  if (ch == '*')
    return (A * B);
  if (ch == '/')
    return (A / B);
  if (ch == '^')
    return (pow(A, B));
}
int evaluate(char *exp)
{
  int value;
  int temp;
  char test;
  strrev(exp);
  for (int i = 0; i < strlen(exp); ++i)
  {
    if (operator(*(exp + i)))
    {
      test = *(exp + i);
      temp = atoi(&test);
      pushfn_num(temp);
    }
    else
    {
      value = expression(numbers->num, *(exp + i), numbers->next->num);
      popfn_num();
      popfn_num();
      pushfn_num(value);
    }
  }
  return value;
}
int sizer(char *str)
{
  int size = 0, i;
  for (i = 0; i < strlen(str); ++i)
  {
    if (*(str + i) == '(' || *(str + i) == ')')
      continue;
    ++size;
  }
  return size;
}
int main()
{
  char str[1000];
  printf("Enter the infix input:- ");
  scanf("%s", str);
  char exp[sizer(str)];
  prefix(str, exp);
  printf("Prefix of the above infix is: ");
  printf("%s", exp);
  int answer = evaluate(exp);
  printf("\nEvaluated answer is:- %d\n", answer);
  return 0;
}