#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    if ( n % 2 ){
        cout << n << " is odd" << endl;
    }else{
        cout << n << " is even" << endl;
    }
    
    return 0;
}