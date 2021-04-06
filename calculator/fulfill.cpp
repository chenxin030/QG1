#include"fulfill.h"
int level(char p)
{
    int l;
    switch (p)
    {
    case '+':
    case '-':l = 2; break;
    case '*':
    case '/':l = 3; break;
    case '(':l = 1; break;
    case '#':l = -1; break;
    }
    return l;
}

void  calculate(int *number, int* numberTop, char *symbol, int* symbolTop)
{
    char operation = symbol[(*symbolTop)];
    (*symbolTop)--;
    int value1 = number[(*numberTop)];
    (*numberTop)--;
    int value2 = number[(*numberTop)];
    (*numberTop)--;
    int temp;
    switch (operation)
    {
    case '+':temp = value2 + value1;  break;
    case '-':temp = value2 - value1; break;
    case '*':temp = value2 * value1; break;
    case '/':temp = value2 / value1; break;
    }
    (*numberTop)++;
    number[*numberTop] = temp;
}
int fun(char str[])
{
    char  symbol[MAX];
    int symbolTop = -1; 
    int numberTop = -1; 
    int  number[MAX];
    int  y = 0;
    int i = 0;
    symbol[++symbolTop] = '#';
    while (str[i]) {
        y = 0;
        if (str[i] <= '9' && str[i] >= '0') 
        {
            while (str[i] <= '9' && str[i] >= '0')
            {
                y = y * 10 + str[i] - '0';
                i++;
            }
            number[++numberTop] = y;
        }
        else if ((str[i] > '9' || str[i] < '0') && str[i] != '(' && str[i] != ')')
        {
            while (level(str[i]) <= level(symbol[symbolTop]))
                calculate(number, &numberTop, symbol, &symbolTop);
            symbol[++symbolTop] = str[i];
            i++;
        }
        else if (str[i] == '(')
        {
            symbol[++symbolTop] = '(';
            i++;
        }
        else if (str[i] == ')')
        {
            while (symbol[symbolTop] != '(') 
            {
                calculate(number, &numberTop, symbol, &symbolTop);
            }
            symbolTop--;
            i++;
        }
    }
    while (symbol[symbolTop] != '#') 
    {
        calculate(number, &numberTop, symbol, &symbolTop);
    }
    return number[numberTop];
}