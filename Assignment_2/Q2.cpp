// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
// the adjacent elements if they are in wrong order. Code the Bubble sort with the
// following elements:

#include <iostream>
using namespace std;

int Bubble_sort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "";
    }
}
int main()
{
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    Bubble_sort(arr, 7);
    print(arr, 7);

    return 0;
}
