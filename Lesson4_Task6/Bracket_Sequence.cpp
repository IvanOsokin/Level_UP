#include <stdio.h>
#include "Bracket_Sequence.h"

bool isCorrectBracketSequence(char* seq)
{
    int cntSquareBracket = 0;
    int cntCircleBracket = 0;
    int cntCurlyBrace = 0;
    bool isCircleOpen = false;
    bool isSquareOpen = false;
    bool isCurlyOpen = false;
    bool isCorBracSeq = false;
    while(*seq)
    {
        if(cntSquareBracket < 0 || cntCircleBracket < 0 || cntCurlyBrace < 0)
        {
            printf("\nIt is an incorrect bracket secuence!");
            return false;
        }
        switch(*seq)
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
                    return false;
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
                    return false;
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
                    return false;
                }
                --cntCurlyBrace;
                isCircleOpen = true;
                isSquareOpen = true;
                isCurlyOpen = true;
                break;
        }
        ++seq;
    }
    (cntCircleBracket == 0 && cntSquareBracket == 0 && cntCurlyBrace == 0) ? isCorBracSeq = true : isCorBracSeq = false;

    return isCorBracSeq;
}
