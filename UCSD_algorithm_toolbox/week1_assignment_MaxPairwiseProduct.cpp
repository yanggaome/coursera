#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProductBySorting(std::vector<int>& numbers) {
    
    long long max_product = 0;
    int n = numbers.size();
    
    // ascending sort
    std::sort( numbers.begin(), numbers.end() );
    // return product of the largest two numbers
    // note: index is 0 based
    // note type should be long long
    max_product = (long long) numbers[n-1] * numbers[n-2];
    
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    std::cout << MaxPairwiseProductBySorting(numbers) << "\n";
    
    return 0;
}
