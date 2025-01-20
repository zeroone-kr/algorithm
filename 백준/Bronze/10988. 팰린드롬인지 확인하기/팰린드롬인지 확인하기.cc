#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string in;
    cin >> in;
    string cp = in;
    reverse(in.begin(), in.end());

    if (cp == in) cout << "1" << "\n";
    else cout << "0" << "\n";

}