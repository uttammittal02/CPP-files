#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    int num = 0;
    int i(0), j(0);
    vector<int> visited(n+1, 0);
    while (i < n && j < n){
        if (visited[a[i]]){
            i++; continue;
        }
        if (a[i] == b[j]){
            visited[b[j]] ++;
            i++; j++; continue;
        }
        // cout<<b[j]<<" "<<a[i]<<endl;
        visited[b[j]]^=1;
        j++;
        num++;
    }
    // cout<<endl;
    cout<<num<<endl;
}
