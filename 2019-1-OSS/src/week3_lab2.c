#include <stdio.h>

void input(char* ch, int* size){
  printf("출력문자는?");
  scanf("%c", ch);
  printf("크기는?");
  scanf("%d", size);
}

void print (char ch, int size){
  int blankcnt = 0;
  int starcnt = size;

  for(int j = 0 ; j < size/2 ; j++){
    for(blankcnt = 0 ; blankcnt < j ; blankcnt++){
      printf(" ");
    }
    for(int i=0 ; i<starcnt ; i++){
      printf("%c", ch);
    }
    starcnt-=2;
    printf("\n");
  }

  for (int j = 0 ; j<size/2+(size%2) ; j++){
    for(int l=0 ; l<=blankcnt ; l++){
      printf(" ");
    }
    for(int i=0 ; i<starcnt ; i++){
      printf("%c", ch);
    }
    starcnt+=2;
    blankcnt--;
    printf("\n");
  }
}

int main (){
  char ch;
  int size;
  input(&ch, &size);
  print(ch, size);

  return 0;
}
