%{
#include <stdlib.h>
#include "Exp_8.tab.h"
%}
%option noyywrap
%%
[0-9]+(\.[0-9]+)?   { yylval = atof(yytext); return NUMBER; }
[ \t]               ;
\n                  { return '\n'; }
.                   { return yytext[0]; }
%%
