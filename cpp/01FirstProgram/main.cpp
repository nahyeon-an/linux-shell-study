#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  // Compile time error
  // std::cout << "Hello world!" << std::endl

  std::cout << "Hello world!" << std::endl;

  // Run time error
  int value = 8 / 0;

  std::cout << "value : " << value << std::endl;

  return 0;
}