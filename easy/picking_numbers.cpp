#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int picking_numbers(vector<int> vec) {
    int n = vec.size();
    int count = 0;
    int max_count = 0;
    // Sorting is important, because by doing so, you will not have keep tract of item, as you can guess in this subarray there should be only two element with absoulte difference of less than or equal to 1.
    sort(vec.begin(), vec.end());
    // int i = 0;
    for(int i = 0; i < n; i++) {
        // At each iteration take i
        for(int j = i; j < n; j++) {
            // And find the absolute difference with the next item.
            int diff = abs(vec.at(i) - vec.at(j)); //  = 0;
            // As long as abs difference is less than or equal to 1, increase count++
            if(diff <= 1) {
                // cout << "Item "<< vec.at(j) << count << endl;
                count++;
            }
        }
        // Once iteration is completed then check if curr count is greater than max_count then replace it.
        max_count = max(count, max_count);
        // Finally set the count to 0;
        count = 0;
    }
    return max_count;
}

int main() {
    vector<int> vec {1,1,2,2,4,4,5,5,5};
    vector<int> vec1 {4, 6, 5, 3, 3, 1};
    vector<int> vec2 {1, 2, 2, 3, 1, 2};

    cout << "Max Count Vector 1: " << picking_numbers(vec) << endl;
    cout << "Max Count Vector 2: " << picking_numbers(vec1) << endl;
    cout << "Max Count Vector 3: " << picking_numbers(vec2) << endl;
}
