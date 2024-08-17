#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

int solution(vector<vector<int>> targets) {

    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int answer = 0;
    double current_end = -1; 

    for (const auto& target : targets) {
        int s = target[0];
        int e = target[1];
        

        if (s >= current_end) {
            answer += 1;
            current_end = e;  
        }
    }
    
    return answer;
}