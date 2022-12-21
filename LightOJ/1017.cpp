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
const ll mxv=1e18;
void solve()
{
    ll N, w, k; cin >> N >> w >> k; vector<ll> points(N+2); ll tmp;
    forn(i, N) cin >> tmp >> points[i]; points[0]=-mxv; points[N+1]=mxv;
    sort(points.begin()+1, points.end()); ll ans=0;
    //forn(i, N) cout << points[i] << "\n";
    ll dp[N+1][k+1]; memset(dp, 0, sizeof dp); dp[0][0]=0; 
    ll taken[N+1]; taken[0]=0;
    forn(i, N)
    {
        int num=lower_bound(points.begin(), points.end(), points[i]+w+1)-points.begin()-i;
        int prev=lower_bound(points.begin(), points.end(), points[i]-w)-points.begin()-1;
        taken[i]=taken[prev]+1;
        //cout << i << " " << num << " " << prev << "\n";
        for(int j=min(taken[i], k);j>=1;j--)
        {
            dp[i][j]=max(dp[i][j], dp[prev][j-1]+num);
            dp[i][j]=max(dp[i-1][j], dp[i][j]);
            //cout << "dp " << i << " " << j << " " << dp[i][j] << "\n";
            ans=max(ans, dp[i][j]);
        }
        taken[i]=max(taken[i-1], taken[i]);
    }
    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
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
