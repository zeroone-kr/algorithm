#include <string>
#include <vector>
#include <iostream>

using namespace std;

int array[100001];

int solution(int n) {
    
    array[0] = 0;
    array[1] = 1;
    
    for(int i=2; i <= n ; ++i){
        array[i] = (array[i-2] + array[i-1]) % 1234567;       
    }
    
    return array[n];
}