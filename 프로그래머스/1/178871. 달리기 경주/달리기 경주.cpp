#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> player_positions;
    
    for (int i = 0; i < players.size(); ++i) {
        player_positions[players[i]] = i; 
    }

    for (const string& calling : callings) {
        int current_pos = player_positions[calling];
        
        if (current_pos > 0) {
            int new_pos = current_pos - 1; 
            string overtaken_player = players[new_pos]; 

            swap(players[current_pos], players[new_pos]);

            player_positions[calling] = new_pos;
            player_positions[overtaken_player] = current_pos;
        }
    }

    return players;
}