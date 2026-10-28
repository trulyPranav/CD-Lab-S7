%{
#include <stdio.h>
int yylex();
int yyerror(const char *s);
%}
%define api.value.type {double}
%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
input :
      | input line
      ;
line  : '\n'
      | expr '\n'     { printf("Result = %g\n", $1); }
      | error '\n'    { yyerrok; }
      ;
expr  : expr '+' expr { $$ = $1 + $3; }
      | expr '-' expr { $$ = $1 - $3; }
      | expr '*' expr { $$ = $1 * $3; }
      | expr '/' expr {
                          if ($3 == 0)
                          {
                              printf("Division by zero\n");
                              YYERROR;
                          }
                          $$ = $1 / $3;
                      }
      | '(' expr ')'  { $$ = $2; }
      | '-' expr %prec UMINUS { $$ = -$2; }
      | NUMBER
      ;
%%
int main()
{
    printf("Enter expressions (Ctrl+Z to stop):\n");
    yyparse();
    return 0;
}
int yyerror(const char *s)
{
    printf("Invalid expression\n");
    return 0;
}
