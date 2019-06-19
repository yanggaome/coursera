#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
   long long result = 0;
   
   // make a copy of the vectors
   vector<int> a1(a);
   vector<int> b1(b);
   
   // sort, ascending
   std::sort(a1.begin(), a1.end());
   std::sort(b1.begin(), b1.end());

   for (size_t i = 0; i < a1.size(); i++)
   {
      result += ((long long) a1[i]) * b1[i];
   }
   return result;
}

int main() {
   size_t n;
   std::cin >> n;
   vector<int> a(n), b(n);
   for (size_t i = 0; i < n; i++) {
     std::cin >> a[i];
   }
   for (size_t i = 0; i < n; i++) {
     std::cin >> b[i];
   }
   std::cout << max_dot_product(a, b) << std::endl;
}
