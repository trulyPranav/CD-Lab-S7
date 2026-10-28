#include <stdio.h>
#include <ctype.h>
char s[50];
int pos = 0;
int E();
int F()
{
    if (isalnum(s[pos]))
    {
        pos++;
        return 1;
    }
    if (s[pos] == '(')
    {
        pos++;
        if (!E())
            return 0;
        if (s[pos] == ')')
        {
            pos++;
            return 1;
        }
    }
    return 0;
}
int Tp()
{
    if (s[pos] == '*' || s[pos] == '/')
    {
        pos++;
        if (!F())
            return 0;
        return Tp();
    }
    return 1;
}
int T()
{
    return F() && Tp();
}
int Ep()
{
    if (s[pos] == '+' || s[pos] == '-')
    {
        pos++;
        if (!T())
            return 0;
        return Ep();
    }
    return 1;
}
int E()
{
    return T() && Ep();
}
int main()
{
    printf("Enter an expression: ");
    scanf("%s", s);
    if (E() && s[pos] == '\0')
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
}
