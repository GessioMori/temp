#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandomArray(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 20;
  }
}

void copyArray(int *arr, int *copy, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    copy[i] = arr[i];
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int *arr, int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void insertionSort(int *arr, int n)
{
  int i, j, k;
  for (i = 1; i < n; i++)
  {
    k = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > k)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = k;
  }
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

void merge(int *arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
  }

  for (j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main()
{
  system("clear");

  srand(time(NULL));

  int isRunning = 1;

  int length = 100000;

  int originalArr[length];
  int arr[length];

  createRandomArray(originalArr, length);

  copyArray(originalArr, arr, length);

  clock_t start, end;
  double cpu_time_used;

  int choice;

  while (isRunning)
  {
    printf("Choose a sorting algorithm:\n");
    printf("1. Create new random array\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      createRandomArray(originalArr, length);
      copyArray(originalArr, arr, length);
      system("clear");
      printf("New random array created!\n");
      printf("________________________________________\n");
      break;
    case 2:
      copyArray(originalArr, arr, length);
      start = clock();
      bubbleSort(arr, length);
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      system("clear");
      printf("Bubble Sort completed in: %f seconds\n", cpu_time_used);
      printf("________________________________________\n");
      break;
    case 3:
      copyArray(originalArr, arr, length);
      start = clock();
      insertionSort(arr, length);
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      system("clear");
      printf("Insertion Sort completed in: %f seconds\n", cpu_time_used);
      printf("________________________________________\n");
      break;
    case 4:
      copyArray(originalArr, arr, length);
      start = clock();
      selectionSort(arr, length);
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      system("clear");
      printf("Selection Sort completed in: %f seconds\n", cpu_time_used);
      printf("________________________________________\n");
      break;
    case 5:
      copyArray(originalArr, arr, length);
      start = clock();
      mergeSort(arr, 0, length - 1);
      end = clock();
      cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
      system("clear");
      printf("Merge Sort completed in: %f seconds\n", cpu_time_used);
      printf("________________________________________\n");
      break;
    case 6:
      isRunning = 0;
      break;
    default:
      system("clear");
      printf("Invalid choice!\n");
      printf("________________________________________\n");
      break;
    }
  }

  return 0;
}