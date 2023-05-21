#include <iostream>

int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  if (n > 1)
  {
    return fib(n - 1) + fib(n - 2);
  }
  return n;
}

int factorial(int n)
{
  if (n < 1)
    return 0;

  if (n == 1)
    return 1;

  return n * factorial(n - 1);
}
//  980
//
int reverseNumber(int n)
{
  int res = 0;

  while (n != 0)
  {
    res = res * 10 + (n % 10);
    n /= 10;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  int fibNum = fib(10);
  int fac = factorial(4);
  int rev = reverseNumber(980);
  ;

  std::cout << fibNum << std::endl;
  std::cout << fac << std::endl;
  std::cout << rev << std::endl;
  return 0;
}

//  1 1 2 3 5 8 13 21 34 55
//  4 * 3 * 2 * 1