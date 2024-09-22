#include <string>
#include <vector>
#include <sstream>

using namespace std;


int timeToSeconds(string time) {
    stringstream ss(time);
    string mm, ss_str;
    getline(ss, mm, ':');
    getline(ss, ss_str);
    return stoi(mm) * 60 + stoi(ss_str);
}

string secondsToTime(int seconds) {
    int mm = seconds / 60;
    int ss = seconds % 60;
    string mm_str = (mm < 10 ? "0" : "") + to_string(mm);
    string ss_str = (ss < 10 ? "0" : "") + to_string(ss);
    return mm_str + ":" + ss_str;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int videoLength = timeToSeconds(video_len);
    int currentPosition = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);
    

    for (const auto& command : commands) {
        if (command == "next") {
            
            if (currentPosition >= opStart && currentPosition <= opEnd) {
                currentPosition = opEnd + 10;            
            }else{
                currentPosition += 10;
                if (currentPosition >= opStart && currentPosition <= opEnd) {
                    currentPosition = opEnd;
                }
            }       
            
            if (currentPosition > videoLength) {
                currentPosition = videoLength;  
            }

        } else if (command == "prev") {
            currentPosition -= 10;
            if (currentPosition < 0) {
                currentPosition = 0; 
            }
            if (currentPosition >= opStart && currentPosition <= opEnd) {
                currentPosition = opEnd;
            }
        }
    }

    return secondsToTime(currentPosition);
}
