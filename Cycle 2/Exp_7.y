%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int yylex();
int yyerror(const char *s);
%}
%token LETTER DIGIT
%%
start : var '\n'    { printf("Valid variable\n"); exit(0); }
      ;
var   : LETTER rest
      ;
rest  : LETTER rest
      | DIGIT rest
      |
      ;
%%
int main()
{
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}
int yylex()
{
    int c = getchar();
    if (isalpha(c))
        return LETTER;
    if (isdigit(c))
        return DIGIT;
    if (c == EOF)
        return 0;
    return c;
}
int yyerror(const char *s)
{
    printf("Invalid variable\n");
    exit(0);
}
