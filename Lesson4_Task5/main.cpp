//Дана строка символов. Удалить из нее все слова нечетной длины.
//Слова отделяются друг от друга одним пробелом.

#include <stdio.h>

int main()
{
    constexpr int size = 255;

    char str[size];

    printf("Enter a string: ");
    gets(str);

    char* ptrStr = str;
    char* temp = str;
    int cnt = 0;

    while(*temp)
    {
        if(*temp == ' ')
        {
            if(cnt & 0x1)
            {
                ++temp;
                ptrStr -= cnt;
                cnt = 0;
            }
            else
            {
                *ptrStr = *temp;
                ++temp;
                ++ptrStr;
                cnt = 0;
            }
        }
        ++cnt;
        *ptrStr = *temp;
        ++temp;
        ++ptrStr;
    }
    if(cnt & 0x1)
    {
        ptrStr -= cnt;
    }
    *ptrStr = '\0';
    printf("\nA new string: %s", str);

    return 0;
}