#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt =0, rm_zero=0, cnt_one;
    
    while( s != "1"){
        
        rm_zero += count(s.begin(), s.end(), '0');
        
        cnt_one = count(s.begin(), s.end(), '1');
        
        s = bitset<32>(cnt_one).to_string();
        s = s.substr(s.find('1'));
        cnt++;
        
    }
    
    return {cnt, rm_zero};
}