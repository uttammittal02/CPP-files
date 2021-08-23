#include <iostream>
using namespace std;

int hello(int n){
    cout<<n<<endl;
    return n;
}

int main(){
    int(*ptr)(int) = hello;
    ptr(7);
    cout<<ptr<<" "<<*ptr<<endl;
}
