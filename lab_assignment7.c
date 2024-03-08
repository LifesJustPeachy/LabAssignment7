#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int data;
  int numswaps;
} element;

element *numSwapsBubbleSort(int *arr, int size) {
  element *swaps = (element *)malloc(sizeof(element) * size);

  for (int i = 0; i < size; i++) {
    swaps[i].data = arr[i];
    swaps[i].numswaps = 0;
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap elements
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        // Update swaps count
        swaps[j].numswaps++;
      }
    }
  }

  return swaps;
}

int numSwapsSelectionSort(int *arr, int size) {
  int numswaps = 0;

  for (int i = 0; i < size - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    // Swap elements
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;

    // Update swaps count
    numswaps++;
  }

  return numswaps;
}

void printSwaps(element *swaps, int size) {
  // Sort swaps array in ascending order
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (swaps[j].data > swaps[j + 1].data) {
        // Swap elements
        element temp = swaps[j];
        swaps[j] = swaps[j + 1];
        swaps[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < size; i++) {
    printf("%d: # of times %d is swapped\n", swaps[i].data, swaps[i].numswaps);
  }
}

int main() {
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int size1 = sizeof(array1) / sizeof(array1[0]);
  int size2 = sizeof(array2) / sizeof(array2[0]);

  // Bubble Sort
  element *bubble_swaps1 = numSwapsBubbleSort(array1, size1);
  element *bubble_swaps2 = numSwapsBubbleSort(array2, size2);

  // Selection Sort
  int selection_swaps1 = numSwapsSelectionSort(array1, size1);
  int selection_swaps2 = numSwapsSelectionSort(array2, size2);

  // Print results
  printf("array1:\n");
  printSwaps(bubble_swaps1, size1);
  printf("total # of swaps: %d\n\n", selection_swaps1);

  printf("array2:\n");
  printSwaps(bubble_swaps2, size2);
  printf("total # of swaps: %d\n", selection_swaps2);

  // Free allocated memory
  free(bubble_swaps1);
  free(bubble_swaps2);

  return 0;
}
