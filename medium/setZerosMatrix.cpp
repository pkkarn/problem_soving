#include <iostream>
#include <vector>
using namespace std;

/**
    ** Time complexity of this would be O(n*m) // traversing through each element to extract 0 poistion 
    ** and then O(m+n) to traverse throught row(n) and coloumn(n) once for each zero to set all items
    ** to 0 in that rwo and coloumn
**/

void setZeroes(vector<vector<int>>& matrix) {
    // first extract the position of 0 index.
    // To store 0th i, j index
    vector<vector<int>> zerosIndex;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.at(i).size(); j++) {
            if(matrix.at(i).at(j) == 0) {
                zerosIndex.push_back({i, j});
            }
        }
    } 

    for(int z = 0; z < zerosIndex.size(); z++) {
        // this one is to mutate the col of current 0 index
        for(int m = 0; m < matrix.size(); m++) {
            int col_index = zerosIndex.at(z).at(1);
            matrix.at(m).at(col_index) = 0; 
        }
        // select the row you want to set 0
        int row_index = zerosIndex.at(z).at(0);
        // loop over all row element
        for(int n = 0; n < matrix.at(row_index).size(); n++) {
            matrix.at(row_index).at(n) = 0; 
        }
    }
}

int main() {
    vector<vector<int>> matrix {{1,1,1},{1,0,1},{1,1,1}};

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.at(i).size(); j++) {
            cout << matrix.at(i).at(j) <<  " ";
        }
        cout << endl;
    }

    setZeroes(matrix);
    cout << "-----" << endl;

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.at(i).size(); j++) {
            cout << matrix.at(i).at(j) <<  " ";
        }
        cout << endl;
    }

}