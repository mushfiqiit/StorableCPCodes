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

void solve()
{
    ll N; cin >> N;
    vector<ll> a[2*N-1]; ll tmp;
    int i=1;
    for(i=0;i<N;i++) { for(int j=0;j<=i;j++) {
        cin >> tmp; a[i].pb(tmp);
    }
    }
    int lim=N-1;
    for(i=N;i<2*N-1;i++)
    {
        for(int j=0;j<lim;j++) {
        cin >> tmp; a[i].pb(tmp);
    }
    lim--;
    }

    vector<ll> dp[2*N-1]; lim=2;
    dp[2*N-2].pb(a[2*N-2][0]);
    for(int i=2*N-3;i>=N-1;i--)
    {
        dp[i].resize(a[i].size()+1, 0);
        for(int j=0;j<lim;j++)
        {
            if(j==0) dp[i][j]=dp[i+1][j]+a[i][j];
            else if(j==lim-1) dp[i][j]=dp[i+1][j-1]+a[i][j];
            else {
                dp[i][j]=max(dp[i+1][j-1], dp[i+1][j])+a[i][j];
            }
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
        lim++;
    }
    for(int i=N-2;i>=0;i--) {
        dp[i].resize(a[i].size()+1, 0);
        for(int j=0;j<=i;j++) dp[i][j]=max(dp[i+1][j],
        dp[i+1][j+1])+a[i][j];
    }
    cout << dp[0][0] << "\n";
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
