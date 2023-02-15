#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)
{
  printf("Swapping %d and %d...\n", *xp, *yp);
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

void bubbleSort(int arr[], int n)
{
  int i, j, k;
  k = 0;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
      else
      {
        printf("No swap between %d and %d\n", arr[j], arr[j + 1]);
      }
      k++;
      printf("Array after %d iteration: ", k);
      printArray(arr, n);
    }
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

  printf("Enter the length of the array: \n");

  int length;
  scanf("%d", &length);

  int *array = malloc(length * sizeof(int));

  if (!array)
  {
    exit(EXIT_FAILURE);
  }

  /*
  printf("1: %d\n", sizeof(array));
  printf("2: %d\n", sizeof(array[0]));
  */

  createRandomArray(array, length);

  printf("Unsorted array: \n");
  printArray(array, length);

  bubbleSort(array, length);

  printf("Sorted array: \n");
  printArray(array, length);

  free(array);
  return 0;
}
