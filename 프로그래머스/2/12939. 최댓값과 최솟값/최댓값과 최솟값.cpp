#include <string>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<string> split(const string &str, const string &token) {
    vector<string> result;
    size_t start = 0;
    size_t pos = str.find(token);
    
    while (pos != string::npos) {
        result.push_back(str.substr(start, pos - start));
        start = pos + token.length();
        pos = str.find(token, start);
    }
    
    result.push_back(str.substr(start));
    
    return result;
}



string solution(string s) {
    string answer = "";
    
    int min=std::numeric_limits<int>::max(), max=std::numeric_limits<int>::min();
    for(const auto& str : split(s, " ")){
        
        if (stoi(str) < min){
            min = stoi(str);
        }
        
        if (stoi(str) > max){
            max = stoi(str);
        }
    }
    
    return to_string(min) + " " + to_string(max);
}