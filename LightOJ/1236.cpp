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
    for(ll i=2;i<mx;i++)
    {
        if(!sv[i]) { prime.pb(i);
            for(ll j=i*i;j<mx;j+=i)
            {
                sv[j]=true;
            }
        }
    }
}

ll otn(ll n) {
    return (2*n-1);
}

void solve()
{
    ll n; cin >> n; ll ans=1;
    for(ll p:prime)
    {
        ll cnt=0; if(p*p>n) break;
        while(n%p==0) { n/=p; cnt++; }
        //cout << cnt << " " << p << "\n";
        ans*=otn(cnt+1);
    }
    if(n>1) ans*=3;
    cout << (ans/2) +1 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
#endif
    /* ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);  */
    siv(); 
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        cout << "Case " << i << ": ";
        solve();
    }
}
