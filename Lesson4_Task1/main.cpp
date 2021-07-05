//Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

int main()
{
    constexpr int size = 40;
    int array[size];
    initializingArray(array, size);

    int maxElem = INT_MIN;
    int index = 0;
    findMaxElem(array, size, &maxElem, &index);

    replacementLastNegAndMax(array, size, &maxElem, &index);

    return 0;
}
