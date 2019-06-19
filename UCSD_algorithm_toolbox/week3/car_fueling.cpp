#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
   // add start and end points
   stops.insert(stops.begin(), 0);
   stops.push_back(dist);

   int numStops = stops.size();
   int numRefills = 0;
   int last_refill = 0;
   int current_refill = 0;
   
   while (current_refill < numStops)
   {
      // start from last refill
      while (stops[current_refill+1] - stops[last_refill] <= tank && (current_refill+1) <= numStops)
      {
         current_refill ++;
      }
      
      // cannot find a stop to refill
      if(current_refill==last_refill)
      {
         return -1;
      }
      
      if (current_refill < numStops)
      {
         // refill here
         last_refill = current_refill;
         numRefills++;
      }
   }

   return numRefills;
}


int main() {
   int d = 0;
   cin >> d;
   int m = 0;
   cin >> m;
   int n = 0;
   cin >> n;
  
   vector<int> stops(n);
   for (size_t i = 0; i < n; ++i)
       cin >> stops.at(i);
   
   cout << compute_min_refills(d, m, stops) << "\n";

   return 0;
}
