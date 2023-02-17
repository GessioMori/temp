#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr, int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort(int arr[], int n)
{
  int i, j, k, interactions = 0;
  for (i = 1; i < n; i++)
  {
    k = arr[i];
    printf("Taking %d, in position %d as the key...\n", k, i);
    j = i - 1;
    while (j >= 0 && arr[j] > k)
    {
      arr[j + 1] = arr[j];
      j--;
      interactions++;
      printf("Moving %d to the right...\n", arr[j + 1]);
      printf("Array after this iteration: ");
      printArray(arr, n);
    }
    printf("Inserting %d to the right of %d...\n", k, arr[j]);
    arr[j + 1] = k;
  }
  printf("Total interactions: %d\n", interactions);
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

  int *array = malloc(length * sizeof(int));

  if (!array)
  {
    exit(EXIT_FAILURE);
  }

  createRandomArray(array, length);

  printf("Unsorted array: \n");
  printArray(array, length);

  insertionSort(array, length);

  printf("Sorted array: \n");
  printArray(array, length);

  free(array);
  return 0;
}
