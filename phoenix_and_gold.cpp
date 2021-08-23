#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#define loop(j, n, i) for(int i = j; i < n; i++)
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    loop(0, t, test){
        int n, x;
        cin>>n>>x;
        int arr[n];
        loop(0, n, i){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int sum = 0;
        int res = -1;
        vector <int> li;
        for (int i = n-1; i>=0; i--){
            if (x - sum == arr[i]) {res = i; continue;}
            li.push_back(arr[i]);
            sum += arr[i];
        }
        // cout<<res<<arr[res]<<endl;
        if (res != -1 && res != n-1) li.push_back(arr[res]);
        if (res == n-1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            loop(0, n, i){
                cout<<li[i]<<" ";
            }
        }
    if (test != t -1)cout<<"\n";
    }
}