#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct stack
{
	char data;
	struct stack *next;
};
struct stack *push(struct stack *top, char value)
{
	struct stack *flag = NULL;
	flag = (struct stack *)malloc(sizeof(struct stack));
	if (flag == NULL)
	{
		printf("no memory allocated");
		exit(0);
	}
	flag->data = value;
	flag->next = top;
	top = flag;
	return top;
}
struct stack *pop(struct stack *top)
{
	if (top == NULL)
	{
		return top;
	}
	else
	{
		struct stack *flag = top;
		top = top->next;
		char value = flag->data;
		free(flag);
	}
	return top;
}
int main()
{
	int n, i;
	printf("Enter the length of the string:- ");
	scanf("%d", &n);
	struct stack *top = NULL;
	char string[n + 1];
	srand(time(0));
	printf("generated string is:- ");
	for (i = 0; i < (n + 1); ++i)
	{
		if (i == n)
		{
			string[i] = '\0';
		}
		else
		{
			string[i] = rand() % 26 + 65 + rand() % 2 * 32;
			printf("%c", string[i]);
		}
	}
	if (n == 0)
	{
		printf("\nStack Underflow!!!");
		exit(0);
	}
	i = 0;
	while (i != n)
	{
		if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
		{
			top = pop(top);
		}
		else
		{
			top = push(top, string[i]);
		}

		if (top == NULL)
		{
			printf("\nStack Underflow!!!\n");
		}
		else
		{
			printf("\nTop of the stack : %c", top->data);
		}
		++i;
	}
	printf("\nfinal stack is :- ");
	while (top != NULL)
	{
		printf("%c ", top->data);
		top = top->next;
	}
	free(top);
	printf("\n");
	return 0;
}