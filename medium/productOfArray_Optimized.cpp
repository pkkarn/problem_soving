#include <iostream>
#include <vector>
using namespace std;

vector<int> mapProductArray(vector<int> vec) {
    vector<int> product;

    int n = vec.size();
    int temp = 1;
    // Product = [1, 1 * 1(vec), 1 * 2(vec), 2 * 3(vec), 6 * 4(vec), 24]
    // [1, 1, 2, 6, 24]
    for(int i = 0; i < n; i++) {
        product.push_back(temp);
        temp *= vec.at(i);
    }
    
    temp = 1;
    // [1(60 * 2), 1(20  * 3), 2(4 * 5), 6(5 * 1), 24(1)] 
    // 120 60 40 30 24
    for(int i = n - 1; i >= 0; i--) {
        // cout << i << endl;
        product.at(i) *= temp;
        temp *= vec.at(i);
    }
    
    return product;
} 

int main() {
    vector<int> vec {1,2,3,4,5};
    vector<int> result = mapProductArray(vec);
    
    for(auto i: result)
        cout << i << endl;
}