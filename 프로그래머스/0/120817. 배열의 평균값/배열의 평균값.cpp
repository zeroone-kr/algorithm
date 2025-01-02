#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    for(const auto &n : numbers){
        answer += n;
    }
    
    answer = answer / numbers.size();
    return answer;
}