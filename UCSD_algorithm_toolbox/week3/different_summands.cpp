#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
   vector<int> summands;
   
   int remainder = n;
   int summer = 1;
   int remainder_try = remainder;
   
   while (remainder > 0)
   {
      remainder_try = remainder - summer;
      
      if (remainder_try <= summer && remainder_try!=0)
      {
         // increase summer and skip;
         summer++;
         continue;
      }
      else
      {
         remainder = remainder_try;
         summands.push_back(summer);
         //std::cout << "remainder: "<< remainder << ", summer: "<< summer << std::endl;
         summer++;
      }
   }
   return summands;
}

int main() {
   int n;
   std::cin >> n;
   vector<int> summands = optimal_summands(n);
   std::cout << summands.size() << '\n';
   for (size_t i = 0; i < summands.size(); ++i) {
      std::cout << summands[i] << ' ';
   }
}
