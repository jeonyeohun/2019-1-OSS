#include <stdio.h>
#define SIZE 10

int maxNum(int*num, int size){
  int max=0;
  for(int i=0 ; i<size ; i++){
    if(max<num[i]){
      max = num[i];
    }
  }
  return max;
}

void input(int* num){
  for(int i=0 ; i<SIZE ; i++){
    printf("%d번 숫자 입력 : ", i+1);
    scanf("%d", &num[i]);
  }
}

int main(void){
  int num[SIZE];

  input(num);
  printf("최대값은 %d\n", maxNum(num, SIZE));

  return 0;
}
