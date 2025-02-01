#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    int mp, mf, ms, mv;

    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    int inp, inf, ins, inv, inc;

    vector<vector<int>> table(N);;
    
    for(auto &v : table){

        cin >> inp >> inf >> ins >> inv >> inc; 
        v.push_back(inp);
        v.push_back(inf);
        v.push_back(ins);
        v.push_back(inv);
        v.push_back(inc);
    }

    int min_cost = numeric_limits<int>::max();
    map<int, vector<vector<int>>> mymap;

    for(int i=1; i < (1 << N); ++i){

        vector<int> vec;
        int p, f, s, v, cost;
        p = f = s = v = cost = 0;

        for(int j=0; j < N; j++){

            if( i & (1 << j)){

                vec.push_back(j+1);    
                p += table[j][0];
                f += table[j][1];
                s += table[j][2];
                v += table[j][3];
                cost += table[j][4];
            }
        }

        if (p >= mp && f >= mf && s >= ms && v >=mv){
            if(min_cost >= cost){
                min_cost = cost;
                mymap[min_cost].push_back(vec);
            }
        }
    }


    if (min_cost == numeric_limits<int>::max()){
        cout << -1 << '\n';
    }else{

        sort(mymap[min_cost].begin(), mymap[min_cost].end());
        cout << min_cost << '\n';
        for(int E : mymap[min_cost][0]){
            cout << E << " ";
        }

    }

}