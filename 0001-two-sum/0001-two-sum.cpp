#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        bool found = false;
        
        for (int i=0; i < nums.size() ; ++i){
            for (int j =0 ; j < nums.size(); ++j){
                if( i != j && nums[i]+nums[j] == target ){
                    res.push_back(i);
                    res.push_back(j);
                    found = true;
                }
            }
            if (found) break;
        }

        return res;
    }
};