#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  int age = 25;
  if (age >= 24)
  {
    printf("adult\n");
  }
  else if (age < 20)
  {
    printf("teenage\n");
  }
  else
  {
    printf("student\n");
  }

  // && ||
  int a = 10;
  int b = 11;
  int c = 12;
  if (a == b && b == c)
  {
    printf("a, b, c는 모두 같다.\n");
  }
  else if (a == b)
  {
    printf("a와 b 만 같다.\n");
  }
  else if (b == c)
  {
    printf("b와 c 만 같다.\n");
  }
  else
  {
    printf("서로 다르다.\n");
  }

  // random
  printf("before init...\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", rand() % 10);
  }
  printf("\n");

  srand(time(NULL)); // init

  printf("after init...\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", rand() % 10);
  }
  printf("\n");

  int num = rand() % 3 + 1;
  switch (num)
  {
  case 1:
    printf("rock\n");
    break;
  case 2:
    printf("scissors\n");
    break;
  case 3:
    printf("paper\n");
    break;
  default:
    printf("unknown\n");
  }

  // Project
  int n = rand() % 50 + 1;
  printf("number : %d\n", n);
  int answer = 0;
  int chance = 5;
  while (chance > 0)
  {
    printf("remain : %d\n", chance--);
    printf("guess the n (1~50) : ");
    scanf("%d", &answer);

    if (answer > n)
    {
      printf("Down\n\n");
    }
    else if (answer < n)
    {
      printf("Up\n\n");
    }
    else if (answer == n)
    {
      printf("HIT!!!!!\n\n");
      break;
    }

    if (chance == 0)
    {
      printf("FAILED\n");
      printf("Answer : %d\n", n);
    }
  }

  return 0;
}