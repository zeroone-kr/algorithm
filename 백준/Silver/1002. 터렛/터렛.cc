#include <bits/stdc++.h>

using namespace std;


int bigger(int a, int b){
    if (a > b) return a;
    return b;
}

int smaller(int a, int b){
    if (a > b) return b;
    return a;
}

int main(){

    int N;
    cin >> N;
    vector<int> answer;
    int x1, y1, x2, y2, r1, r2;

    for(int i=0; i < N; ++i){

        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            answer.push_back(-1);
        }

        else if (dist > r1 + r2) {
            answer.push_back(0);
        }
        
        else if (dist < abs(r1 - r2)) {
            answer.push_back(0);
        }
        
        else if (dist == r1 + r2) {
            answer.push_back(1);
        }
        
        else if (dist == abs(r1 - r2)) {
            answer.push_back(1);
        }
        
        else {
            answer.push_back(2);
        }

    }

    for(const auto & A : answer){
        cout << A << '\n';
    }
}