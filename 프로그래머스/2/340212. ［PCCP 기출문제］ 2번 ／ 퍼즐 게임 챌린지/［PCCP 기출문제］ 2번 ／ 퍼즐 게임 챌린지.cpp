#include <bits/stdc++.h>
using namespace std;

/**
 * 현재 숙련도(level)로 모든 퍼즐을 풀 때 걸리는 총 시간을 계산.
 * 만약 중간에 limit를 넘으면 바로 리턴(시간 절약).
 */
long long totalTimeNeeded(const vector<int> &diffs, const vector<int> &times, long long limit, int level) {
    
    long long total = 0;
    int n = (int)diffs.size();

    total += times[0];
    if (total > limit) return total;  
    
    for (int i = 1; i < n; i++) {
        if (diffs[i] <= level) {
            
            total += times[i];
            
        } else {

            long long failCount = (long long)diffs[i] - level;
            total += failCount * ((long long)times[i] + (long long)times[i - 1]) + times[i];
            
        }
                if (total > limit) {
            return total;
        }
    }
    
    return total;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int left = 1, right = 100000;
    int answer = right; 
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long timeNeeded = totalTimeNeeded(diffs, times, limit, mid);
        
        if (timeNeeded <= limit) {

            answer = mid;
            right = mid - 1; 
            
        } else {
            
            left = mid + 1;
            
        }
    }
    
    return answer;
}