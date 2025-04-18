#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N = 2e5 + 19;
#define MOD1 1000000007
#define MOD 998244353
#define INF 1e18
#define endl "\n"
#define py cout << "Yes\n";
#define pn cout << "No\n";
#define pub push_back
#define F first
#define S second
#define nl cout << "\n";
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define pY cout << "YES" << endl;
#define pN cout << "NO" << endl;

// #define TEM template <class... T>
// TEM ostream &operator<<(ostream &out, const pair<T...> &p) { return out << '(' << p.first << ", " << p.second << ')'; }
// TEM istream &operator>>(istream &in, pair<T...> &p) { return in >> p.first >> p.second; }
// #define def_out(cont)                                          \
// TEM ostream &operator<<(ostream &out, const cont<T...> &A) \
// {                                                          \
// 	int i = 0;                                             \
// 	auto it = A.begin();                                   \
// 	while (it != A.end())                                  \
// 		out << &" "[!i++] << *it++;                        \
// 	return out;                                            \
// }
// #define def_in(cont)                                    \
// TEM istream &operator>>(istream &in, cont<T...> &A) \
// {                                                   \
// 	for (auto &a : A)                               \
// 		in >> a;                                    \
// 	return in;                                      \
// }
// def_out(set) def_out(vector) def_out(deque) def_out(map) def_in(vector) def_in(deque)

// // #define nl cout<<"\n";
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

// #define Case   // for LOJ
// #define Yamin_ //for interactive

void solve()
{
    int k;
    cin>>k;
    if(k==0)return;
    int n,m;
    cin>>n>>m;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        if(x==n || y== m)
        {
            cout<<"divisa";
        }
        else if(x<n && y>m)
        {
            cout<< "NO";
        }
        else if(x>n && y>m)
        {
            cout<< "NE";
        }
        else if(x<n && y<m)
        {
            cout<< "SO";
        }
        else cout<< "SE";
        cout<<endl;
    }
    solve();

}

int main()
{
#ifndef Yamin_
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif

int t = 1;
// cin >> t;

for (int i = 1; i <= t; i++)
{
#ifdef Case
	cout << "Case " << i << ": ";
#endif
	solve();
}
}
