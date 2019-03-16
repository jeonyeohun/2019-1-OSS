#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char name[20];
  int weight;
  int price;
  int stdprice;
  int stars;
  int cmtcnt;
}Product;

void add (Product* ptr, int cnt){
  printf("제품이름: ");
  scanf("%s", ptr[cnt].name);
  printf("중량: ");
  scanf("%d", &ptr[cnt].weight);
  printf("가격: ");
  scanf("%d", &ptr[cnt].price);
  printf("표준가격: ");
  scanf("%d", &ptr[cnt].stdprice);
  printf("별점수(1~5): ");
  scanf("%d", &ptr[cnt].stars);
  printf("댓글: ");
  scanf("%d", &ptr[cnt].cmtcnt);
}

void printlist (Product* ptr, int cnt){
  for(int i=0 ; i<cnt ; i++){
    printf("제품이름: %s\n", ptr[i].name);
    printf("중량: %d\n", ptr[i].weight);
    printf("가격: %d\n", ptr[i].price);
    printf("표준가격: %d\n", ptr[i].stdprice);
    printf("별점수(1~5): %d\n", ptr[i].stars);
    printf("댓글: %d\n\n", ptr[i].cmtcnt);
  }
}

void mod (Product* ptr){
  int n;
  char name[20];
  printf("몇번 제품의 정보를 변경하시겠습니까?: ");
  scanf("%d", &n);

  n-=1;

  printf("제품이름: ");
  scanf("%s", name);
  strcpy(ptr[n].name, name);
  printf("중량: ");
  scanf("%d", &ptr[n].weight);
  printf("가격: ");
  scanf("%d", &ptr[n].price);
  printf("표준가격: ");
  scanf("%d", &ptr[n].stdprice);
  printf("별점수(1~5): ");
  scanf("%d", &ptr[n].stars);
  printf("댓글: ");
  scanf("%d", &ptr[n].cmtcnt);
}

void delete (Product *ptr, int cnt){
  int n;
  printf("몇번 제품의 정보를 삭제하시겠습니까?: ");
  scanf("%d", &n);

  for(int i=n-1 ; i<cnt ; i++){
    ptr[i] = ptr[i+1];
  }
}

int menu (){
  int op;
  printf("\n메뉴를 선택하세요. 1. 제품추가 / 2. 전체 리스트 / 3. 제품 수정 / 4. 제품 삭제 / 5. 종료");
  scanf("%d", &op);

  return op;
}

int main(){
  Product* ptr = (Product*)malloc(sizeof(Product)*5);
  int cnt=0;
  int op;

  while(1){
    op = menu();
    if (op==5) break;
    switch (op){
      case 1:
        if (cnt%5==0){
          ptr = (Product*)realloc(ptr, sizeof(Product)*(cnt/5)*5);
        }
        add(ptr, cnt);
        cnt++;
        break;
      case 2:
        printlist(ptr, cnt);
        break;
      case 3:
        mod(ptr);
        break;
      case 4:
        delete(ptr, cnt);
        cnt--;
        break;
    }
  }
  free(ptr);
  return 0;
}
