#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int first_diagnoal = 0;
    int second_diagnoal = 0;
    
    int n = arr.size();
    
    for(int i = 0; i < n; i++) {
        first_diagnoal += arr[i][i];
        second_diagnoal += arr[i][n - 1 - i];
    } 
    
    return abs(first_diagnoal - second_diagnoal);
}

int main() {
    vector<vector<int> > vec_variable {
        { 2,1,4},
        { 2,5,6},
        { 4,2,1}
    };

    cout << diagonalDifference(vec_variable) << endl;
};
