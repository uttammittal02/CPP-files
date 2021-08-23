#include<iostream>
#define loop(j, n) for(int i=j; i<n; i++)
#include<vector>
using namespace std;
int minimum_coins_needed = 0;
void minimum_coins(float val_needed, float current_val,vector<float> &denomination, int coin_count)
{
    
    if(current_val == val_needed)
    {
        if(coin_count<minimum_coins_needed) minimum_coins_needed = coin_count;
        return;
    }
    else if(current_val>val_needed) return;
    for(int index=0; index<denomination.size();index++)
        minimum_coins(val_needed,  current_val+denomination[index], denomination, coin_count+1);
        minimum_coins(val_needed, current_val, denomination, coin_count);
    return;
}
int main()
{
    int n;
    float v;
    cin >> n >> v;
    vector<float> denomination(0);
    loop(0, n)
    {
        float temp;
        cin >> temp;
        denomination.push_back(temp);
    }
    minimum_coins(v, 0, denomination, 0); 
    cout << minimum_coins_needed << endl;
    return 0;
}