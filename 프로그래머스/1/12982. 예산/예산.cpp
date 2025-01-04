#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    
    while(!d.empty()){
        if (budget >= *d.begin()){
            budget -= *d.begin();
            answer++;
        }
        d.erase(d.begin());        
    }
    
    return answer;
}