#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
    std::sort(s.begin(), s.end(), [](char a, char b) {
        return a > b; 
    });
    return s;
}