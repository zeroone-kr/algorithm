#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    if(price >= 500000){
        price = price*(1- 0.2);
    }else if(price >= 300000){
        price = price*(1- 0.1);
    }else if(price >= 100000){
        price = price*(1- 0.05);
    }
    
    answer = price;
    return answer;
}