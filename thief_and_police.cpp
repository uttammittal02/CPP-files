#include <iostream>
#include <vector>
#include <cmath>
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;

int main(){
    int t;
    cin>>t;
    loop(0, t){
        int n, m, x, y, a, b;
        cin>>n>>m>>x>>y>>a>>b;
        int s = max(n-a, m-b);
        if (a > x && b > y){
            cout<<"NO"<<endl;
            continue;
        }
        else if (n - x + m - y > s){
            printf("NO\n");
        }
        else cout<<"YES"<<endl;
    }
}
