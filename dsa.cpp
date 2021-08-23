#include <iostream>
#include <vector>
using namespace std;

vector <int> v(5, 0);

int main(){
    int arr[] = {};
    v.resize(4);
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<endl;
        // cout<<v.unique()<<endl;
    }
    return 0;
}