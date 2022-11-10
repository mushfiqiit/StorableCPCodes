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
const ll mx=2021;
int td[mx+5];
void init()
{
    for(int i=1;i<mx;i++)
    {
        int tmp=i;
        while(tmp%2==0) { td[i]++; tmp/=2; }
    }
    //for(int i=1;i<=10;i++) cout << i << " " << td[i] << "\n";
}
​
void solve()
{
    ll k, n; cin >> k >> n;
    ll x=0;
    ll a[n+1]; forn(i, n) { cin >> a[i]; x^=a[i]; }
    if(k==1) { cout << "0\n"; return; }
    else
    {
        ll num=n-1, den=1;
        ll ans=1;
        ll pt=0;
        for(int i=1;i<=min(n-1, k-2);i++)
        {
            pt+=td[num]; pt-=td[den];
            num--; den++;
            if(pt==0) ans=(ans+1)&1;
        }
        if(ans) cout << x << "\n";
        else cout << "0\n";
    }
}
​
int main()
{
#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init();
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        solve();
    }
}
