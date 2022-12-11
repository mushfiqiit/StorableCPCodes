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
const ll mx=1e4+1;
vector<ll> g[mx]; ll vi[mx];
int ans=1;
void dfs(ll u)
{
    vi[u]=1;
    for(ll v:g[u])
    {
        //cout << u << " " << v << "\n";
        if(!vi[v]) dfs(v);
        else if(vi[v]==1) ans=0;
    }
    vi[u]=2;
}

void solve()
{
    ll m; cin >> m; forn(i, m) { vi[i]=0; g[i].clear(); }
    string a, b; ans=1;
    map<string, ll> mapp;
    ll cnt=1;
    forn(i, m) { cin >> a >> b; if(!mapp[a]) mapp[a]=cnt++;
    if(!mapp[b]) mapp[b]=cnt++; ll u=mapp[a], v=mapp[b];
    g[u].pb(v);
    } //for(auto tmp:mapp) cout << tmp.first << " " << tmp.second << "\n";
    forn(i, cnt-1) {
    if(!vi[i]) dfs(i);
    }
    if(ans) { cout << "Yes\n"; }
    else cout << "No\n";
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
