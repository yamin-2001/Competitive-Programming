#inlcude<bits/stdc++.h>
using namespace std;
class Lazy{
public:
vector<int> ST,lazy;
Lazy(int n)
{
    ST.assign(n*4+5,0);
    lazy.assign(n*4+5,-1);
}

void push_down(int node,int l,int r)
{
    if(lazy[node]!=-1)
    {
        ST[node]=(lazy[node])*(r-l+1);
        if(l!=r)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;

    }
}
void update(int node,int st,int en,int l,int r,int v)
{
    push_down(node,st,en);
    if(l>r)return;
    if(st==l && en==r)
    {
        lazy[node]=v;
        push_down(node,st,en);
    }else{
        int mid=(st+en)/2;
        update(node*2,st,mid,l,min(r,mid),v);
        update(node*2+1,mid+1,en,max(l,mid+1),r,v);
        ST[node]=ST[node*2]+ST[node*2+1];
    }


}
int query(int node,int st,int en,int l,int r)
{
    push_down(node,st,en);
    if(l>r)return 0;
    if(st==l && en==r)
    {
        return ST[node];
    }
    int mid=(st+en)/2;
    return query(node*2,st,mid,l,min(r,mid))+query(node*2+1,mid+1,en,max(l,mid+1),r);
}
};
int main(){
  int n;
  cin>>n;
  Lazy lz(n);
}
