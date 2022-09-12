#include <stdio.h>

int main(void)
{
  // for loop
  // for (선언; 조건; 증감)
  for (int i = 1; i <= 10; i++)
  {
    printf("value %d\n", i);
  }

  // while (조건)
  int j = 1;
  while (j <= 10)
  {
    printf("while %d\n", j);
    j++;
  }

  // do {} while (조건)
  int k = 1;
  do
  {
    printf("do %d\n", k++);
  } while (k <= 10);

  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 5; j++)
    {
      printf("%d x %d = %d\n", i, j, i * j);
    }
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4 - i; j++)
    {
      printf(" ");
    }
    for (int j = 0; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  // Project
  /*
  ex) 3
    *
   ***
  *****

  ex) 4
     *
    ***
   *****
  *******
  */
  int floor;
  printf("몇 층으로 쌓을까? ");
  scanf("%d", &floor);
  for (int i = 0; i < floor; i++)
  {
    for (int j = 0; j < floor - i - 1; j++)
    {
      printf(" ");
    }
    for (int k = 0; k < 2 * i + 1; k++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}