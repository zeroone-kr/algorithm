#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    
    vector<int> answer;
    int s, e, k;
 
    for(const auto query : queries){
        
        s = query[0];
        e = query[1];
        k = query[2];
        
        bool found = false;
        int min = 1000000;
        for (int i=s ; i <=e ; i++){
            if (arr[i] > k && arr[i] < min) {
                min = arr[i]; 
                found = true;
            }
        }
        
        found ? answer.push_back(min) : answer.push_back(-1);   
    }
    
    return answer;
}