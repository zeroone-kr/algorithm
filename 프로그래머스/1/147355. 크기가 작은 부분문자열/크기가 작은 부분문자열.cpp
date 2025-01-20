#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    
    vector<unsigned long long> result;
    
    for (int i = 0; i <= t.size()-p.size() ; ++i){
    
        string s = t.substr(i, p.size());
        unsigned long long X = stoull(s);
        unsigned long long C = stoull(p);
        if ( X <= C ) result.push_back(X);
        
    }
    
    return result.size();
}