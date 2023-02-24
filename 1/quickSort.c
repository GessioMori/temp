#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

int partition(int *arr, int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  int j;
  for (j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int A[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
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

  quickSort(arr, 0, length - 1);

  printf("Array after sorting: \n");
  printArray(arr, length);

  return 0;
}
