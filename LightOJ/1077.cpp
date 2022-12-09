#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 1; i <= int(n); i++)
#define sz(v) (int)v.size()

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

void solve()
{
    pi point[2]; for(int i=0;i<2;i++) cin >> point[i].first
    >> point[i].second;
    ll a=point[1].second-point[0].second;
    ll b=point[1].first-point[0].first;
    ll g=gcd(a, b); ll n=a/g; ll m=b/g;
    //cout << a << " " << m << "\n";
    ll ans; if(m!=0)
    ans=abs(b/m)+1;
    else ans=abs(a)+1;
    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        cout << "Case " << i << ": ";
        solve();
    }
}
