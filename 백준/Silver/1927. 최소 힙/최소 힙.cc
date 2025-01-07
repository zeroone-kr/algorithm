#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, std::vector<int>, greater<int>> min_heap;
    vector<int> answer;

    int total;
    cin >> total;

    for (int i=0; i < total ; ++i){
        int n;
        cin >> n;

        if (n == 0){
            if (min_heap.empty()) cout << "0" << "\n";
            else{
                // answer.push_back(min_heap.top());
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
            continue;
        }

        min_heap.push(n);
    }


    return 0;
}
