#include<bits/stdc++.h>
using namespace std;
class SegTree{
    public:
    vector<long long> tree;
    int n;
    SegTree(int sz)
    {
        n=sz;
        tree.assign(n*4,0);
    }
    void do_update(int i,long long val,int st,int en,int node)
    {
        // d_bug(i,node,st,en);
        if(i>en || i<st)return;
        if(st==en ){
            if(i==st)tree[node]+=val;
            return;
        }
        int mid=(st+en)/2;
        do_update(i,val,st,mid,node*2+1);
        do_update(i,val,mid+1,en,node*2+2);
        tree[node]=tree[node*2+1]+tree[node*2+2];
    }
    void update(int i,long long val)
    {
        do_update(i,val,0,n-1,0);
    }
    long long make_query(int l,int r,int st,int en,int node)
    {
        if(st>r || en<l)return 0;
        if(st>=l && en<=r)return tree[node];
        int mid=(st+en)/2;
        return (make_query(l,r,st,mid,node*2+1)+make_query(l,r,mid+1,en,node*2+2));
    }
    long long query(int l,int r)
    {
        return make_query(l,r,0,n-1,0);
    }
};
