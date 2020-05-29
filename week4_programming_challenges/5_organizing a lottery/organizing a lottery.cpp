// Author : Abdallah Hemdan
// For Hassanosama, ICPC next year ISA.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define all(v) ((v).begin()), ((v).end())
#define rall(v) ((v).rbegin()), ((v).rend())
#define mms(a,val) memset(a,val,sizeof(a))
#define endl '\n'
#define sz size()
#define pii pair<int,int>
#define pll pair<ll,ll>


using namespace std;
using ll = long long int;
using ld = long double;

vi naive_count_segments(vi starts, vi ends, vi points) {
    vi ret(points.size());
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < starts.size(); j++) {
            ret[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("In.txt", "r", stdin);
#endif
	int n, m;
    cin >> n >> m;
    vi starts(n), ends(n), points(m);
    for (int i = 0; i < starts.sz; i++) {
        cin >> starts[i] >> ends[i];
    }
    for (int i = 0; i < points.size(); i++) {
        cin >> points[i];
    }
    
    vi ret = naive_count_segments(starts, ends, points);
    for (int i = 0; i < ret.sz; i++) {
        cout << ret[i] << ' ';
    }
    cout << endl;
}
