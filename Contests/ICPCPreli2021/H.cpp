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

class SegmentTree {
    #define Lc( idx )      idx * 2
    #define Rc( idx )      idx * 2 + 1
    public:
        struct node {
            vector<ll> arr;
            bool marked;
            node () {
                arr.resize(26);
                for(int i=0;i<26;i++) arr[i]=0;
                marked=false;
            }
        };
        vector < node > segT;
        string A;

        SegmentTree( int sz ) {
            segT.resize(4 * sz + 10);
            A.resize(sz + 1);
        }

        node Merge(node L, node R) {
            node F;
            for(int i=0;i<26;i++)
            {
                F.arr[i]=L.arr[i]+R.arr[i];
            }
            return F;
        }

        void MakeSegmentTree( int L, int R, int idx ) {
            if ( L == R ) {
                segT[idx].arr[A[L-1]-'a']=1;
                return;
            }

            int M = ( L + R ) / 2;

            MakeSegmentTree( L, M, Lc( idx ) );
            MakeSegmentTree( M + 1, R, Rc( idx ) );
            segT[ idx ] = Merge( segT[ Lc( idx ) ], segT[ Rc( idx ) ] );
        }

        void push(int idx, int L, int R)
        {
            int M = ( L + R ) / 2;
            if(segT[idx].marked)
            {
                for(int i=0;i<26;i++)
                {
                    segT[idx*2].arr[i]=(segT[idx].arr[i]+1)/2;
                    segT[idx*2+1].arr[i]=(segT[idx].arr[i]/2);
                }
                segT[idx*2].marked=segT[idx*2+1].marked=true;
                segT[idx].marked=false;
            }
        }

        node RangeQuery( int L, int R, int idx, int l, int r) {
            node F;
            //cout << L << " " << R << " " << idx << " " << carry << " " << l << " " << r << "\n";
            if ( L > r || R < l )    return F;
            if ( L >= l && R <= r ) {
            F= segT[idx];
            return F;
            }
            push(idx, L, R);

            int M = ( L + R ) / 2;

            F = Merge( RangeQuery( L, M, Lc( idx ), l, r),
            RangeQuery( M + 1, R, Rc( idx ), l, r) );
            
            return F;
        }


        void RangeUpdate(int L, int R, int idx, int l, int r, ll x) {
            if(L>r || R<l) return;
            if(L!=R) push(idx, L, R);
            if(L>=l && R<=r)
            {
                segT[idx].marked=true;
                for(int i=0;i<26;i++)
                {
                    if(i==x) segT[idx].arr[i]=(R-L+1);
                    else segT[idx].arr[i]=0;
                }
                return;
            }
            int M = ( L + R ) / 2;
            RangeUpdate(L, M, idx*2, l, r, x);
            RangeUpdate(M+1, R, idx*2+1, l, r, x);
            segT[idx]=Merge(segT[idx*2], segT[idx*2+1]);
        }
};

void solve()
{
    string P, Q; cin >> P >> Q;
    ll n=P.length(), m=Q.length();
    SegmentTree pst(n+1), qst(m+1);

    pst.A=P;
    pst.MakeSegmentTree(1, n, 1);
    qst.A=Q;
    qst.MakeSegmentTree(1, n, 1);
    /* pst.RangeUpdate(1, n, 1, 3, 4, 0);

    for(int i=0;i<26;i++)
    cout << pst.RangeQuery(1, n, 1, 2, 5).arr[i] << "\n"; */

    ll M; cin >> M;
    while(M--)
    {
        ll com; cin >> com;
        if(com==1 || com==2)
        {
            ll L, R; char c;
            cin >> L >> R >> c;
            if(com==1)
            {
                pst.RangeUpdate(1, n, 1, L, R, c-'a');
            }
            else
            {
                qst.RangeUpdate(1, n, 1, L, R, c-'a');
            }
        }
        else
        {
            ll L[2], R[2]; for(int i=0;i<2;i++) cin >> L[i] >> R[i];
            ll ans=(R[0]-L[0]+2)*(R[1]-L[1]+2);
            //cout << ans << "\n";
            for(int i=0;i<26;i++)
            {
                ans-=(pst.RangeQuery(1, n, 1, L[0], R[0]).arr[i]*qst.RangeQuery(1, n, 1, L[1], R[1]).arr[i]);
            }
            cout << ans << "\n";
        }
    }
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
        //cout << "Case " << i << "\n";
        solve();
    }
}
