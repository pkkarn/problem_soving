#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> rank;
    vector<int> finalRank;
    int temp = ranked.at(0);
    rank.push_back(ranked.at(0));
    
    for(auto i:ranked) {
        if(i < temp) {
            rank.push_back(i);
            temp = i;
        }
    }
    
    reverse(player.begin(), player.end());
    
    int i_rank = 1;
    int i = 0; // for ranks
    int j = 0; // for players
    // break loop when j == players.size();
    
    for(int t = 0; t < rank.size() + player.size(); t++) {
        if(player[j] >= rank[i]) {
            finalRank.push_back(i_rank);
            j++;
            if(j == player.size()) break;
        } else {
            i_rank++;
            i++;
        }
    }
    
    reverse(finalRank.begin(), finalRank.end());
        
    return finalRank;
}

int main() {
    vector<int> ranked {100,100,50,40,40,20,10};
    vector<int> players {5,25,50,120};

    vector<int> result = climbingLeaderboard(ranked, players);
    for(auto i: result)
        cout << i << endl;
}