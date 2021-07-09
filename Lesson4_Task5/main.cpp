//Дана строка символов. Удалить из нее все слова нечетной длины.
//Слова отделяются друг от друга одним пробелом.

#include <stdio.h>
#include "My_String.h"

int main()
{
    char* initString = getString();
    char* resString = resultString(initString);

    printf("The result string: %s", resString);

    delete[] resString;
    resString = nullptr;
    delete[] initString;
    initString = nullptr;

    return 0;
}
