#include <iostream>
#include <vector>
#define vi vector<int>
#define pb push_back()
using namespace std;
#define loop(var, lower, upper) for(int var = lower; var < upper; var++)

class Min_heap
{
private:
    /* data */
public:
    Build_Min_heap(vector &v, int n){
        
    };
    ~Min_heap();
};

Min_heap::Min_heap(/* args */)
{
}

Min_heap::~Min_heap()
{
}



int main(){
    vi v;
    int n;
    cin>>n;
    loop(i, 0, n){
        int temp;
        cin>>temp;
        v.pb(temp);
    }

}