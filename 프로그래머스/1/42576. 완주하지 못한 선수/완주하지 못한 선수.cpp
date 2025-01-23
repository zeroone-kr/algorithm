#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hashmap;
    
    for(const auto &name : participant){
        
        hashmap[name]++;
        
    }
    
    for(const auto &name: completion){
        
        hashmap[name]--;
        if (hashmap[name] == 0) hashmap.erase(name);
        
    }

    answer = hashmap.begin()->first;
    return answer;
}