#include <iostream>
#include <vector>
#include <string>

using namespace std;

int addNumbers(int param1, int param2)
{
  int result = param1 + param2;
  return result;
}

int main()
{
  int first_number{3}; // Statement
  int second_number{7};

  std::cout << "First number : " << first_number << std::endl;   // 3
  std::cout << "Second number : " << second_number << std::endl; // 7

  int sum = first_number + second_number;
  std::cout << "Sum : " << sum << std::endl; // 10

  sum = addNumbers(25, 3);
  std::cout << "Sum : " << sum << std::endl; // 28

  sum = addNumbers(25, 32);
  std::cout << "Sum : " << sum << std::endl; // 57

  return 0;
}