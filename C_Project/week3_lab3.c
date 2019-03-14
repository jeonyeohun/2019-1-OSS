#include <stdio.h>
void input(char *name, int *s){
  char subs [3][20] = {"국어", "영어", "수학"};
  printf("학생이름 입력: ");
  scanf("%s", name);
  for(int i=0 ; i<3 ; i++){
    printf("%s 점수 입력: ", subs[i]);
    scanf("%d", &s[i]);
  }
}

void print(char *name, int *s){
  int sum = 0;
  for(int i=0 ; i<3 ; i++){
    sum += s[i];
  }
  printf("%s 학생의 총 합계는 %d 이고, 평균은 %0.2f 입니다.\n", name, sum, (float)sum/3);
}

int main(){
  int score[3];
  char name[20];

  input(name, score);
  print(name, score);
  return 0;
}
