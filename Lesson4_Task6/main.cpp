//Дана строка символов.
//Определить, является ли она правильным скобочным выражением.

#include <iostream>

int main()
{
    const char *str = "()[()]{()([[{}]])()}";
    printf("An initial string is:\n%s\n", str);

    int cntSquareBracket = 0;
    int cntCircleBracket = 0;
    int cntCurlyBrace = 0;
    bool isCircleOpen = false;
    bool isSquareOpen = false;
    bool isCurlyOpen = false;
    while(*str)
    {
        if(cntSquareBracket < 0 || cntCircleBracket < 0 || cntCurlyBrace < 0)
        {
            printf("\nIt is an incorrect bracket secuence!");
            return 1;
        }
        switch(*str)
        {
            case '(':
                ++cntCircleBracket;
                isCircleOpen = true;
                isSquareOpen = false;
                isCurlyOpen = false;
                break;
            case '[':
                ++cntSquareBracket;
                isCircleOpen = false;
                isSquareOpen = true;
                isCurlyOpen = false;
                break;
            case '{':
                ++cntCurlyBrace;
                isCircleOpen = false;
                isSquareOpen = false;
                isCurlyOpen = true;
                break;
            case ')':

                //Нельзя закрывать один тип скобок пока открыт другой
                if(!isCircleOpen)
                {
                    printf("\nIt is an incorrect bracket secuence!");
                    return 1;
                }
                --cntCircleBracket;
                isCircleOpen = true;
                isSquareOpen = true;
                isCurlyOpen = true;
                break;
            case ']':
                if(!isSquareOpen)
                {
                    printf("\nIt is an incorrect bracket secuence!");
                    return 1;
                }
                --cntSquareBracket;
                isCircleOpen = true;
                isSquareOpen = true;
                isCurlyOpen = true;
                break;
            case '}':
                if(!isCurlyOpen)
                {
                    printf("\nIt is an incorrect bracket secuence!");
                    return 1;
                }
                --cntCurlyBrace;
                isCircleOpen = true;
                isSquareOpen = true;
                isCurlyOpen = true;
                break;
        }
        ++str;
    }
    if(cntCircleBracket == 0 && cntSquareBracket == 0 && cntCurlyBrace == 0)
    {
        printf("\nIt is a correct sequence!");
    }
    else
    {
        printf("\nIt is an incorrect bracket secuence!");
    }
    return 0;
}
