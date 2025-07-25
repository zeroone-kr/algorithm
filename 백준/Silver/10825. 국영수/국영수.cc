#include <bits/stdc++.h>

using namespace std;

struct Student{
    string name;
    int kor, eng, math;
};

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ;
    cin >> n;
    vector<Student> a(n);
    
    for(int i =0; i< n; i++){
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }
    
    sort(a.begin(), a.end(), [](const Student &A, const Student &B){
        if(A.kor != B.kor) return A.kor > B.kor;
        if(A.eng != B.eng) return A.eng < B.eng;
        if(A.math != B.math) return A.math > B.math;
        return A.name < B.name;
    });
    
    for ( auto &s : a ){
        cout << s.name << '\n';
    }
    
    return 0;
}
