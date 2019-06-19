#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

struct triple_vector
{
   double x; // value per weight
   int y; // values
   int z; // weights
};

// descending sort based on the first value, i.e. value per weight
bool compareValuePerWeight(triple_vector v1, triple_vector v2)
{
   return (v1.x > v2.x);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
   
   double value = 0.0;
   int current_total_weight = 0;
   
   vector<double> value_per_weight;
   for (int n=0; n<values.size(); n++)
   {
      // NOTE: convert to double!!!
      value_per_weight.push_back((double)values[n]/weights[n]);
   }
   
   vector<triple_vector> alldata;

   for (int n=0; n<values.size(); n++)
   {
      alldata.push_back({value_per_weight[n], values[n], weights[n]});
   }
   
   std::sort(alldata.begin(), alldata.end(), compareValuePerWeight);

   for (int n=0; n<values.size(); n++)
   {
      int current_capacity = capacity - current_total_weight;
      // add from the largest value per weight
      int current_pick_value = alldata[n].y;
      int current_pick_weight = alldata[n].z;
      
      int add_weight = std::min(current_capacity, current_pick_weight);
      double add_value = (double) add_weight * alldata[n].x;
      
      current_total_weight += add_weight;
      value += add_value;

      if (current_total_weight==capacity)
      {
         break;
      }
   }

   // round to 4 decimals
   // NOTE: use long instead of int!!!
   double temp_val = (long)(value*10000 + 0.5);
   value = temp_val/10000;

   return value;
}

int main() {
   int n;
   int capacity;
   std::cin >> n >> capacity;
   vector<int> values(n);
   vector<int> weights(n);
   for (int i = 0; i < n; i++) {
     std::cin >> values[i] >> weights[i];
   }

   double optimal_value = get_optimal_value(capacity, weights, values);

   std::cout.precision(10);
   std::cout << optimal_value << std::endl;
   return 0;
}
