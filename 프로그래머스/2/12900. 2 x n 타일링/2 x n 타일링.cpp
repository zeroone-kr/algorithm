#include <string>
#include <vector>

using namespace std;

const int BOUND = 1000000007;

    int solution(int n) {
    
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }
    
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i =3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % BOUND;    
    }
    
    return dp[n];
}