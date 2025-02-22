#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, duration;
    cin >> n >> duration;

    vector<int> arr(n);
    vector<long long> sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];  
    }

    long long max_sum = LLONG_MIN;

    for (int i = 0; i + duration <= n ; ++i) {
        long long temp_sum = sum[i + duration] - sum[i]; 
        max_sum = max(max_sum, temp_sum);
    }

    cout << max_sum << endl;
    return 0;
}
