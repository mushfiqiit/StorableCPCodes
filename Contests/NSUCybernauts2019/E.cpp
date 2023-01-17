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
string dl=":;!@#$%^&*";

struct suffix_array {
vector<ll> sa, lcp;
suffix_array(string& s, int lim=256) { 
  #define rep(i,a,b) for(int i=a;i<b;i++)
int n = s.size() + 1, k = 0, a, b; vector<ll> x(s.begin(),s.end()+1), y(n),
ws(max(n, lim)), rank(n);
sa = lcp = y, iota(sa.begin(),sa.end(), 0);
for (int j = 0, p = 0; p < n; j = max(1, j * 2),
lim = p) {
p = j, iota(y.begin(),y.end(), n - j); rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j; fill(ws.begin(),ws.end(), 0);
rep(i,0,n) ws[x[i]]++;
rep(i,1,lim) ws[i] += ws[i - 1];
for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i]; swap(x, y), p = 1, x[sa[0]] = 0;
rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
    (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1
    : p++;
}
rep(i,1,n) rank[sa[i]] = i;
for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
#undef rep
} };

void solve()
{
    string s, ss;
    ll N; cin >> N; for(int i=0;i<N;i++) { cin >> ss; s+=ss; if(i!=N-1) s+=dl[i]; }
    //cout << s << "\n";
    int len=s.length(); int t=0; int which[len+1];
    for(int i=0;i<len;i++)
    {
        if(!isalpha(s[i])) { which[i]=10; t++; }
        else which[i]=t;
    }
    //for(int i=0;i<len;i++) cout << which[i] << " "; cout << "\n";
    suffix_array sfa(s);
    sfa.lcp.pb(-1);
    /* for(int i=0;i<=len;i++) cout << sfa.sa[i] << " "; cout << "\n";
    for(int i=0;i<=len;i++) cout << sfa.lcp[i] << " "; cout << "\n"; */
    ll ans=0;
    for(int i=1;i+N-1<=len;i++)
    {
        set<ll> unik; ll mi=1e18;
        for(int j=i;j<=i+N-1;j++)
        {
            unik.insert(which[sfa.sa[j]]);
            if(i!=j) { mi=min(mi, sfa.lcp[j]); //cout << i << " " << j << "\n"; 
            }
        }
        //cout << i << " " << sfa.lcp[i] << " " << unik.size() << " " << mi << "\n";
        if(sfa.lcp[i]<mi && sfa.lcp[i+N]<mi && unik.size()==N) { //cout << mi << "\n";
            ans=max(ans, mi); }
    }
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
    //cin >> T;
    forn(i, T)
    {
        solve();
    }
}
