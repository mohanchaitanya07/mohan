#include <stdio.h>
#include <stdlib.h>
void initialization(int m, int n, int *matrix);
void encryption(int m, int n, int *matrix); //encryption declaration
void decryption(int m, int n, int *matrix); //decryption declaration
void print(int m, int n, int *matrix);
int main()
{
    int m, n;
    printf("enter order of matrix\n");
    scanf("%d%d", &m, &n); //m*n=row*column
    int *matrix = (int *)malloc(m * n * sizeof(int));
    initialization(m, n, matrix);
    encryption(m, n, matrix);
    decryption(m, n, matrix);
    free(matrix);
}
void initialization(int m, int n, int *matrix)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *((matrix + j) + (i * n)) = rand() % 1000; //generating and sending
        }
    }
    printf("matrix is:\n");
    print(m, n, matrix);
}
void print(int m, int n, int *matrix)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", *((matrix + j) + (i * n)));
        }
        printf("\n");
    }
}
void encryption(int m, int n, int *matrix)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                *((matrix + j) + (i * n)) += i + 1; //borders
            else
                *((matrix + j) + (i * n)) -= (i + j + 2); //non borders
        }
    }
    printf("encrypted matrix is:\n");
    print(m, n, matrix);
}

void decryption(int m, int n, int *matrix)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                *((matrix + j) + (i * n)) -= i + 1;
            else
                *((matrix + j) + (i * n)) += (i + j + 2);
        }
    }
    printf("decrypted matrix is:\n");
    print(m, n, matrix);
}