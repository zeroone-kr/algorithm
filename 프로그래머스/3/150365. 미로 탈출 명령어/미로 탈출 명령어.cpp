#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> pathVector;
int n, m, r, c, k;
bool found = false;


void dfs(int x, int y, int depth, string path) {

    int remainingDistance = abs(r - x) + abs(c - y);
    if (remainingDistance > (k - depth) || (k - depth -remainingDistance) % 2 != 0 ) {
        return;
    }

    if (x == r && y == c && depth == k) {
        pathVector.push_back(path);
        found = true;
        return;
    }

    // down
    if (x + 1 >= 1 && x + 1 <= n) {
        dfs(x + 1, y, depth + 1, path + 'd');
        if(found) return;
    }
    
    // left
    if (y - 1 >= 1 && y - 1 <= m) {
        dfs(x, y - 1, depth + 1, path + 'l');
        if(found) return;
    }
    // right
    if (y + 1 >= 1 && y + 1 <= m) {
        dfs(x, y + 1, depth + 1, path + 'r');
        if(found) return;
    }
    // up
    if (x - 1 >= 1 && x - 1 <= n) {
        dfs(x - 1, y, depth + 1, path + 'u');
        if(found) return;
    }
}

string solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {

    n = _n;
    m = _m;
    r = _r;
    c = _c;
    k = _k;

    dfs(_x, _y, 0, "");

    if (pathVector.empty()) {
        return "impossible";
    }

    // sort(pathVector.begin(), pathVector.end());
    return pathVector[0];
}
