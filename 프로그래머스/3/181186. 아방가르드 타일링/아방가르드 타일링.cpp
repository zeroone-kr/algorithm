#include <string>
#include <vector>

using namespace std;

const unsigned long MOD = 1'000'000'007;

int solution(int n) {
    
    vector<long long> dp(max(7, n + 1), 0);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    dp[4] = 23;
    dp[5] = 62;
    dp[6] = 170;

    for (int i = 7; i <= n; ++i) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2] + 6 * dp[i - 3] + dp[i - 4] - dp[i - 6] + MOD) % MOD;
    }

    return dp[n];
}