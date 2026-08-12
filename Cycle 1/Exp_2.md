# Compiler Lab Experiment 1

Aim: Write a program to convert NFA with ε transitions to NFA without ε transitions.

## Algorithm

1. Start.
2. Define the maximum number of states as `MAX = 10`.
3. Read the number of states `n`.
4. Read the ε-transition matrix `e` of size `n × n`.
5. Read the transition matrix `t` of size `n × n` for one input symbol.
6. For each state `i` from `0` to `n-1`, initialize the `vis` array to `0`.
7. Find the ε-closure of state `i` using the `closure()` function.
8. Mark the current state as visited by setting `vis[s] = 1`.
9. Check every state `j` to determine whether an ε-transition exists from the current state.
10. If `e[s][j] = 1` and state `j` has not been visited, recursively find the ε-closure of state `j`.
11. Repeat Steps 9–10 until all states reachable through ε-transitions have been visited.
12. For every state `j` in the ε-closure of state `i`, check the transition matrix `t`.
13. If `t[j][k] = 1`, set `c[i][k] = 1`.
14. Repeat Steps 6–13 for all states.
15. Display the resulting NFA transition matrix `c`.
16. Stop.

## Program

```c
#include <stdio.h>
#define MAX 10
int n;
int e[MAX][MAX], t[MAX][MAX], c[MAX][MAX];
void closure(int s, int vis[])
{
    vis[s] = 1;
    for (int i = 0; i < n; i++)
        if (e[s][i] && !vis[i])
            closure(i, vis);
}
int main()
{
    printf("States: ");
    scanf("%d", &n);
    printf("Epsilon transition matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &e[i][j]);
    printf("Transition matrix (one symbol):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &t[i][j]);
    for (int i = 0; i < n; i++)
    {
        int vis[MAX] = {0};
        closure(i, vis);
        for (int j = 0; j < n; j++)
            if (vis[j])
                for (int k = 0; k < n; k++)
                    if (t[j][k])
                        c[i][k] = 1;
    }

    printf("NFA Transition Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}
```

## Output

![Exp 2 output](./Exp_2_output.png)