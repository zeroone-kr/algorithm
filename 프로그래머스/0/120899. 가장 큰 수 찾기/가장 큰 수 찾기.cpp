#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array) {
    
    
    int loc= 0;
    vector<int> answer;
    vector<int> orig = array;
    sort(array.rbegin(), array.rend());
    
    for(const auto & n : orig){
        if ( n == array[0] ) break;
        loc++;
    }
    answer.push_back(array[0]);
    answer.push_back(loc);
    return answer;
}