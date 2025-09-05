#include "main.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdint.h"

int main(int argc, char *argv[]) {
  char *Stack = "stack_overflow";
  char *MemoryLeak = "memory_leak";
  char *OutMemory = "out_of_memory";
  int i = 0;
  if (argc != 2) {
    printf("Usage: main [memory error] - "
           "stack_overflow/memory_leak/out_of_memory");
    return 0;
  }
  if(strcmp(argv[1], Stack) == 0){
    stack_overflow(i);
  } else if (strcmp(argv[1], MemoryLeak)==0){
    printf("Memory Leak\n");
    memory_leak();
  } else if (strcmp(argv[1], OutMemory) == 0){
    out_of_memory();
  }
}

void stack_overflow(int i) {
  i++;
  printf("level: %i\n", i);
  stack_overflow(i);
}


void memory_leak(){
  char * i = malloc(1000);
  if(i == NULL){
    printf("Failed to allocate memory");
    return;
      }
}

void out_of_memory(){
  char * i = malloc(SIZE_MAX);
  if(i == NULL){
    printf("Out of memory error");
  } else {
    free(i);
    printf("allocated successfully");
  }
}
