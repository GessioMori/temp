#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int arr[], int n)
{
  int i, j, k, interactions = 0;
  for (i = 1; i < n; i++)
  {
    k = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > k)
    {
      arr[j + 1] = arr[j];
      j--;
      interactions++;
    }
    arr[j + 1] = k;
  }
  return interactions;
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

  int length = 1000;
  int numOfArrays = 1000;

  int arr[length];
  int arrOfInteractions[numOfArrays];

  for (int i = 0; i < numOfArrays; i++)
  {
    createRandomArray(arr, length);
    arrOfInteractions[i] = insertionSort(arr, length);
  }

  int sum = 0;

  for (int i = 0; i < numOfArrays; i++)
  {
    sum += arrOfInteractions[i];
  }

  printf("Average number of interactions: %d\n", sum / numOfArrays);

  return 0;
}
