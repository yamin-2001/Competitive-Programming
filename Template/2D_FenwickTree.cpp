#include<bits/stdc++.h>
using namespace std;
class FenwickTree2D{
private:
    vector<vector<long long>>tree;
    int n,m;
public:
    FenwickTree2D(int x,int y)
    {
        n=x;
        m=y;
        tree.assign(n+1,vector<long long>(m+1,0));
    }
    void update(int i,int j,long long x)
    {
        for(;i<=n;i+=(i & (-i)))
        {
            for(int jj=j;jj<=m;jj+= (jj & (-jj)))
            {
                tree[i][jj]+=x;
            }
        }
    }
    long long  sum(int i,int j)
    {
        long long ans=0;
        for(;i>0;i-=(i&(-i)))
        {

            for(int jj=j;jj>0;jj-=(jj&(-jj)))ans+=tree[i][jj];
        }
        return ans;
    }
    long long query(int l1,int r1,int l2,int r2)
    {
        return sum(l2,r2)-sum(l1-1,r2)-sum(l2,r1-1)+sum(l1-1,r1-1);
    }
};
