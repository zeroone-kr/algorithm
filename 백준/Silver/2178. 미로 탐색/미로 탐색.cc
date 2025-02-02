#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool visited[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


typedef struct point {

    int x; 
    int y;
    int val;
}P;

int N, M;

void bfs(){

    P start;
    start.x=0;
    start.y=0;
    start.val=1;
    visited[start.x][start.y] =1 ;
    queue<P> Q;

    Q.push(start);

    while(!Q.empty()){

        P base = Q.front();
        Q.pop();

        if(base.x == N-1 && base.y == M-1){
            cout << base.val << endl;
        }

        for(int i=0 ; i < 4; i++){
        
            int nx = base.x + dx[i];
            int ny = base.y + dy[i];
            if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1)
                continue;

            if(visited[nx][ny] == 0 && arr[nx][ny] == 1){

                P newP;
                newP.x  = nx; newP.y = ny; newP.val = base.val+1;
                visited[nx][ny] = 1;
                Q.push(newP);    

            }

        }
    }
}


int main(){


    cin >> N >> M;
    
    for(int i=0 ; i < N; ++i){
        
        string row;
        cin >> row;

        for (int j=0; j < M; ++j){
            
            arr[i][j] = row[j] - '0';
        }
            
    }

    bfs();
}