
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define M 50000

double diffTime(time_t end, time_t start)
{
  return (end - start);
}

void startArray(int *array)
{
  int i;
  for (i = 0; i < M; i++)
  {
    array[i] = 1 + (rand() % 5000);
  }
}

int binarySearch(int *arr, int size, int seed)
{
  int start = 0;
  int middle;
  int end = size - 1;

  while (start <= end)
  {
    middle = ((start + end) / 2);
    if (seed < arr[middle])
    {
      end = middle - 1;
    }
    else if (seed > arr[middle])
    {
      start = middle + 1;
    }
    else
    {
      return middle;
    }
  }
  return -1;
}

void CocktailSort(int* list)
{
  int length, bottom, top, swapped, i, aux;
  length = M;
  bottom = 0;
  top = length - 1;
  swapped = 0;

  while ((swapped == 0) && (bottom < top))
  {
    swapped = 1;

    for (i = bottom; i < top; i++)
    {

      if (list[i] > list[i + 1])
      {
        aux = list[i];
        list[i] = list[i + 1];
        list[i + 1] = aux;
        swapped = 0;
      }
    }
    top = top - 1;

    for (i = top; i > bottom; i = i - 1)
    {

      if (list[i] < list[i - 1])
      {

        aux = list[i];
        list[i] = list[i - 1];
        list[i - 1] = aux;
        swapped = 0;
      }
    }
    bottom++;
  }
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int* arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}

void print_array(int *arr, int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(int argc, char **argv)
{
  time_t start, end;
  double dif;
  int i;
  int v[M] = {};
  int v2[M] = {};
  int result = -1;
  srand(time(NULL));

  startArray(v);
  startArray(v2);
  //print_array(v2, M);

  //time(&start);
  //CocktailSort(v);
  //time(&end);
  //dif = difftime(end, start);
  //printf("Sorting time %f\n", dif);

  time(&start);
  print_array(v2, 50);
  quickSort(v2, 0, M-1);
  print_array(v2, 50);
  time(&end);
  dif = difftime(end, start);
  printf("Sorting time %f\n", dif);

  // print_array(v, M);

  // printf("searching for: %d \n", v[5]);

  // time(&start);
  // result = binarySearch(v, M, v[5]);
  // time(&end);

  // dif = difftime(end, start);
  // printf("Searching time %f\n", dif);

  // if (result != -1)
  // {
  //   printf("The {%d} is the %d element on the array\n", v[result], result + 1);
  // }
  // else
  // {
  //   printf("Nao foi encontrado o elemento procurado");
  // }
  // print_array(v, M);

  return 0;
}
