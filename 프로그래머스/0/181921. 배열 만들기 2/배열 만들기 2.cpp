#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    
    vector<int> answer;
    
    for(int i = l; i<= r; ++i){
        
        string cur_str = to_string(i);
        int five = count(cur_str.begin(), cur_str.end(), '5');
        int zero = count(cur_str.begin(), cur_str.end(), '0');
        
        if (cur_str.length() == five + zero){
            answer.push_back(i);
        }
        
    }
    
    if (answer.empty()){
        return {-1};
    }
    
    return answer;
}