#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
        
    vector<string> possible_cases;
    int answer = 0;
    
    string tmp ;
    for ( int i =0 ;i < s.size() ; i++){
        tmp = s.substr(i) + s.substr(0, i);
        possible_cases.push_back(tmp);
    }
    
    for ( auto K : possible_cases){
        
        stack<char> st;
        bool invalid = false;
        
        for ( char c : K ) {
            
            if ( c == '[' || c == '(' || c == '{') st.push(c);
            else{
                if (st.empty()) {invalid=true; break;}
                
                char ch = st.top(); st.pop();
                
                if ( (c == ']' && ch != '[') || 
                     (c == ')' && ch != '(') || 
                     (c == '}' && ch != '{')) {invalid = true; break;}
            }
        }
        
        if (invalid == false && st.empty()) answer += 1;
        
    }
    
    return answer;
}