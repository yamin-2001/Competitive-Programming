#include<bits/stdc++.h>
using namespace std;
class FenwickTree{
private:
    vector<long long>tree;
    int n;
public:
    FenwickTree(int x)
    {
        n=x;
        tree.assign(n+1,0);

    }
    void update(int i,long long x)
    {
        for(;i<=n;i+=(i & (-i)))
        {
            tree[i]+=x;
        }
    }
    long long  sum(int i)
    {
        long long ans=0;
        for(;i>0;i-=(i&(-i)))
        {
            ans+=tree[i];
        }
        return ans;
    }
    long long query(int l,int r)
    {
        return (sum(r)-sum(l-1));
    }
};
