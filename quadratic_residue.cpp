#include <iostream>
using namespace std;

int main(){
    int a, p;
    cin >> a >> p;
    for (int i = 1; i <= max(1000, p); i++){
        if (((i*i) % p) == a)
            cout << i << endl;
    }
}