#include <bits/stdc++.h>

using namespace std;

int z_order(int n, int r, int c) {

    if (n == 0) return 0;
    
    int size = 1 << (n - 1);
    int quadrant_size = size * size;
    
    if (r < size && c < size)
        return z_order(n - 1, r, c); 
    
    else if (r < size && c >= size)
        return quadrant_size + z_order(n - 1, r, c - size); 
    
    else if (r >= size && c < size)
        return 2 * quadrant_size + z_order(n - 1, r - size, c); 

    else
        return 3 * quadrant_size + z_order(n - 1, r - size, c - size); 

}

int main() {

    int N, r, c;
    cin >> N >> r >> c;
    cout << z_order(N, r, c) << endl;

    return 0;
}
