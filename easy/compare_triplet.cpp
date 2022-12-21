#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem Statement:
 * 
 * https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true
*/

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int alice_scores = 0;
    int bob_scores = 0;
    
    vector<int> scores = {0, 0};
    
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) scores[0]++;
        if(a[i] < b[i]) scores[1]++;
    }
    
    return scores;
}

int main() {
    vector<int> alice_score {12,1,32};
    vector<int> bob_score {3,12,13};
    
    vector<int> fina_result;

    fina_result = compareTriplets(alice_score, bob_score);

    for(auto score:fina_result)
        cout << score << endl;
};