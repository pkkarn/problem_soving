#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    int count = 0;
    // loop until count reached to given no. of rows
    while(count < numRows) {
        // if count is 0 edge case = just assign result to {{1}}
        if(count == 0) {
            result = {{1}};
        } else {
            // or else if its more than that then store previous vect inside prevVec variable
            vector<int> prevVec = result.at(count - 1);
            // now declare a new vec item to store next vector
            vector<int> nextVec;
            // here loop it on prevVec
            for(int i = 0; i < prevVec.size(); i++) {
                // if its 0 in that case just push 1
                if(i == 0) {
                    nextVec.push_back(1);
                } else {
                    // or else push back curr of prev + previous item
                    nextVec.push_back(prevVec.at(i) + prevVec.at(i -1));
                }
            }
            // And once loop is finished then just simply push 1 in back. because prev
            // will only help you to prepare upto the n-1 and last one will be 1 by default
            nextVec.push_back(1);
            // just push result inside nextVec
            result.push_back(nextVec);
        }
        count++;
    }
    return result;
}

int main() {
    int rows = 5;
    

    vector<vector<int> > result = generate(5);
 
    for(auto i: result) {
        for(int j = 0; j < i.size(); j++) {

            cout << i.at(j) << " ";
        }
        cout << endl;
    }
}