#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void printArray(int *arr, int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selectionSort(int *arr, int n)
{
  int i, j, minIdx;
  for (i = 0; i < n - 1; i++)
  {
    minIdx = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIdx])
      {
        minIdx = j;
      }
    }
    swap(&arr[minIdx], &arr[i]);
  }
}

int createRandomArray(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
    arr[i] = rand() % 20;
}

int main()
{
  srand(time(NULL));

  int length = 10;

  int arr[length];

  createRandomArray(arr, length);

  printf("Array before sorting: \n");
  printArray(arr, length);

  selectionSort(arr, length);

  printf("Array after sorting: \n");
  printArray(arr, length);

  return 0;
}
