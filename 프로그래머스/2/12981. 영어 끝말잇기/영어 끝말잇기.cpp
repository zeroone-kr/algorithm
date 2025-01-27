#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> hmap;
    
    // initialization
    for(const auto word: words){
        hmap[word] = false;    
    }

    hmap[words[0]] = true;    
    auto i = 1;
    int person = 1;
    bool wrong_case = false;
    
    for(i=1; i < words.size() ; ++i){
        
        if (words[i-1][words[i-1].length()-1]  == words[i][0] && !hmap[words[i]] ){         
            hmap[words[i]] = true; 
            continue;    
        }
        
        wrong_case = true;
        break;        
    }
    
    if (!wrong_case){
    
        answer.push_back(0);
        answer.push_back(0);
    
    }else{
        
        answer.push_back(i % n + 1);
        answer.push_back(i / n + 1);
        
    }

    return answer;
}