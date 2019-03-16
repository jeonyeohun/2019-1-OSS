#include <stdio.h>
#include <stdlib.h>

int main (){
  char **fruits;
  int n;

  printf("문자열 몇개? ");
  scanf("%d", &n);

  fruits = (char**)malloc(sizeof(char)*n);
  for(int i=0 ; i< n ; i++){
    *(fruits+i) = (char*)malloc(sizeof(char)*20);
  }

  for(int i =0 ; i<n ; i++){
    printf("문자열입력: ");
    scanf("%s", fruits[i]);
  }

  for(int i =0 ; i<n ; i++){
    printf("문장 %s\n", fruits[i]);
  }
  
  free(*fruits);
  free(fruits);
  return 0;
}
