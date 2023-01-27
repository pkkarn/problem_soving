#include <iostream>
#include <vector>
using namespace std;


vector<int> mergeTwoArray(vector<int> v1, vector<int> v2) {
    /**
        Take two sorted arrays;
        Define two different pointers pointing at 0th index of v1 and v2 respectively.
        Define a empty vector to store sorted values
        Run while loop until one of the pointer reaches at the size of their array.
            Inside loop, 
            IF: check if the value of v1 at pointer i is less than value of v2 at pointer j then
                push value of v1 at ith index and increase i++;
            ELSE: Do vise versa.

            Time Complexity: O(n+m)

        Once loop ends, then push rest of the items left in either vector1 or vector2.
    **/
    int n = v1.size();
    int m = v2.size();
    int i = 0;
    int j = 0;

    vector<int> result;

    while((i < n) && (j < m)) {
        if(v1[i] < v2[j]) {
            result.push_back(v1[i]);
            i++;
        } else {
            result.push_back(v2[j]);
            j++;
        }
    }

    while(i<n) {
        result.push_back(v1[i]);
        i++;
    }

    while(j<m) {
        result.push_back(v2[j]);
        j++;
    }
    return result;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /**
        merge two sorted array first written and explained function above.
        And then find out median by using basic math.
    **/
    vector<int> sortedMergedVector = mergeTwoArray(nums1, nums2);
    int n = sortedMergedVector.size();
    if(n % 2 != 0) {
        int term = (n + 1)/2;
        float item = sortedMergedVector.at(term - 1); // - 1 to get item at given index
        return item;
    } else {
        int midPoint = n/2;
        int totalValue = sortedMergedVector.at(midPoint - 1) 
                        + sortedMergedVector.at(midPoint);

        float item = (float) totalValue/2; // - 1 to get item at given index
        return item;
    }
    return 0;
}

int main() {
    vector<int> vec1 {1,2};
    vector<int> vec2 {3,4};

    float resultVec = findMedianSortedArrays(vec1, vec2);

    cout << resultVec;
}