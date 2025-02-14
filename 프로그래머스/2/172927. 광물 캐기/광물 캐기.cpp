#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {

    int totalPicks = picks[0] + picks[1] + picks[2];
    int n = minerals.size();
    int blockCount = min(totalPicks, (int)ceil(n / 5.0));

    vector<vector<string>> blocks;
    for (int i = 0; i < blockCount; i++) {
        vector<string> block;
        for (int j = i * 5; j < min(n, (i+1) * 5); j++) {
            block.push_back(minerals[j]);
        }
        blocks.push_back(block);
    }
    
    vector<pair<int, vector<string>>> blockScores;
    for(auto &block : blocks) {
        int score = 0;
        for(auto &mineral : block) {
            if(mineral == "diamond")
                score += 25;
            else if(mineral == "iron")
                score += 5;
            else if(mineral == "stone")
                score += 1;
        }
        blockScores.push_back({score, block});
    }

    sort(blockScores.begin(), blockScores.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    int totalFatigue = 0;
    for(auto &p : blockScores){
        vector<string> block = p.second;

        if(picks[0] > 0) {  
            picks[0]--;
            totalFatigue += block.size(); 
        }
        else if(picks[1] > 0) {
            picks[1]--;
            for(auto &mineral : block) {
                if(mineral == "diamond")
                    totalFatigue += 5;
                else
                    totalFatigue += 1;
            }
        }
        else if(picks[2] > 0) { 
            picks[2]--;
            for(auto &mineral : block) {
                if(mineral == "diamond")
                    totalFatigue += 25;
                else if(mineral == "iron")
                    totalFatigue += 5;
                else
                    totalFatigue += 1;
            }
        }
    }
    return totalFatigue;
}