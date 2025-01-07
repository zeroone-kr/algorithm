#include <bits/stdc++.h>

using namespace std;

int main(){

    int H, W, N, M;
    cin >> H >> W >> N >> M;
    
    N++; M++;
    int X = H / N + ((H % N == 0)? 0 : 1);
    int Y = W / M + ((W % M == 0)? 0 : 1);

    cout << X * Y << endl;

}