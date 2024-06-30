#include <iostream>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        
        int reversed = 0;
        
        while (x != 0){
            int o = x % 10;
            x = x / 10;
            if (reversed > std::numeric_limits<int>::max() / 10 || (reversed == std::numeric_limits<int>::max() / 10 && o > 7)) return 0;
            if (reversed < std::numeric_limits<int>::min() / 10 || (reversed == std::numeric_limits<int>::min() / 10 && o < -8)) return 0;
            reversed = reversed* 10+ o;
        }
        
        return reversed;
    }
};