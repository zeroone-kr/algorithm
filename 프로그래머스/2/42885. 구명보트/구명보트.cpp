#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    
    sort(people.rbegin(), people.rend());
    
    int heavy=0, light=people.size()-1;
    
    while(heavy <= light){
        
        if (heavy == light && people[heavy] <= limit){
            // answer++;
            // heavy++;
        }else if (people[heavy] + people[light] <= limit){
        
            // answer++;
            // heavy++;
            light--;
            
        }else if(people[heavy] <= limit){
            // heavy++;
            // answer++;

        }    
        heavy++;
        answer++;
    }

    return answer;
}