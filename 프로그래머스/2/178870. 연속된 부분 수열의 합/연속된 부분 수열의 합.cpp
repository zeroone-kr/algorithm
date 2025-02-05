#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0, right = 0, sum = 0;
    int minLength = sequence.size() + 1, minLeft = 0, minRight = 0;
    
    while (right < sequence.size()) {

        while (right < sequence.size() && sum < k) {
            sum += sequence[right++];
        }
        
        while (sum > k && left < right) {
            sum -= sequence[left++];
        }
        
        if (sum == k) {
            int length = right - left;
            if (length < minLength) {
                minLength = length;
                minLeft = left;
                minRight = right-1; 
            }
        }
  
        sum -= sequence[left++];
    }
    
    answer.push_back(minLeft);
    answer.push_back(minRight);
    
    return answer;
}
