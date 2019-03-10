#include <stdio.h>
#define SIZE 4

int main (){
  double point[] = {0.02, 0.01, 0.015, 0.005};
  char title [][20] = {"현금", "VIP", "체크", "신용"};
  double cash[SIZE] = {0};
  int op, price;
  int sum=0;

  while(1){
    printf("식사금액과 지불방법(현금 1, VIP카드 2, 체크카드 3, 신용카드 4)을 입력하시오.");
    scanf("%d %d", &op, &price);

    if (op<=0) break;

    cash[op-1] += (price * point[op-1]);
  }


  printf("지불방법에 따라 적립된 포인트는 다음과 같습니다.\n");
  for (int i=0 ; i<SIZE ; i++){
    if(i<3)
      printf("%s %.0f원, ", title[i], cash[i]);
    else
      printf("%s %.0f원\n", title[i], cash[i]);

    sum +=  (int)(cash[i]);
  }
  printf("총 적립된 포인트는 %d원 입니다.\n", sum);

  return 0;
}
