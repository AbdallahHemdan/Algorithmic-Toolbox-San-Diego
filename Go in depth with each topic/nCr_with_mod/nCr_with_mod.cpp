ll mod = 1e9+7;
const int N = 1e5+10;

ll fact[N];

void ComputeFactorial() // Don't forget to compute the factorial
{
    fact[0] = 1;
    for(ll i=1;i<N;i++)
        fact[i] = (fact[i-1]%mod * i%mod)%mod;
}

ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

ll modInverse(ll n)
{
    return power(n, mod-2);
}

ll nCr(ll n, ll r)
{
   if (r==0)
      return 1;

    return (fact[n]* modInverse(fact[r]) % mod *
            modInverse(fact[n-r]) % mod) % mod;
}