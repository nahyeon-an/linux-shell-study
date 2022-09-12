#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void p(int num);
void function_without_return();
int function_with_return();
void function_with_param(int v1, int v2, int v3);
int getRandomNumber(int level);
void showQuestions(int level, int n1, int n2);
void success();
void fail();

int main(void)
{
  int num = 2;
  p(num);
  function_without_return();
  int ret = function_with_return();
  p(ret);
  function_with_param(11, 12, 112);

  // Project
  srand(time(NULL));
  int cnt = 0;
  for (int i = 1; i <= 5; i++)
  {
    int n1 = getRandomNumber(i);
    int n2 = getRandomNumber(i);
    showQuestions(i, n1, n2);

    int answer = -1;
    scanf("%d", &answer);
    if (answer == -1)
    {
      printf("exit program\n");
      exit(0);
    }
    else if (answer == n1 * n2)
    {
      success();
      cnt++;
    }
    else
    {
      fail();
      printf("Answer was %d\n", n1 * n2);
    }
  }

  return 0;
}

void p(int num)
{
  printf("num : %d\n", num);
}

void function_without_return()
{
  printf("No return value!\n");
}

int function_with_return()
{
  return 4;
}

void function_with_param(int v1, int v2, int v3)
{
  printf("%d, %d, %d\n", v1, v2, v3);
}

int getRandomNumber(int level)
{
  return rand() % (level * 7) + 1;
}

void showQuestions(int level, int n1, int n2)
{
  printf("\n\n----- Lv.%d number -----\n\n", level);
  printf("what is \"%d x %d\"?\n\n", n1, n2);
  printf("---------------------------\n\n");
  printf("Enter your password (exit : -1) >> ");
}

void success()
{
  printf("\nSuccess :)\n");
}

void fail()
{
  printf("\nFailed :(\n");
}