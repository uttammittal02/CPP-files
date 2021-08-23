#include <iostream>
#include <memory>
using namespace std;

struct Player {
    int x, y;
    ~Player(){
        cout<<"player destroyed"<<endl;
    }
};

int main(){
    long long int l = 25L;
    long long int *ptr = &l;
    long long int **ptr1 = &ptr;
    int arr[] = {1, 12, 3, 4};
    cout<<*arr<<" "<<*(arr+1)<<" "<<arr+2<<endl;
    cout<<ptr<<" "<<sizeof(ptr)<<" "<<sizeof(ptr1)<<endl;
    unique_ptr<Player> ptr1 = make_unique<Player>();
    unique_ptr<int> p1 = make_unique<int>();
    unique_ptr<int> p2 = make_unique<int[9]>;
    
}
