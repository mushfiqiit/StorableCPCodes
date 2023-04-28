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
const ll mx=501, INF=1e16+1;
vector<pi> g[mx];
ll dis[mx][mx]; ll n, m, s, t, c, d;
bool dijkstra(int initial) {
    forn(i, n) { forn(j, initial) dis[i][j]=INF; } dis[s][initial]=0;
    priority_queue<pair<pair<ll, ll>, ll > > pq; pq.push(mp(mp(0, initial), s));
    
    while(!pq.empty()) {
        auto [du, eu]=pq.top().first; ll u=pq.top().second; pq.pop();
        du=-du;
        if(dis[u][eu]<du) continue; ll minweight=INF;
        //cout << u << " " << du << " " << eu << "\n";
        //if(u==s)
        for(auto [v, w]: g[u]) {  
            if(dis[v][eu-1]>du+w && eu>1 && du+w<=c) { dis[v][eu-1]=du+w; pq.push(mp(mp(-dis[v][eu-1], eu-1), v));
            //cout << "v " << v << " " << du+w << " " << dis[v][eu-1] << " " << pq.size() << "\n"; 
            }
            if(dis[v][initial]>du+w+d+d && eu>0 && du+w+d+d<=c) { dis[v][initial]=du+w+d+d; pq.push(mp(mp(-dis[v][initial], initial), v)); }
            if(w<minweight) { minweight=w; }
        }
        if(dis[u][initial]>du+minweight+d && du+minweight+d<=c) { dis[u][initial]=du+minweight+d;
            pq.push(mp(mp(-dis[u][initial], initial), u));
        }
    }
    forn(i, initial) { if(dis[t][i]<=c) return true; }
    return false;
}

void solve()
{
    cin >> n >> m >> s >> t >> c >> d; forn(i, n) { g[i].clear(); }
    forn(i, m) { ll u, v, w; cin >> u >> v >> w; g[u].pb(mp(v, w)); g[v].pb(mp(u, w)); }
    int l=1, r=mx; //cout << dijkstra(5) << "\n";
    while(l<r) { int mid=(l+r)/2; if(dijkstra(mid)) { r=mid; } else { l=mid+1; }
    } if(l==mx) { cout << "Impossible\n"; return; }
    cout << l << "\n";
}

int main()
{
//freopen("input.txt", "r", stdin);
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
