#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll nCrModpDP(ll n, ll r, ll mod)
    {
        ll i,j;
        ll C[r+1];
        memset(C, 0, sizeof(C));

        C[0] = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = min(i, r); j > 0; j--)
                C[j] = (C[j] + C[j-1])%mod;
        }
        return C[r];
    }

    ll nCrModpLucas(ll n, ll r, ll mod)
    {
        if (r==0)
            return 1;

        ll ni = n%mod, ri = r%mod;
        return (nCrModpLucas(n/mod, r/mod, mod) * nCrModpDP(ni, ri, mod)) % mod;
    }

int main()
{
    ll n=5;
    ll r=2;
    ll mod=1000000007;
    cout << nCrModpLucas(n, r, mod);
}
