#include <stdio.h>

int main(void)
{
  // 정수형 변수
  int age = 12;
  printf("%d\n", age);

  // 실수형 변수
  float f = 47.5f;
  printf("%f\n", f);   // 47.500000
  printf("%.2f\n", f); // 47.50

  double d = 4.4256;
  printf("%lf\n", d);   // 4.425600
  printf("%.2lf\n", d); // 4.43

  // 상수
  const int YEAR = 2000;
  printf("연도 : %d\n", YEAR);

  // printf
  int sum = 3 + 2;
  printf("3 + 2 = %d\n", sum);
  printf("%d + %d = %d\n", 3, 2, 3 + 2);
  printf("%d x %d = %d\n", 3, 2, 3 * 2);

  // scanf : 입력받기
  int input;
  printf("값을 입력하세요 : ");
  scanf("%d", &input);
  printf("입력값 : %d\n", input);

  int v1, v2, v3;
  printf("3개 값을 입력하세요 : ");
  scanf("%d %d %d", &v1, &v2, &v3);
  printf("입력값 : %d %d %d\n", v1, v2, v3);

  // 문자, 문자열
  char c = 'A';
  printf("%c\n", c);

  char str[256];
  scanf("%s", str);
  printf("%s\n", str);

  // Project
  // 경찰관이 조서를 작성함
  char name[256];
  printf("What's your name? ");
  scanf("%s", name);

  int age2;
  printf("How old are you? ");
  scanf("%d", &age2);

  float weight;
  printf("How tall are you? ");
  scanf("%f", &weight);

  double height;
  printf("How much do you weigh? ");
  scanf("%lf", &height);

  char what[256];
  printf("What did you do? ");
  scanf("%s", what);

  printf("\n\n--- information ---\n\n");
  printf("name : %s\n", name);
  printf("age : %d\n", age2);
  printf("weight : %.2f\n", weight);
  printf("height : %.2lf\n", height);
  printf("action : %s\n", what);

  return 0;
}