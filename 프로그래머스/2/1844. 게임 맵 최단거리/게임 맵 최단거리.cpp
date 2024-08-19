#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int visited[MAX][MAX];

typedef struct point{
    int x;
    int y;
}Point;


int solution(vector<vector<int> > maps)
{
    int width = maps[0].size();
    int height = maps.size();    
    int answer = 0;
    
    queue<Point> q;
    
    Point start_point = {0, 0};
    q.push(start_point);
    
    visited[0][0] = 1;
    
    while(!q.empty()){
        
        Point c = q.front();
        q.pop();
        
        int cur_x = c.x; 
        int cur_y = c.y;
        
        if(cur_x-1 >= 0 && maps[cur_y][cur_x-1]==1 && visited[cur_y][cur_x-1] == 0){
            q.push({cur_x-1, cur_y});
            visited[cur_y][cur_x-1]=visited[cur_y][cur_x]+1;
        }
            
        if(cur_x+1 < width && maps[cur_y][cur_x+1]==1 && visited[cur_y][cur_x+1] == 0){
            q.push({cur_x+1, cur_y});
            visited[cur_y][cur_x+1]=visited[cur_y][cur_x]+1;
        }
            
        if(cur_y-1 >= 0 && maps[cur_y-1][cur_x]==1 && visited[cur_y-1][cur_x] == 0){
            q.push({cur_x, cur_y-1});
            visited[cur_y-1][cur_x]=visited[cur_y][cur_x]+1;
        }
        
        if(cur_y+1 < height && maps[cur_y+1][cur_x]==1 && visited[cur_y+1][cur_x] == 0){
            q.push({cur_x, cur_y+1});
            visited[cur_y+1][cur_x]=visited[cur_y][cur_x]+1;
        }    
        
    }

    if (!visited[height-1][width-1]) {
        return -1;
    }
    
    return visited[height-1][width-1];
}