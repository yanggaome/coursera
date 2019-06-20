#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// input array a is already sorted in ascending order
// no duplicated elements
// iterative version takes less stack space than the recursive version
int binary_search(const vector<int> &a, int x) {
   int low = 0;
   int mid = 0;
   // NOTE: this is size - 1 !!!
   int high = (int)a.size()-1;

   while (low <= high)
   {
      mid = ((high + low)/2);
      
      if (a[mid] == x)
      {
         return mid;
      }
      else if (a[mid] < x)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return - 1;
}

int linear_search(const vector<int> &a, int x) {
   for (size_t i = 0; i < a.size(); ++i) {
     if (a[i] == x) return i;
   }
   return -1;
}

int main() {
   int n;
   std::cin >> n;
   vector<int> a(n);
   for (size_t i = 0; i < a.size(); i++) {
     std::cin >> a[i];
   }
   int m;
   std::cin >> m;
   vector<int> b(m);
   for (int i = 0; i < m; ++i) {
     std::cin >> b[i];
   }
   for (int i = 0; i < m; ++i) {
      //replace with the call to binary_search when implemented
      //std::cout << linear_search(a, b[i]) << ' ';
      std::cout << binary_search(a, b[i]) << ' ';
   }
}
