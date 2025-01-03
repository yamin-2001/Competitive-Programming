#include<bits/stdc++.h>
using namespace std;
#define ll long long
//-----------------------------------------------------------------------------



bool cmp(const pair<int,int> & p1,const pair<int,int> & p2)
{
    if(p1.S>p2.S)return 1;
    return 0;
}

ll mod=1e9+7;
ll big_mod(ll base, ll power)
{
    if(power==0)    return 1;
    else if(power%2==1)
    {
        ll p1 = base % mod;
        ll p2 = (big_mod(base,power-1))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0)
    {
        ll p1 = (big_mod(base,power/2))%mod;
        return (p1*p1)%mod;
    }
}
vi prime;
bool pr[N];
void sieve(ll n)
{
    memset(pr,true ,sizeof(pr));
    for(ll p=2;p*p<=n;p++)
    {
        if(pr[p]==1)
        {
            for(int i=p*p;i<=n;i+=p)
            {
                pr[i]=false;
            }
        }
    }
   for(int i=2;i<=n;i++)if(pr[i]==true)prime.pub(i);
}

bool isP(int n)
{
    if(n==2 || n==3)return true;
    else if(n<=1 || n%2==0 || n%3==0)return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}



//----------------------hashing----------------------------------------------






const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 5;
const int BASE1 = 31;
const int BASE2 = 29;
void computePrefixHashes(const string& s, vector<ll>& hash, vector<ll>& power, int base, int mod) {
    int n = s.size();
    hash.resize(n);
    power.resize(n);
    power[0] = 1;
    hash[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++) {
        power[i] = (1LL * power[i - 1] * base) % mod;
        hash[i] = (1LL * hash[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    }
}
// 

ll getSubstringHash(const vector<ll>& hash, const vector<ll>& power, int l, int r, int mod) {
    ll result = hash[r];
    if (l > 0) {
        result = (result - (1LL * hash[l - 1] * power[r - l + 1]) % mod + mod) % mod;
    }
    return result;
}






//----------------------------segment tree------------------------------------







template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<ll>arr;
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a)
    {
        arr=a;
        n=a_len;
        s=1;
        while(s < 2*n)
        {
            s = s<<1;
        }
        tree.resize(s);fill(tree.begin(),tree.end(),Node());
        build(0,n-1,1);

    }
    void build(int st,int en,int ind)
    {
        if(st==en)
        {
            tree[ind]=Node(arr[st]);
            return ;

        }
        int mid=((st+en)>>1);
        build(st,mid,(ind<<1));
        build(mid+1,en,(ind<<1)+1);
        tree[ind].op(tree[(ind<<1)],tree[(ind<<1)+1]);

    }
    void update(int st,int en,int ind,int q_i,Update &u)
    {
        if(st==en)
        {
            u.apply(tree[ind]);
            return;
        }
        int mid=(st+en)>>1;
        if(mid>=q_i)
            update(st,mid,(ind<<1),q_i,u);
        else
            update(mid+1,en,(ind<<1)+1,q_i,u);
        tree[ind].op(tree[(ind<<1)],tree[(ind<<1)+1]);

    }
    Node query(int st,int en,int ind,int l,int r)
    {
        if(st>r || en<l)
            return Node();
        if(st>=l && en<=r)
            return tree[ind];
        int mid=(st+en)>>1;
        Node lq,rq,ans;
        lq = query(st,mid,(ind<<1),l,r);
        rq = query(mid+1,en,(ind<<1)+1,l,r);
        ans.op(lq,rq);
        return ans;
    }
    void m_u(int ind, ll val)
    {

        Update new_update = Update(val);
        update(0,n-1,1,ind,new_update);
    }
    Node m_q(int l , int r)
    {
        return query(0,n-1,1,l,r);
    }
};
struct Node1
{
    ll val;
    Node1()
    {
        val=0;
    }
    Node1(ll p1)
    {
        val=p1;
    }
    void op(Node1 &l , Node1 &r)
    {
        val = l.val + r.val;
    }
};
struct Update1
{
    ll val;
    Update1(ll p1)
    {
        val=p1;
    }
    void apply(Node1 &a)
    {
        a.val=val;
    }
};





//---------------------LazyPropagation---------------------------/





template<typename Node,typename Update>
struct Lazy
{
    vector<Node>tree;
    vector<bool>lazy;
    vector<Update>updates;
    vector<ll>arr;
    int n;
    int s;
    Lazy(int a_len,vector<ll>&a)
    {
        arr=a;
        n=a_len;
        s=1;
        while(s<2*n)
        {
            s<<=1;
        }
        tree.resize(s);fill(tree.begin(),tree.end(),Node());
        lazy.resize(s);fill(lazy.begin(),lazy.end(),false);
        updates.resize(s);fill(updates.begin(),updates.end(),Update());
        build(0,n-1,1);
    }
    void build(int st,int en,int ind)
    {

        if(st==en)
        {
         tree[ind]=Node(arr[st]);
         return;
        }
        int mid = (st+en)>>1;
        build(st,mid,ind<<1);
        build(mid+1,en,(ind<<1)+1);
        tree[ind].op(tree[ind<<1],tree[(ind<<1)+1]);
    }
    void pushdown(int ind,int st,int en)
    {
        if(lazy[ind])
        {
            int mid=(st+en)>>1;
            apply(ind<<1,st,mid,updates[ind]);
            apply((ind<<1)+1,mid+1,en,updates[ind]);
            updates[ind]=Update();
            lazy[ind]=false;

        }
    }
    void apply(int ind,int st,int en,Update & u)
    {
        if(st!=en)
        {
            lazy[ind]=1;
            updates[ind].combine(u,st,en);
        }
        u.apply(tree[ind],st,en);

    }
    void update(int st,int en,int ind,int l,int r ,Update &u)
    {
        if(st>r || en<l)
            return;
        if(st>=l && en <= r)
        {
            apply(ind,st,en,u);
            return;
        }
        pushdown(ind,st,en);
        int mid=(st+en)>>1;
        update(st,mid,(ind<<1),l,r,u);
        update(mid+1,en,(ind<<1)+1,l,r,u);
        tree[ind].op(tree[(ind<<1)],tree[(ind<<1)+1]);
    }
    Node query(int st,int en,int ind,int l,int r)
    {
        if(st>r || en<l)
            return Node();
        if(st>=l && en<=r)
        {
            pushdown(ind,st,en);
            return tree[ind];
        }
        pushdown(ind ,st, en);
        int mid= (st+en)>>1;
        Node lq,rq,ans;
        lq=query(st,mid,(ind<<1),l,r);
        rq=query(mid+1,en,(ind<<1)+1,l,r);
        ans.op(lq,rq);
        return ans;

    }
    void m_u(int l,int r,ll val)
    {
        Update new_update=Update(val);
        update(0,n-1,1,l,r,new_update);
    }
    Node m_q(int l,int r)
    {
        return query(0,n-1,1,l,r);
    }
};
struct Node2
{
    ll val;
    Node2()
    {
        val=0;
    }
    Node2(ll p1)
    {
        val=p1;
    }
    void op(Node2 &l, Node2 &r)
    {
        val=l.val +r.val;
    }
};
struct Update2
{
    ll val;
    Update2()
    {
        val=-1;
    }
    Update2(ll p1)
    {
        val=p1;
    }
    void apply(Node2 &a,int st,int en)
    {
        if(val==-1)
            return;
        a.val=val *(en-st+1);/// it will change the range value to val

    }
    void combine(Update2 & new_update,int st,int en)
    {
        val=new_update.val;
    }

};






//--------------------------FenwickTree-----------------------------------------










struct FenwickTree{
    int n;
    vector< long long > bit;
    FenwickTree(vector< long long > &a): n(sizeof(a)),bit(n+1)
    {

        for(int i=0;i<n;i++)upd(i,a[i]);
    }
    void upd(int i,long long x)
    {

        for(++i;i<=n;i+=(i& -i))bit[i]+=x;
    }
    void cng(int i,long long new_value ,long long prev_value)
    {

        for(++i;i<=n;i+=(i & -i))bit[i]+=(new_value-prev_value);

    }
    long long sum(int i)
    {

        long long s=0;
        for(++i;i>0;i-=(i & -i))s+=bit[i];
        return s;
    }
    long long query(int l,int r)
    {

        return (sum(r)-sum(l-1));
    }

};
struct FenwickTree2D{
    int n,m;
    vector<vector<long long >>bit;
    FenwickTree2D(vector<vector<long long >>&a,int x,int y)
    {
        n=x;
        m=y;
//        cout<<n<<" "<<m;
        bit.resize(n+1,vector<long long>(m+1));
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
            {

                upd2d(i,j,a[i][j]);
            }
        }
    }
        void upd2d(int r,int c,long long x)
        {
          for(int i=r+1;i<=n;i+=(i & -i))
            for(int j=c+1;j<=m;j+= (j & -j))
            bit[i][j]+=x;

        }
        void cng2d(int r,int c,long long x,vector<vector<long long >>&a){
             for(int i=r+1;i<=n;i+=(i & -i))
            for(int j=c+1;j<=m;j+= (j & -j)){
            bit[i][j]+=(x-a[r][c]);
            }
            a[r][c]=x;
        }
        long long sum2d(int r,int c)
        {
            long long s=0;
            for(int i=r+1;i>0;i-=(i & -i))
                for(int j=c+1;j>0;j-=( j & -j))s+=bit[i][j];
            return s;
        }
        long long query2d(int r1,int c1,int r2,int c2)
        {

            return (sum2d(r2,c2)-sum2d(r1-1,c2)-sum2d(r2,c1-1)+sum2d(r1-1,c1-1));
        }


};

/*
    <<-------------------------note------------------------>>
    since fenwicktree works as a prefix sum , to add x to a range from [l,r]
    we just update x to l and update -x to r+1.


*/
int main()
{
//    vector<vector<long long >>a(3,vector<long long >(4));
//    for(int i=1;i<=3;i++)
//    {
//        for(int j=((i-1)*4)+1;j<=i*4;j++)
//        {
//            a[i-1][(j-1)%4]=j;
//
//            cout<<a[i-1][(j-1)%4]<<" ";
//        }
//        cout<<endl;
//    }
//    vector<long long>b(100);
//    cout<<sizeof(b);
//    cout<<sizeof(a)<<" ";
//    FenwickTree2D bit(a,3,4);
//    bit.cng2d(1,2,5,a);
//    cout<<bit.query2d(1,1,2,2);
        vector<ll> a={1,2,3,4};
        Lazy<Node2,Update2> seg=Lazy<Node2,Update2>(4,a);
        seg.m_u(1,2,3);
        cout<<seg.m_q(1,2).val;


    return 0;
}
