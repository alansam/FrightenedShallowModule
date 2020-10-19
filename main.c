#include <stdio.h>
#include <stdlib.h>

int remain(void);
void print_array(int * array, size_t array_l);
void bubbles(int * array, size_t array_l);

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
  int * array = calloc(n, sizeof(int));
  size_t array_l = n;
  int swap;
  size_t loc, num;
  int ptr, temp;
  printf("array max length: %zu\n", array_l);
  printf("enter %zu elements in array\n", n);
  for (size_t ctr1 = 0; ctr1 < n; ctr1++) {
    scanf("%d",&array[ctr1]);
  }
  printf("array contents\n");
  print_array(array, array_l);

  ptr = 0;
  printf("enter location where you want to insert an element\n");
  scanf("%zu", &loc);
  printf("enter value you want to enter\n");
  scanf("%zu", &num);
  while(ptr != loc) { //  why?
    ptr++;  //  TODO: just use loc, ptr is not nneeded.
  }
  ++array_l;
  printf("array max length: %zu\n", array_l);
  array = realloc(array, array_l * sizeof(*array));
  array[array_l - 1] = num;
  swap = array[ptr - 1];
  array[ptr - 1] = array[n];
  array[array_l - 1] = swap;
  printf("array after insert\n");
  print_array(array, array_l);

  //  Bubble sort
  bubbles(array, array_l);

  printf("sorted list in ascending order :\n");
  print_array(array, array_l);

  free(array);

  return 0;
}

void print_array(int * array, size_t array_l) {
  for (size_t j_ = 0; j_ < array_l; j_++) {
    printf("%d\n", array[j_]);
  }
}

inline
static
void swap(int * l_, int * r_) {
  int temp;
  temp = *l_;
  *l_ = *r_;
  *r_ = temp;
}

void bubbles(int * array, size_t array_l) {
  int temp;
  for (size_t k = 0; k <= array_l - 1; k++) {
    for (size_t l = 0; l < array_l - k - 1; l++) {
      if (array[l] > array[l + 1]) {
        swap(&array[l], &array[l + 1]);
      }
    }
  }
}
