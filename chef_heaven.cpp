#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;

int main(){
    int t, l;
    string s;
    string a = "Uttam";
    cout<<a<<endl;
    a[1] = 'p';
    cout<<a<<endl;
    cin>>t;
    vector <int> v;
    for(int k = 0; k<t; k++){
        cin>>l>>s;
        int cnt0 = 0; int cnt1 = 0;
        bool found = false;
        loop(0, s.size()){
            if (s[i] == '1') cnt1++;
            else cnt0++;
            if (cnt1 >= cnt0){ cout<<"YES"<<endl;
            found = true;
            break;}
        if (!found) cout<<"NO"<<endl;
        }
    }
}
