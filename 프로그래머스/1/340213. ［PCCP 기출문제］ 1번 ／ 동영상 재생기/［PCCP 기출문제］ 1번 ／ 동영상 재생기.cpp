#include <string>
#include <vector>

using namespace std;

int timeToSeconds(string time) { 
    string::size_type pos = time.find(":");
    int mm = stoi(time.substr(0, pos));
    int ss = stoi(time.substr(pos+1));
    return mm * 60 + ss;
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
            }       
            
            if (currentPosition > videoLength) {
                currentPosition = videoLength;  
            }

        } else if (command == "prev") {
            currentPosition -= 10;
            if (currentPosition < 0) {
                currentPosition = 0; 
            }
        }
        
        if (currentPosition >= opStart && currentPosition <= opEnd) {
            currentPosition = opEnd;
        }
        
    }

    return secondsToTime(currentPosition);
}
