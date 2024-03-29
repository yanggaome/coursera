#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

// select minimum right endpoint and remove those segments that contains that endpoint
using std::vector;

struct Segment {
   int start, end;
};

// ascending sort with the right end point
bool compareRightEnd(Segment a, Segment b)
{
   return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
   
   // sorting
   std::sort(segments.begin(), segments.end(), compareRightEnd);

   vector<int> points;
   // add the first end point
   int point = segments[0].end;
   points.push_back(point);

   for (size_t i = 1; i < segments.size(); ++i)
   {
      if (point < segments[i].start || point > segments[i].end)
      {
         point = segments[i].end;
         points.push_back(point);
      }
   }
   return points;
}

int main() {
   int n;
   std::cin >> n;
   vector<Segment> segments(n);
   for (size_t i = 0; i < segments.size(); ++i) {
     std::cin >> segments[i].start >> segments[i].end;
   }
   vector<int> points = optimal_points(segments);
   std::cout << points.size() << "\n";
   for (size_t i = 0; i < points.size(); ++i) {
     std::cout << points[i] << " ";
   }
}
