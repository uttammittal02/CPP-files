#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld EPS = 1e-9,pi = 3.1415926535897;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void setIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
struct P
{
    ld x,y;
    void read(){
        cin>>x>>y;
    }
    P(ld x,ld y)
    {
        (*this).x = x,(*this).y = y;
    }
    P operator +(const P&b)const{
        return P(x + b.x,y + b.y);
    }
    P operator -(const P& b)const {
        return P(x - b.x,y - b.y);
    }
    P operator *(ld d)const {
        return P(x * d,y * d);
    }
    ll dist(const P& other)const{
        return pow(other.x - x,2) + pow(other.y - y,2);
    }
    bool operator <(const P&other)const{
        if (fabs(x - other.x) > EPS)return x < other.x;
        return y < other.y;
    }
    bool operator ==(const P&other)const{
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
    ll cross(const P&other)const{
        return x * other.y - y * other.x;
    }
    ll cross(const P&a, P&b)const{
        return (a - *this).cross(b - *this);
    }
    ll dot(const P&other)const{
        return x * other.x + y * other.y;
    }
};
bool onSegment(P start,P end,P p)
{
    return (p.cross(start,end) == 0) && (start - p).dot(end - p) <= 0;//WHY the dot product ???
}
bool inPolygon(vector<P> &points, P a)
{
    int ret = 0,n = (int)points.size();
    for (int i = 0;i<n;i++){
        P b = points[(i + 1)%n];
        ret ^= ((a.y < points[i].y) - (a.y < b.y)) * a.cross(points[i],b) > 0;
    }
    return ret;
}
P transalate(P v,P p)
{
    return p + v;
}
P scale(P center, ld factor, P p)
{
    return center + (p - center) * factor;
}
ll polygonArea(vector<P> &points)
{
    ll ret = 0;
    int n = (int)points.size();
    for (int i = 0;i<n;i++)ret += points[i].cross(points[(i + 1)%n]);
    return ret;
}
P rot(P p,ld a)
{
    return P(p.x * cos(a) - p.y * sin(a),p.x * sin(a) + p.y * cos(a));
}
P perp(P p)
{
    return P(-p.y,p.x);
}
void solve()
{
	int n;
	cin>>n;
	P delta(0,0);
	P start(0,0);
	while (n--){
		string s;
		cin>>s;
		if (s == "fd"){
			int dist;
			cin>>dist;
			delta.x = dist;
			start = start + delta;
			//cout<<delta.x<<" "<<delta.y<<" "<<start.x<<" "<<start.y<<endl;
		}
		else if (s == "lt"){
			int a;
			cin>>a;
			delta = rot(delta,a * pi/180);
		}
		else{
			int a;
			cin>>a;
			a = 360 - a;
			delta = rot(delta,a * pi/180);
		}
	}
	cout<<start.x<<" "<<start.y<<endl;
}
int main()
{
    setIO();
    int t;
    cin>>t;
    while (t--){
    	solve();
    }
    return 0;
}
