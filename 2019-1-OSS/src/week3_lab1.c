#include <stdio.h>

void input(char *name, int* score){
  char sub [3][20] = {"국어", "영어", "수학"};

  printf("학생 이름 입력: ");
  scanf("%s", name);
  for(int i=0 ; i< sizeof(sub)/sizeof(sub[0]); i++){
    printf("%s 점수 입력: ", sub[i]);
    scanf("%d", &score[i]);
  }
}

void print (char *name, int s){
  printf("%s 학생의 총 합계는 %d 이고, 평균은 %0.2f 입니다.", name, s, (float)(s/3));
}

int main (){
  char name[20];
  int score[3];
  int sum=0;
  input(name, score);

  for(int i=0 ; i< sizeof(score)/sizeof(int) ; i++){
    sum += score[i];
  }

  print(name, sum);

  return 0;
}
