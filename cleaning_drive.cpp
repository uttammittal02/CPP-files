#include <iostream>
#include <vector>
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;

int main(){
    int t;
    cin>>t;
    loop(0,t){
        int n, m;
        cin>>n>>m;
        bool l_found = false;
        bool r_found = false;
        vector <int> li_l;
        vector <int> li_r;
        loop(0, m){
            int l, r;
            cin>>l>>r;
            li_l.push_back(l);
            li_r.push_back(r);
            if (l == 1) l_found = true;
            if (r == n) r_found = true;
        }
        if (l_found == false || r_found == false) {cout<<-1<<endl; continue;}
        
    }
    return 0;
}