//Дана строка символов.
//Определить, является ли она правильным скобочным выражением.

#include <stdio.h>
#include "Bracket_Sequence.h"

int main()
{
    char str[50] = "()[()]{()([[{}]])()}";
    printf("An initial string is:\n%s\n", str);

    bool isCorBracSeq = isCorrectBracketSequence(str);
    printf(isCorBracSeq == true ? "\nIt is a correct sequence!"
                                : "\nIt is an incorrect bracket secuence!");

    return 0;
}
