#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    
    const int MIN_W = 100;
    const int MAX_W = 1000;
    vector<long long> freq(MAX_W + 1, 0);
    
    for (int w : weights) {
        freq[w]++;
    }
    
    long long answer = 0;
    
    
    for (int w = MIN_W; w <= MAX_W; w++) {
        if (freq[w] > 1) {
            answer += (freq[w] * (freq[w] - 1)) / 2;
        }
    }
    
    for (int w1 = MIN_W; w1 <= MAX_W; w1++) {
        if (freq[w1] == 0) continue;
        for (int w2 = w1 + 1; w2 <= MAX_W; w2++) {
            if (freq[w2] == 0) continue;
            
            bool valid = false;
            if (2LL * w1 == 3LL * w2) valid = true;
            if (3LL * w1 == 2LL * w2) valid = true;
            if (2LL * w1 == 4LL * w2) valid = true;
            if (4LL * w1 == 2LL * w2) valid = true;
            if (3LL * w1 == 4LL * w2) valid = true;
            if (4LL * w1 == 3LL * w2) valid = true;
            
            if (valid) {
                answer += freq[w1] * freq[w2];
            }
        }
    }
    
    return answer;
}