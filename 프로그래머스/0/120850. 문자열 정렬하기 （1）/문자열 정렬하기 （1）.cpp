#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(const auto& chr : my_string){
        if ('0' <= chr && chr <= '9'){
            answer.push_back(chr-'0');
        }
    }
    sort(answer.begin(), answer.end());    
    
    return answer;
}