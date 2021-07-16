#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define loop(j, n, i) for(int i = j; i < n; i++)
using namespace std;

int main(){
    int t;
    cin>>t;
    loop(0, t, test){
        long long n, w, wr;
        cin>>n>>w>>wr;
        long long arr[n];
        loop(0, n, i){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        vector <long long> ans;
        long long cnt = 0;
        long long temp = arr[0];
        loop(0, n, i){
            if (arr[i] == temp) cnt++;
            else cnt = 1, temp = arr[i];
            if (cnt == 2) {ans.push_back(arr[i]); cnt = 0;}
            }
        long long res = 0;
        loop(0, ans.size(), i){
            res += ans[i];
            // cout<<res;
        }
        float w_reqd = (float)(w-wr)/2;
        // cout<<w_reqd<<endl;
        // cout<<res<<endl;
        if (res >= w_reqd){
        cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;}
    return 0;
}}