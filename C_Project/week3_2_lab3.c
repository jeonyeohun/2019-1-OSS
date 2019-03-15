#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[20];
  int weight;
  int price;
  int stdprice;
  int stars;
  int cmtcnt;
}Product;

int add (Product* ptr, int cnt){
  printf("제품이름: ");
  scanf("%s", ptr[cnt].name);
  printf("중량: ");
  scanf("%d", ptr[cnt].weight);
  printf("가격: ");
  scanf("%d", ptr[cnt].price);
  printf("표준가격: ");
  scanf("%d", ptr[cnt].stdprice);
  printf("별점수(1~5)");
  scanf("%d", ptr[cnt].stars);
  printf("댓글: ");
  scanf("%d", ptr[cnt].cmtcnt);
}

int printlist (Product* ptr, int cnt){
  for(int i=0 ; i<cnt ; i++){
    printf("제품이름: %s\n", ptr[cnt].name);
    printf("중량: %d\n", ptr[cnt].weight);
    printf("가격: %d\n", ptr[cnt].price);
    printf("표준가격: %d\n", ptr[cnt].stdprice);
    printf("별점수(1~5): %d", ptr[cnt].stars);
    printf("댓글: %d", ptr[cnt].cmtcnt);
  }
}

int mod (){

}

int delete (){

}

int menu (){
  int op;
  printf("메뉴를 선택하세요. 1. 제품추가 / 2. 전체 리스트 / 3. 제품 수정 / 4. 제품 삭제 / 5. 종료");
  scanf("%d", op);

  return op;
}

int main(){
  Product* ptr = (Product*)malloc(sizeof(Product)*5);
  int cnt=0;

  while(1){

    swtich (menu()){
      case 1:
        if (cnt%5==0){
          ptr = (Product*)realloc(sizeof(Product)*(cnt/5)*5)
        }
        add(ptr, cnt);
        cnt++;
        break;
      case 2:
        printlist();
        break;
      case 3:
        mod();
        break;
      case 4:
        delete();
        break;
      case 5:
        break;
    }
  }


  free(ptr);
}
