#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define loop(j, n) for(int i = j; i < n; i++)
using namespace std;

// i -> row number
// j -> column number
// n -> number of rows
// m -> number of columns
// li -> input list
// marked -> visiting check
// result -> groups of 1

vector <vector<int> > marked;
vector <string> li(0);
vector <int> result;
int cnt;
void land_sizes(int i, int j, int n, int m){
    if (li[i][j] == '1' && marked[i][j] == 0) cnt++, marked[i][j] = 1;
    else return;
    bool cond1, cond2, cond3, cond4;
    cond1 = true;
    cond2 = true;
    cond3 = true;
    cond4 = true;
    if (i != 0 && li[i-1][j] != '0' && marked[i-1][j] == 0){
        land_sizes(i-1, j, n, m);
    }
    else cond1 = false;
    if (j != 0 && li[i][j-1] != '0' && marked[i][j-1] == 0){
        land_sizes(i, j-1, n, m);
    }
    else cond2 = false;
    if (i != n-1 && li[i+1][j] != '0' && marked[i+1][j] == 0){
        land_sizes(i+1, j, n, m);
    }
    else cond3 = false;
    if (j != m-1 && li[i][j+1] != '0' && marked[i][j+1] == 0){
        land_sizes(i, j+1, n, m);
    }
    else cond4 = false;
    if (!cond1 && !cond2 && !cond3 && !cond4) return;
    return;
}
int main(){
    int t;
    cin>>t;
    loop(0,t){
        int n, m;
        cin>>n>>m;
        li.resize(0);
        marked.resize(0);
        result.resize(0);
        loop(0,n){
            string s;
            cin>>s;
            li.push_back(s);
        }
        vector <int> collections(m, 0);
        
        loop(0,n){
            marked.push_back(collections);
        }
        
        loop(0,n){
            for (int j = 0; j < m; j++){
                if (marked[i][j] == 0 && li[i][j] == '1'){
                    cnt = 0;
                    land_sizes(i, j, n, m);
                    result.push_back(cnt);
                }
            }
        }
        sort(result.begin(), result.end(), greater<int>());
        int sum = 0;
        for(int i = 1; i < result.size(); i+=2){
            sum += result[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}