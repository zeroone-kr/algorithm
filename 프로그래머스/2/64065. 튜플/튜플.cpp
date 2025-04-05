#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>


using namespace std;

unordered_map<int, int> hash_map;


vector<string> split(string &input, string del){
    
    vector<string> result;
    int start = 0;
    int end = input.find(del, start);
    
    while(end != string::npos){
        
        result.push_back(input.substr(start, end-start));
        start = end + del.length();
        end = input.find(del, start);
        
    }
    
    result.push_back(input.substr(start));
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    s = s.substr(2, s.length()-4);
    
    vector<string> splitted = split(s, "},{");
    
    for( auto & word : splitted){
        
        vector<string> v2 = split(word, ",");
        for(auto & digit : v2 ){
            hash_map[stoi(digit)]++;
        }
    }
    
    for(auto &p : hash_map){
        answer.push_back(p.first);
        // cout << p.first << ": " << p.second << endl;
    }
    
    
    sort(answer.begin(), answer.end(), [](int a, int b ){
        return hash_map[a] > hash_map[b];
    });
    
    
    return answer;
}