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
const ll mx=1e7+1;
vector<ll> prime; bool sv[mx];
void siv()
{
    for(int j=4;j<mx;j+=2) sv[j]=true;
    for(ll i=3;i<mx;i+=2)
    {
        if(!sv[i]) { prime.pb(i);
        for(ll j=i*i;j<mx;j+=i) sv[j]=true;
        }
    }
    //cout << prime.size() << "\n";
}

void solve()
{
    ll N; cin >> N; ll ans=1; while(N%2==0) N/=2;
    for(int i=0;i<prime.size();i++)
    {
        ll cnt=0; if(prime[i]*prime[i]>N) break;
        while(N%prime[i]==0) { N/=prime[i]; cnt++; }
        ans*=(cnt+1);
    }
    if(N>1) ans*=2;
    cout << ans-1 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); siv();
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        cout << "Case " << i << ": ";
        solve();
    }
}
