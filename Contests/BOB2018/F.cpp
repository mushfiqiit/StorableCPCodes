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
ll const mx=1e6+5;
int sv[mx+5];
int cnt[mx+5];

ll gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}

void siv()
{
    for(ll i=2;i<mx;i++)
    {
        if(sv[i]<=1)
        for(ll j=i*2LL;j<mx;j+=i)
        {
            sv[j]=max(sv[j], sv[i]+1);
        }
    }
    for(int i=1;i<mx;i++)
    {
        cnt[i]=cnt[i-1];
        if(sv[i]<=1) cnt[i]++;
    }
}

void solve()
{
    ll N; cin >> N;
    ll num=cnt[N]; ll den=N;
    ll g=gcd(num, den);
    num/=g; den/=g;
    cout << num << "/" << den << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    siv();
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        cout << "Case " << i << ": ";
        solve();
    }
}
