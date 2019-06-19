#include <iostream>

int get_change(int m) {
   int num, remainder;
   num = 0;
   remainder = m;

   while (remainder>=0)
   {
      if (remainder >= 10)
      {
         remainder -= 10;
         num++;
      }
      else if (remainder >= 5)
      {
         remainder -= 5;
         num++;
      }
      else if (remainder >= 1)
      {
         remainder -= 1;
         num++;
      }
      else
      {
         // remainder is 0
         return num;
      }
   }
}

int main() {
   int m;
   std::cin >> m;
   std::cout << get_change(m) << '\n';
}
