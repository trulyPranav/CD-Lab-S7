#include <stdio.h>

#define MAX 20

int matrix[MAX][MAX];
int closure[MAX];
int n;

void epsilon_closure(int state)
{
    int i;

    closure[state] = 1;

    for (i = 0; i < n; i++)
    {
        if (matrix[state][i] == 1 && closure[i] == 0)
        {
            epsilon_closure(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("\nEnter the epsilon transition matrix:\n");
    printf("(Enter 1 if epsilon transition exists, otherwise 0)\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEpsilon Closures:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            closure[j] = 0;
        }

        epsilon_closure(i);

        printf("\nE-closure(q%d) = { ", i);

        for (j = 0; j < n; j++)
        {
            if (closure[j] == 1)
            {
                printf("q%d ", j);
            }
        }

        printf("}");
    }

    printf("\n");

    return 0;
}