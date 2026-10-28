%{
#include <stdio.h>
#include <string.h>
%}
%option noyywrap
%%
.+      {
            if (strstr(yytext, "pran") == NULL)
                printf("Accepted\n");
            else
                printf("Rejected\n");
        }
\n      ;
%%
int main()
{
    printf("Enter strings (Ctrl+Z to stop):\n");
    yylex();
    return 0;
}
