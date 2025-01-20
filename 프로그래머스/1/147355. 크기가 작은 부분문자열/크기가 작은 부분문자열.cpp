#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    
    int cnt=0;
    
    for (int i = 0; i <= t.size()-p.size() ; ++i){
    
        string s = t.substr(i, p.size());
        unsigned long long X = stoull(s);
        unsigned long long C = stoull(p);
        if ( X <= C ) cnt++;
        
    }
    
    return cnt;
}