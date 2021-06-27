//Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    constexpr int size = 40;

    int array[size];

    printf("An initial array:\n");
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 201 - 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    int maxElem = INT_MIN;
    int index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] > maxElem)
        {
            maxElem = array[i];
            index = i;
        }
    }

    bool isNegative = false;
    for(int i = size - 1; i >= 0 && !isNegative; --i)
    {
        if(array[i] < 0)
        {
            int temp = array[i];
            array[i] = maxElem;
            array[index] = temp;
            isNegative = true;
        }
    }

    if(isNegative)
    {
        printf("A new array:\n");
        for(int i = 0; i < size; ++i)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("There are no negative elements!");
    }

    return 0;
}
