#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define min(a, b) (a < b ? a : b)
#define max(a, b) (b < a ? a : b)
#define ElementType unsigned
#define Key(x) (x)
#define IsLess(a, b) (a < b)
#define Swap(a, b)  \
    {               \
        ElementType temp = a; \
        a = b;      \
        b = temp;      \
    }
#define CompareAndSwap(a, b) \
    if (IsLess(b, a))   \
    Swap(a, b)

int Partition(ElementType *array, int left, int right)
{
    ElementType pivot = array[right];
    int j = left;
    for (int k = left; k < right; k++)
        if (IsLess(array[k], pivot))
        {
            Swap(array[k], array[j]);
            j++;
        }
    Swap(array[j], array[right]);
    return j;
}

void QuickSortMedianOfThree(ElementType *array, int left, int right)
{
    if (right - left <= 32)
        return;

    Swap(array[(left + right) / 2], array[right - 1]);
    CompareAndSwap(array[left], array[right - 1]);
    CompareAndSwap(array[left], array[right]);
    CompareAndSwap(array[right - 1], array[right]);

    int partitionIndex = Partition(array, left, right);
    QuickSortMedianOfThree(array, left, partitionIndex - 1);
    QuickSortMedianOfThree(array, partitionIndex + 1, right);
}

void InsertionSort(ElementType *array, int left, int right)
{
    for (int i = left + 1, j; i <= right; i++)
    {
        ElementType temp = array[i];
        for (j = i; j > 0 && IsLess(temp, array[j - 1]); j--)
            array[j] = array[j - 1];
        array[j] = temp;
    }
}

void QuickSort(ElementType *array, int left, int right)
{
    QuickSortMedianOfThree(array, left, right);
    InsertionSort(array, left, right);
}

void QuickSelect(ElementType *array, int left, int right, int index)
{
    if (index < left || index > right)
        return;

    CompareAndSwap(array[(left + right) / 2], array[right]);
    CompareAndSwap(array[left], array[(left + right) / 2]);
    CompareAndSwap(array[right], array[(left + right) / 2]);

    int partitionIndex = Partition(array, left, right);
    if (partitionIndex > index)
        QuickSelect(array, left, partitionIndex - 1, index);
    else if (partitionIndex < index)
        QuickSelect(array, partitionIndex + 1, right, index);
}

void Solve()
{
    int arraySize, percentile, multiplier;
    scanf(" %d %d %d", &arraySize, &percentile, &multiplier);
    unsigned *array = malloc(arraySize * sizeof(unsigned));
    for (int i = 0; i < arraySize; i++)
        scanf(" %u", array + i);

    QuickSelect(array, 0, arraySize - 1, min(arraySize - 1, percentile * multiplier));
    QuickSelect(array, 0, arraySize - 1, min(arraySize - 1, (percentile + 1) * multiplier - 1));
    QuickSort(array, min(arraySize - 1, percentile * multiplier), min(arraySize - 1, (percentile + 1) * multiplier - 1));

    for (int i = percentile * multiplier; i < min(arraySize, (percentile + 1) * multiplier); i++)
        printf("%u\n", array[i]);
}

int main()
{
    Solve();

    return 0;
}
