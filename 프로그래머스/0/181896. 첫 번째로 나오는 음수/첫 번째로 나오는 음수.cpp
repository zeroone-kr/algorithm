#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    
    int idx= 0;
    for(const auto& num : num_list){
        if (num < 0) {
            answer = idx;
            break;
        }
        ++idx;
    }
    
    return answer;
}