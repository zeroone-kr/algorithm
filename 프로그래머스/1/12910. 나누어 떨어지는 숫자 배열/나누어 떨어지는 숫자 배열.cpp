#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(const auto &E : arr){
        if ( E % divisor == 0){
            answer.push_back(E);
        }
    }
    
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}