#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct partition_result
{
   int lt, gt;
};

partition_result partition3(vector<int> &a, int l, int r) {
  // pivot
  int x = a[l];

  int i = l;
  int lt = l;
  int gt = r;
  
  while (i <= gt)
  {
     if (a[i] < x)
     {
        swap(a[i], a[lt]);
        i++;
        lt++;
     }
     else if (a[i]>x)
     {
        swap(a[i], a[gt]);
        gt --;
     }
     else
     {
        i++;
     }
  }
  
  return {lt, gt};
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  // single way scan and swap
  // j is the last entry less than the pivot
  // j+1 to i-1 are entries greater than the pivot
  // i the current candidate
  for (int i = l + 1; i <= r; i++) {
    // if the current candidate i is less than the pivot
    // swap i with j+1, since j the the last entry less than the pivot
    // j+1 is the first entry greater than the pivot
    // after swapping, i is the entry greater than the pivot
    // then increase i, this will expand the great entry partition
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
    // else if greater than the pivot
    // just increase i, this will expand the great entry partition
  }
  // finally, swap the pivot with j, j is the last entry less than the pivot
  // then left side are all smaller ones, right size are all larger ones
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  
  auto partition = partition3(a, l, r);
  
  int lt = partition.lt;
  int gt = partition.gt;

  randomized_quick_sort(a, l, lt - 1);
  randomized_quick_sort(a, gt + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
