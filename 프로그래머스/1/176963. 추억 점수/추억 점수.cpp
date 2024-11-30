#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> dict_yearning;
    for(int i=0 ; i < name.size() ; ++i){
        dict_yearning[name[i]] = yearning[i];
    }
    
    for(const auto& _photo : photo){
        int sum =0;
        for(const auto& __photo : _photo){
            sum += dict_yearning[__photo];
        }
        answer.push_back(sum);
    }
    
    return answer;
}