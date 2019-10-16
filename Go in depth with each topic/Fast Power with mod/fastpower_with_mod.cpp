ll power(ll base, ll exp)
{
    ll ans = 1;
    base%=mod;
    while(exp>0)
    {
        if(exp&1) ans = (ans*base)%mod;
        exp>>=1;
        base = (base*base)%mod;
    }
    return ans;
}