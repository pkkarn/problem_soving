/**
 * Important to note: You thought zig_zag pointer(i) and and number of rows would alway 
 * be i < numOfRows, which is right. But what if "AB", in that case 2 - 1 = 0 and i is also 0. 
 * So, if in that case you would do inverse thing first then instead of increasing i++,
 *  it will minus from it. 0 - 1 = -1. which you don't want... so do your inverse things after that
*/
#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    // A vector which will store n no. of element(string) in it, where n = numRows.
    vector<string> zig_zag;
    
    // i: zig_zag pointer
    // inverse: whene zig_zag pointer will reach 0 and max then they will inverse.
    // n: size of enitre string, to know how many times we have to run loop
    int i = 0;
    bool inverse = false;
    int n = 0;
    while(n < s.size()) {
        int size_of_zig_zag = zig_zag.size();
        // If item or string is not available at current zig_zag pointer then push current one or
        // else just concatenate in exisiting one.
        if(!inverse) {
            if(zig_zag.size() == i) {
                zig_zag.push_back(string(1, s[n])); // convert char to str
            } else {
                zig_zag.at(i) = zig_zag.at(i) + s[n];
            }
            i++;
        } else {
            if(zig_zag.size() == i) {
                zig_zag.push_back(string(1, s[n]));
            } else {
                zig_zag.at(i) = zig_zag.at(i) + s[n];
            }
            i--;
        }
        if(i==(numRows-1)) {
            inverse = true;
        } else if(i==0) {
            inverse = false;
        }
        n++;
    }

    // At last loop and store the result in final string;
    string final_string = "";

    for(auto i:  zig_zag) {
        final_string+=i;
    }

    return final_string;
}

int main() {
    string test1 = "PAYPALISHIRING";
    string test2 = "AB";
    string test3 = "WXYZ";

    cout << convert(test1, 3) << endl;
    cout << convert(test2, 1) << endl;
    cout << convert(test3, 2) << endl;
}