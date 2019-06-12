#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
  // stop recursion
  if (b == 0)
  {
     return a;
  }
  int ap;
  ap = a % b;
  // recursion
  gcd_fast(b, ap);
}

// least common multiple is actually (a*b)/gcd(a,b), where gcd is the greatest common divider
long long lcm_fast(int a, int b)
{
   return ((long long) a*b ) /gcd_fast(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
