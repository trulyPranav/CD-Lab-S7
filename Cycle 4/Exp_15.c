#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50
int prec(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
int main()
{
    char in[MAX], post[MAX], ops[MAX], st[MAX][5];
    int i, k = 0, top = -1, sp = -1, t = 1;
    printf("Enter an assignment (single letter operands), e.g. a=b+c*d: ");
    scanf("%s", in);
    for (i = 2; in[i] != '\0'; i++)
    {
        if (isalnum(in[i]))
            post[k++] = in[i];
        else if (in[i] == '(')
            ops[++top] = '(';
        else if (in[i] == ')')
        {
            while (ops[top] != '(')
                post[k++] = ops[top--];
            top--;
        }
        else
        {
            while (top >= 0 && prec(ops[top]) >= prec(in[i]))
                post[k++] = ops[top--];
            ops[++top] = in[i];
        }
    }
    while (top >= 0)
        post[k++] = ops[top--];
    post[k] = '\0';
    printf("\nThree address code:\n");
    for (i = 0; i < k; i++)
    {
        if (isalnum(post[i]))
        {
            st[++sp][0] = post[i];
            st[sp][1] = '\0';
        }
        else
        {
            printf("t%d = %s %c %s\n", t, st[sp - 1], post[i], st[sp]);
            sp--;
            sprintf(st[sp], "t%d", t);
            t++;
        }
    }
    printf("%c = %s\n", in[0], st[sp]);
}
