// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/trie_policy.hpp>

#define ll                long long int
#define ld                long double
#define vi                vector<ll>
#define vs                vector<string>
#define umap              unordered_map
#define uset              unordered_set
#define mod               1000000007
#define inf               1e18
#define pq                priority_queue
#define pqi               priority_queue<ll>
#define pqimn             priority_queue<ll,vi,greater<ll>>
#define pb                push_back
#define pii               pair<ll,ll>
#define ss                second
#define ff                first
#define mid(l,r)          (l+((r-l)/2))
#define bitc(x)           __builtin_popcount(x)
#define loop(i,a,b)       for(long long int i=(a);i<=b;i++)
#define loorev(i,a,b)     for(long long int i=(a);i>=b;i--)
#define iter(c,it)        for(__typeof(c.begin) it = c.begin(); it != c.end();it++)
#define log(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
// using namespace __gnu_pbds;


template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
     cout << *it << '=' << a << endl;
     err(++it, args...);
}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
// typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> ptrie; //patricia trie
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
     #endif 
     
     ll t=1;
     cin>>t;
     uset<ll> s;
     while(t--)
     {
          ll w;
          cin>>w;
          auto it=s.find(w);
          if (it!=s.end())
          {
               it=s.find(w+1);
               if (it!=s.end())
               {
                    if (w!=1)
                    {
                         it=s.find(w-1);
                         if (it==s.end())
                         {
                              s.insert(w-1);
                              // cout<<w<<'\n';
                         }
                         
                    }
               }
               else
               {
                    s.insert(w+1);
                    // cout<<w<<'\n';
               }
               
          }
          else
          {
               s.insert(w);
               // cout<<w<<'\n';
          }
          
     }
     cout<<s.size();
     cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
     return 0;
}
