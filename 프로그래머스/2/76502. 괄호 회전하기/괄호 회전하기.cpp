#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string& s, int start){
    
    stack<char> S;
    unsigned int sz = s.size();
    
    for(int i=0; i < sz; ++i){
        
        char c = s[(start + i) % sz];
        
        if (c == '(' || c == '[' || c == '{'){
            
            S.push(c);
            
        }else{
            
            if (S.empty()) return false;
            
            if ( S.top() == '(' && c != ')') 
                return false;
            
            if ( S.top() == '{' && c != '}' )
                return false;
            
            if ( S.top() == '[' && c != ']' )
                return false;
            
            S.pop();
            
        }
    }   
    
    return S.empty();
    
}

int solution(string s) {
    
    int answer = 0;
    int n = s.size();
    
    for(int i =0 ;i < n ; ++i){
        answer += isValid(s, i);   
    }    
   
    return answer;
}