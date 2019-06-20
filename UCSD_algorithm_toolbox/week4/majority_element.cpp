#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
   // empty
   if (left == right) return -1;
   // only one element
   if (left + 1 == right) return a[left];
   
   // hash map to record the occurence of a[i]
   // then loop hash map and find it out
   std::unordered_map<int, int> element_map;
   for (size_t i = 0; i < right; ++i)
   {
      element_map[a[i]]++;
   }
   int count = 0;
   for (auto i : element_map)
   {
      if (i.second > right/2)
      {
         count ++;
         return count;
      }
   }

   return -1;
}

int main() {
   int n;
   std::cin >> n;
   vector<int> a(n);
   for (size_t i = 0; i < a.size(); ++i) {
      std::cin >> a[i];
   }
   std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
