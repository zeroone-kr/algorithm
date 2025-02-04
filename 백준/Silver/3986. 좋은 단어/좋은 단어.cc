#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<string> S;

    for(int i=0 ;i < N ; ++i){
        string s;
        cin >> s;
        S.push_back(s);
    }

    stack<char> stack;
    int total= 0;
    for(string &s : S){
        
        for(int i=0; i< s.length(); ++i){

            if(stack.empty()){
            
                stack.push(s[i]);
            
            }else{

                char top = stack.top();
                if(s[i] == top){
                    stack.pop();
                }else{
                    stack.push(s[i]);
                }

            }
            

        }

        if(stack.empty()) total++;
        else {
            while(!stack.empty()){
                stack.pop();
            }
        }
    }

    cout << total << endl;
}