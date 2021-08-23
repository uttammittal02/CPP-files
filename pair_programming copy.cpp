#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;
#define int long long 
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define tester int t;cin>>t;while(t--)
#define looper(a,b,c) for(int a=b;a<c;a++)
#define ss second
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define mod 1000000007
    
int32_t main(){
    tester{
        int k,n,m;cin>>k>>n>>m;
        vi arr1,arr2;
        looper(i,0,n){
            int x;cin>>x;arr1.pb(x);
        }
        looper(i,0,m){
            int x;cin>>x;arr2.pb(x);
        }
        int i=0,j=0;
        int total=n+m;
        int count=0;
        bool done=true;
        vi result;
        while(count!=total){
            if(i==n){
                looper(a,j,m){
                    if(arr2[a]<=k){
                        result.pb(arr2[a]);
                    }else{
                        done=false;
                        break;
                    }
                }
                break;
            }
            if(j==m){
                looper(a,i,n){
                    if(arr1[a]<=k){
                        result.pb(arr1[a]);
                    }else{
                        done=false;
                        break;
                    }
                }
                break;
            }
            if(arr1[i]==0 | arr2[j]==0){
                // cout<<"1a"<<endl;
                if(arr1[i]==0){
                    // cout<<0<<" ";
                    result.pb(0);
                    i++;k++;count++;
                }
                if(arr2[j]==0){
                    result.pb(0);
                    k++;
                    j++;count++;
                }
            }else{
                if(arr1[i]<arr2[j]){
                    // cout<<"2a"<<endl;
                    if(arr1[i]<=k){

                        result.pb(arr1[i]);
                        count++;i++;
                    }else{
                        done=false;
                        break;
                    }
                }else if(arr1[i]>arr2[j]){
                    // cout<<"3a"<<endl;
                    if(arr2[j]<=k){
                        result.pb(arr2[j]);
                        count++;j++;
                    }else{
                        done=false;
                        break;
                    }
                }else if(arr1[i]==arr2[j] ){
                    // cout<<"4a"<<endl;
                    if(arr1[i]>k){
                        done=false;
                        break;
                    }
                    result.pb(arr1[i]);result.pb(arr2[j]);
                    count+=2;
                    i++;j++;
                }
            }


        }
        if(done==false){
            cout<<-1;
        }else{
            looper(i,0,result.size()){
                cout<<result[i]<<" ";
            }
        }
        cout<<endl;

    }   
    return 0;
}