#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isKeyword(char *s)
{
    char *keywords[] = {"int", "float", "char", "if", "else", "while", "for", "return"};
    int i;
    for (i = 0; i < 8; i++)
        if (strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}
int main()
{
    char code[200], word[50];
    int i = 0, j;
    printf("Enter the source code: ");
    fgets(code, 200, stdin);
    printf("\nTOKEN        TYPE\n");
    while (code[i] != '\0')
    {
        if (code[i] == ' ' || code[i] == '\t' || code[i] == '\n')
            i++;
        else if (isalpha(code[i]) || code[i] == '_')
        {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_')
                word[j++] = code[i++];
            word[j] = '\0';
            if (isKeyword(word))
                printf("%-12s Keyword\n", word);
            else
                printf("%-12s Identifier\n", word);
        }
        else if (isdigit(code[i]))
        {
            j = 0;
            while (isdigit(code[i]))
                word[j++] = code[i++];
            word[j] = '\0';
            printf("%-12s Number\n", word);
        }
        else if (strchr("+-*/%=<>!", code[i]))
        {
            word[0] = code[i++];
            word[1] = '\0';
            if (code[i] == '=' && strchr("=<>!", word[0]))
            {
                word[1] = '=';
                word[2] = '\0';
                i++;
            }
            printf("%-12s Operator\n", word);
        }
        else if (strchr("(){}[];,", code[i]))
        {
            printf("%-12c Delimiter\n", code[i]);
            i++;
        }
        else
        {
            printf("%-12c Invalid\n", code[i]);
            i++;
        }
    }
}
