#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
typedef struct {
  char name[20];
  char add[100];
  int age;

}pinfo;

int main(){

  pinfo* ptr = (pinfo*)malloc(sizeof(pinfo)*SIZE);

  for(int i=0 ; i<SIZE ; i++){
    printf("이름은: ");
    scanf("%s", ptr[i].name);
    getchar();
    printf("주소는: ");
    fgets(ptr[i].add, 100, stdin);
    printf("나이는: ");
    scanf("%d", &ptr[i].age);
  }

  for(int i=0 ; i<3 ; i++){
    printf("%s %s %d\n",ptr[i].name, ptr[i].add, ptr[i].age);
  }

  free(ptr);
}
