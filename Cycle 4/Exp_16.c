#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
char line[MAX][50], vars[60][10];
int nv = 0;
void addVar(char *s)
{
    int i;
    if (isdigit(s[0]))
        return;
    for (i = 0; i < nv; i++)
        if (strcmp(vars[i], s) == 0)
            return;
    strcpy(vars[nv++], s);
}
int main()
{
    int n, i, count;
    char r[10], a[10], b[10], op;
    printf("Enter number of statements: ");
    scanf("%d", &n);
    getchar();
    printf("Enter the three address code (e.g. t1 = b * c):\n");
    for (i = 0; i < n; i++)
    {
        fgets(line[i], 50, stdin);
        count = sscanf(line[i], "%s = %s %c %s", r, a, &op, b);
        addVar(r);
        addVar(a);
        if (count == 4)
            addVar(b);
    }
    printf("\n.MODEL SMALL\n.STACK 100H\n.DATA\n");
    for (i = 0; i < nv; i++)
        printf("    %s DW ?\n", vars[i]);
    printf(".CODE\nMAIN PROC\n");
    printf("    MOV AX, @DATA\n    MOV DS, AX\n");
    for (i = 0; i < n; i++)
    {
        count = sscanf(line[i], "%s = %s %c %s", r, a, &op, b);
        printf("    MOV AX, %s\n", a);
        if (count == 4)
        {
            if (op == '+')
                printf("    ADD AX, %s\n", b);
            else if (op == '-')
                printf("    SUB AX, %s\n", b);
            else if (op == '*')
                printf("    MOV BX, %s\n    MUL BX\n", b);
            else if (op == '/')
                printf("    MOV DX, 0\n    MOV BX, %s\n    DIV BX\n", b);
        }
        printf("    MOV %s, AX\n", r);
    }
    printf("    MOV AH, 4CH\n    INT 21H\nMAIN ENDP\nEND MAIN\n");
}
