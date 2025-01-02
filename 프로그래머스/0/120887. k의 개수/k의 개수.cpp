#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(int m = i ; m <= j; ++m){
        for(const auto& chr : to_string(m)){
            if(chr-'0' == k) ++answer;
        }
    }
    
    return answer;
}