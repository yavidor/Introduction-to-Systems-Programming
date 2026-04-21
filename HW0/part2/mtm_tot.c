#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_square(int candidate) {
  for (int i = 0; i <= (candidate / 2) + 1; i++) {
    if (i * i == candidate) {
      printf("The number %d is a perfect square: %d=%d*%d\n", candidate,
             candidate, i, i);
      return true;
    }
  }
  return false;
}

int main() {
  printf("Enter size of input:\n");
  int size;
  scanf("%d", &size);
  if (size <= 0) {
    printf("Invalid size\n");
    return 0;
  }
  int *nums = (int *)malloc(sizeof(int) * size);
  if (nums == NULL) {
    return 0;
  }
  printf("Enter numbers:\n");
  for (int i = 0; i < size; i++) {
    if (scanf("%d", nums + i) != 1) {
      printf("Invalid number\n");
      free(nums);
      return 0;
    }
  }
  int counter = 0;
  for (int i = 0; i < size; i++) {
    if (check_square(nums[i])) {
      counter++;
    }
  }
  printf("Total number of perfect squares is %d\n", counter);
  free(nums);
  return 0;
}
