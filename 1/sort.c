#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createRandomArray(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 100000;
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
  int i, j, flag;
  for (i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        flag = 1;
      }
    }
    if (!flag)
      break;
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

  int *L = malloc(n1 * sizeof(int));
  int *R = malloc(n2 * sizeof(int));

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

  free(L);
  free(R);
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

void initMergeSort(int *arr, int n)
{
  mergeSort(arr, 0, n - 1);
}

int lomutoPartition(int *arr, int low, int high)
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

int hoarePartition(int *arr, int low, int high)
{
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while (1)
  {
    do
    {
      i++;
    } while (arr[i] < pivot);

    do
    {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
    {
      return j;
    }

    swap(&arr[i], &arr[j]);
  }
}

void lomutoQuickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int pi = lomutoPartition(arr, low, high);
    lomutoQuickSort(arr, low, pi - 1);
    lomutoQuickSort(arr, pi + 1, high);
  }
}

void initLomutoQuickSort(int *arr, int n)
{
  lomutoQuickSort(arr, 0, n - 1);
}

void hoareQuickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int pi = hoarePartition(arr, low, high);
    hoareQuickSort(arr, low, pi - 1);
    hoareQuickSort(arr, pi + 1, high);
  }
}

void initHoareQuickSort(int *arr, int n)
{
  hoareQuickSort(arr, 0, n - 1);
}

double calcFuncTime(void (*func)(int *, int), int *arr, int n)
{
  clock_t head, end;
  double cpu_time_used;

  head = clock();
  func(arr, n);
  end = clock();

  cpu_time_used = ((double)(end - head)) / CLOCKS_PER_SEC;

  return cpu_time_used;
}

int main()
{
  system("clear");

  srand(time(NULL));

  int isRunning = 1;

  int length = 10000000;

  int *originalArr = malloc(length * sizeof(int));
  int *arr = malloc(length * sizeof(int));

  createRandomArray(originalArr, length);

  copyArray(originalArr, arr, length);

  int choice;

  while (isRunning)
  {
    printf("Choose a sorting algorithm:\n");
    printf("1. Create new random array\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Lomuto's Quick Sort\n");
    printf("7. Hoare's Quick Sort\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      createRandomArray(originalArr, length);
      copyArray(originalArr, arr, length);
      system("clear");
      printf("New random array created with %d elements\n", length);
      printf("________________________________________\n");
      break;
    case 2:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Bubble Sort with %d elements\n", length);
      printf("Bubble Sort completed in: %f seconds\n", calcFuncTime(bubbleSort, arr, length));
      printf("________________________________________\n");
      break;
    case 3:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Insertion Sort with %d elements\n", length);
      printf("Insertion Sort completed in: %f seconds\n", calcFuncTime(insertionSort, arr, length));
      printf("________________________________________\n");
      break;
    case 4:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Selection Sort with %d elements\n", length);
      printf("Selection Sort completed in: %f seconds\n", calcFuncTime(selectionSort, arr, length));
      printf("________________________________________\n");
      break;
    case 5:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Merge Sort with %d elements\n", length);
      printf("Merge Sort completed in: %f seconds\n", calcFuncTime(initMergeSort, arr, length));
      printf("________________________________________\n");
      break;
    case 6:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Lomuto's Quick Sort with %d elements\n", length);
      printf("Lomuto's Quick Sort completed in: %f seconds\n", calcFuncTime(initLomutoQuickSort, arr, length));
      printf("________________________________________\n");
      break;
    case 7:
      copyArray(originalArr, arr, length);
      system("clear");
      printf("Running Hoare's Quick Sort with %d elements\n", length);
      printf("Hoare's Quick Sort completed in: %f seconds\n", calcFuncTime(initHoareQuickSort, arr, length));
      printf("________________________________________\n");
      break;
    case 8:
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