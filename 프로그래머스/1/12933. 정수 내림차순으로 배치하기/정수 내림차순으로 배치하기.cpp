#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    
    string ret = to_string(n);
    sort(ret.rbegin(), ret.rend());
    return stoll(ret);
}