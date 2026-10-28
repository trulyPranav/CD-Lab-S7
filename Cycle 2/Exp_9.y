%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char label[20];
    struct node *left, *right;
};
#define YYSTYPE struct node *
int yylex();
int yyerror(const char *s);
struct node *newnode(char *label, struct node *l, struct node *r)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    strcpy(p->label, label);
    p->left = l;
    p->right = r;
    return p;
}
void printtree(struct node *p, int level)
{
    int i;
    if (p == NULL)
        return;
    for (i = 0; i < level; i++)
        printf("    ");
    printf("%s\n", p->label);
    printtree(p->left, level + 1);
    printtree(p->right, level + 1);
}
%}
%token ID NUM
%%
stmt   : expr '\n'          { printf("\nAbstract Syntax Tree:\n"); printtree($1, 0); }
       ;
expr   : expr '+' term      { $$ = newnode("+", $1, $3); }
       | expr '-' term      { $$ = newnode("-", $1, $3); }
       | term
       ;
term   : term '*' factor    { $$ = newnode("*", $1, $3); }
       | term '/' factor    { $$ = newnode("/", $1, $3); }
       | factor
       ;
factor : '(' expr ')'       { $$ = $2; }
       | ID
       | NUM
       ;
%%
int main()
{
    printf("Enter an expression: ");
    yyparse();
    return 0;
}
int yylex()
{
    int c, i = 0;
    char w[20];
    while ((c = getchar()) == ' ' || c == '\t');
    if (isalnum(c))
    {
        int isnum = isdigit(c);
        while (isalnum(c))
        {
            w[i++] = c;
            c = getchar();
        }
        w[i] = '\0';
        ungetc(c, stdin);
        yylval = newnode(w, NULL, NULL);
        return isnum ? NUM : ID;
    }
    if (c == EOF)
        return 0;
    return c;
}
int yyerror(const char *s)
{
    printf("Syntax error\n");
    return 0;
}
