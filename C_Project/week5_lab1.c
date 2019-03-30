#include <stdio.h>
#include <stdlib.h>

void saveFile(char ** str, int cnt){
  FILE * fp;
  fp = fopen("word.txt", "wt");
  for (int i=0 ; i< cnt ; i++){
    fprintf(fp, "%s", str[i]);
  }
  fclose(fp);

}

int readFile(char **str){
  FILE * fp;
  int cnt=0;
  fp = fopen("word.txt", "rt");

  while(!feof(fp)){
    str[cnt] = (char*)malloc(sizeof(char)*20);
    fscanf(fp, "%s", str[cnt]);
    cnt++;
  }
  printf("\nFile read successfully!\n");
  fclose(fp);

  return cnt;
}

void input (char ** str, int cnt){
  printf("단어입력: ");
  scanf("%s", str[cnt]);
}

void print_list (char**word, int cnt){
  FILE * fp;
  fp = fopen("word.txt", "rt");

  for (int i=0 ; i< cnt ; i++){
      printf("단어 %d : %s\n", i+1, word[i]);
  }

}
int main (){
  char ** word;
  int op, cnt=0;
  FILE * fp = fopen("word.txt", "rt");
  word = (char**)malloc(sizeof(word)*100);
  *word = (char*)malloc(sizeof(word)*20);

  cnt = readFile(word);
  print_list(word, cnt);

  while(1){
    printf("**************\n1. 영어 단어 등록\n\n2. 단어 목록 보기\n\n3. 파일 저장하기\n\n4. 종료하기\n\n***************\n");
    scanf("%d", &op);

    if(op==4){
      saveFile(word, cnt);
      break;
      }
    switch(op){
      case 1:
        word[cnt+1] = (char*)malloc(sizeof(char)*20);
        input(word, cnt);
        cnt++;
        break;
      case 2:
        print_list(word, cnt);
        break;
      case 3:
        saveFile(word, cnt);
        break;
    }
  }
  return 0;
}
