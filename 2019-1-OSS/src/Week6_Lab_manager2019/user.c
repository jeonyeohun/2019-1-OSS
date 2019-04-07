#include "user.h"

int load_file(LOGIN* list[], char* filename){
  int count=0;
  char op;
  FILE *datafile = fopen(filename, "r");
  #ifdef DEBUG_MODE
    if (datafile == NULL)
      printf("FAIL TO OPEN FILE: \"%s\"\n", filename);
    else
      printf("FILE \"%s\" OPENED\n", filename);
  #endif
  // 파일열기에 실패한 경우 == 파일이 존재하지 않는 경우 //
  if (datafile == NULL){
    // 새로운 파일을 만들지 사용자에게 물어보기 //
	   printf("%s file does not exit. Do you want to make new file?(Y/N) ", filename);
	   scanf("%c", &op);
	   if (op=='Y'){
	      datafile = fopen(filename, "w"); // 새로운 파일 생성
	      fclose(datafile);
	      datafile = fopen(filename, "r"); // 쓰기모드로 열었던 파일을 닫고 읽기모드로 다시 열기
	     }
    getchar();
  }
  // 파일에 있는 데이터 읽어오기 //
  while(1){
    list[count]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[count]->id,list[count]->password);
    if(feof(datafile)!=0){break;}
    count++;
  }
  #ifdef DEBUG_MODE
    printf("FILE \"%s\" SUCESSFULLY READ\n", filename);
  #endif
  printf("%d records read!\n", count);
  fclose(datafile);

  return count;
}

void join(LOGIN* list[], int count){
  char id[20], pass[20];
  while(1){
    printf("Enter new user id >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count]->password, pass);
      printf("New user added!\n");
      break;
    }
  }
}

int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return 0;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

void logout(int* is_login){
  *is_login = 0;
  printf("Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  #ifdef DEBUG_MODE
    printf("%s Saved!\n", filename);
  #endif
  fclose(datafile);

}
