#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    
    string result;
    string ret = to_string(n);
    sort(ret.rbegin(), ret.rend());
    for(const auto & chr: ret) result += chr;
    return stoll(result);
}