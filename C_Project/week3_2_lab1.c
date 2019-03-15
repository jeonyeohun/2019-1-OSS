#include <stdio.h>
#include <stdlib.h>

int *input (int size){
  int* arr = (int*)malloc(sizeof(int)*size);
  for (int i=0 ; i<size ; i++){
    printf("점수 %d 입력: ", i+1);
    scanf("%d", &arr[i]);
  }

  return arr;
}

void sum (int * s, int size){
  int sum = 0;
  for(int i=0 ; i<size ; i++){
    sum += s[i];
  }

  printf("Total : %d", sum);
}

int main (){
  int *score;
  int size;
  printf("점수는 몇개 입력: ");
  scanf("%d", &size);

  score = input (size);
  sum(score, size);
  return 0;
}
