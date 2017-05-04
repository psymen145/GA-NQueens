#include <iostream>

#include <iostream>
#include <time.h>

using namespace std;

int main() {
    
    srand(time(NULL));
    
    int x;
    
    cout << "test" << endl;
    cin >> x;
    
    while (x != 1) {
        cout << rand() % 2 << endl;
        
        
        cout << "test" << endl;
        cin >> x;
    }
    
    return 0;
}
