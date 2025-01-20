#include <bits/stdc++.h>

using namespace std;

int main(){


    string str;
    cin >> str;

    map<char, int> result;

    for(int key = 'a'; key < 'z'+1 ; ++key){
        result[key]=0;
    }

    for(const auto& chr : str){
        result[chr]++;
    }

    for(const auto& pair : result) {
        cout << pair.second << " ";
    }
    cout  << endl;


}