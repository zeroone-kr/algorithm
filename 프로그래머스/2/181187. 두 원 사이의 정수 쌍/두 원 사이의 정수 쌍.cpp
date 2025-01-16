#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    
    long long answer = 0;
    long long r1_, r2_;
    
    r1_  = static_cast<long long>(r1);
    r2_  = static_cast<long long>(r2);
    
    for (long long i = 1; i <= r2_; ++i) {
        long long y2 = static_cast<long long>(sqrt(r2_ * r2_ - i * i));
        long long y1 = (i < r1_) ? static_cast<long long>(ceil(sqrt(r1_ * r1_ - i * i))) : 0;

        answer += (y2 - y1 + 1);
    }

    return answer * 4;
}