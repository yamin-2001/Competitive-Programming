#include <bits/stdc++.h>

using namespace std;
string t_case() { static int tc; return "Case " + to_string(++tc) + ':'; }
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int N = 2e5 + 19;
const ll INF = 1e14;
#define endl "\n"
#define pub push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pair<ll, ll>>

 
#ifdef DEBUG
#define L_DELIM cerr << "{ "
#define R_DELIM cerr << " }"
#else
#define L_DELIM
#define R_DELIM
#endif
 
template <class T, size_t N> ostream& operator<<(ostream& out, const array<T, N>& A) { L_DELIM; for (int i = 0; i < N; i++) out << &" "[!i] << A[i]; R_DELIM; return out; }
template <class T, size_t N> istream& operator>>(istream& in, array<T, N>& A) { for (auto& a : A) in >> a; return in; }
#define TEM template <class... T>
TEM istream& operator>>(istream& in, pair<T...>& p) { return in >> p.first >> p.second; }
TEM ostream& operator<<(ostream& out, const pair<T...>& p) { L_DELIM; out << p.first << ", " << p.second; R_DELIM; return out; }
#define def_in(cont) TEM istream& operator>>(istream& in, cont<T...>& A) { for (auto& a : A) in >> a; return in; }
#define def_out(cont) TEM ostream& operator<<(ostream& out, const cont<T...>& A) { L_DELIM; int i = 0; auto it = A.begin(); while (it != A.end()) out << &" "[!i++] << *it++; R_DELIM; return out; }
def_in(vector) def_in(deque) def_out(vector) def_out(deque) def_out(set) def_out(map) def_out(multiset)
 //
#ifdef PB_DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
TEM using ordered_set = tree<T..., null_type, less<T...>, rb_tree_tag, tree_order_statistics_node_update>;
TEM using ordered_multiset = tree<T..., null_type, less_equal<T...>, rb_tree_tag, tree_order_statistics_node_update>;
def_out(ordered_set) def_out(ordered_multiset)
#endif
 
TEM istream& c_in(T&... args) { return ((cin >> args), ...); }
TEM ostream& c_out(const T&... args) { int i = 0; return ((cout << &" "[!i++] << args), ...) << '\n'; }
ostream& c_out(bool b) { return c_out(b ? "YES" : "NO"); }
 
#ifdef DEBUG
TEM ostream& c_err(const T&... args) { int i = 0; return ((cerr << &" "[!i++] << args), ...) << '\n'; }
#else
#define c_err(...)
#endif
#define d_bug(args...) c_err(#args, '=', args)
// #define Case   // for LOJ
// #define Yamin_ //for interactive


void solve()
{
    int n;
    cin>>n;
    vii ans;
    auto f=[&](auto f,int x,int a,int b,int c)->void{
        if(x>0)
        {
            f(f,x-1,a,c,b);
            ans.pub({a,c});
            f(f,x-1,b,a,c);
        }
    };
    f(f,n,1,2,3);
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans )cout<<u<< " "<<v<<endl;
    

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
	cout << "Case " << i << ":"<<endl;
#endif
	solve();
}
}
