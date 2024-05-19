#include <iostream>
using namespace std;

void bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int* array, int size) 
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void rearrangeArray(int* array, int size)
{
    int* temp = new int[size];
    int index = 0;

    for (int i = 0; i < size; i++) 
    {
        if (array[i] < 0) 
        {
            temp[index++] = array[i];
        }
    }

      for (int i = 0; i < size; i++)
    {
        if (array[i] >= 0) 
        {
            temp[index++] = array[i];
        }
    }

    for (int i = 0; i < size; i++) 
    {
        array[i] = temp[i];
    }

    delete[] temp;
}

void printArray(int* array, int size) 
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() 
{
    const int size = 10;
    int array[size] = { 3, -1, 4, -9, 5, -7, 8, -2, 6, -5 };

    cout << "Original array:" << endl;
    printArray(array, size);

    rearrangeArray(array, size);
    cout << "Rearranged array:" << endl;
    printArray(array, size);

    int array1[size], array2[size];
   
    copy(begin(array), end(array), begin(array1));
    copy(begin(array), end(array), begin(array2));

    bubbleSort(array1, size);
    cout << "Array sorted with bubble sort:" << endl;
    printArray(array1, size);

    selectionSort(array2, size);
    cout << "Array sorted with selection sort:" << endl;
    printArray(array2, size);

    return 0;
}