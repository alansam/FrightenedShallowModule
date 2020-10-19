#include <stdio.h>
#include <stdlib.h>

int remain(void);

int main(void) {
  printf("FrightenedShallowModule\n");

  int RC = remain();

  return RC;
}

int remain(void) {
  size_t n;
  printf("enter number of elements in array\n");
  scanf("%zu", &n);
//  int array[n];
  int * array = calloc(n + 1, sizeof(int));
  size_t array_l = n + 1;
  int swap;
  size_t loc, num;
  int ptr, temp;
  printf("array max length: %zu\n", array_l);
  printf("enter %zu elements in array\n", n);
  for (size_t ctr1 = 0; ctr1 < n; ctr1++) {
    scanf("%d",&array[ctr1]);
  }
  printf("array contents\n");
  for (size_t j = 0; j < n; j++) {
    printf("%d\n", array[j]);
  }

  ptr = 0;
  printf("enter location where you want to insert an element\n");
  scanf("%zu", &loc);
  printf("enter value you want to enter\n");
  scanf("%zu", &num);
  while(ptr != loc) { //  why?
    ptr++;  //  TODO: just use loc, ptr is not nneeded.
  }
  array[n] = num;
  swap = array[ptr - 1];
  array[ptr - 1] = array[n];
  array[n] = swap;
  printf("array after insert\n");
  for (size_t j = 0; j <= n; j++) {
    printf("%d\n", array[j]);
  }

  //  Bubble sort
  for(size_t k = 0; k <= n; k++) {
    for(size_t l = 0; l < n - k; l++) {
      if(array[l] > array[l + 1]) {
        temp = array[l];
        array[l] = array[l + 1];
        array[l + 1] = temp;
      }
    }
  }

  printf("sorted list in ascending order :\n");
  for (size_t j = 0; j <= n; j++) {
    printf("%d\n", array[j]);
  }

  free(array);

  return 0;
}
