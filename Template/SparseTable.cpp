#include<bits/stdc++.h>
using namespace std;
class SparseTable{
private:
    int n;
    int l;
    vector<vector<long long>>table;
    vector<long long>a;
public:
    SparseTable(int x,vector<long long>y){
        n=x;
        l=log2(x);
        a=y;
        table.assign(n+1,vector<long long>(l+1,100000000000000));
        for(int i=0;i<n;i++)table[i][0]=a[i];
        for(int j=1;(1LL<<j)<=n;j++)
        {
            for(int i=0;(i+(1LL<<j)-1)<n;i++)
            {
                table[i][j]=min(table[i][j-1],table[i+(1LL<<(j-1))][j-1]);
            }
        }
        //   d_bug(table);
    }
    long long query(int l,int r)
    {
        l--;r--; // for 1base to 0base
        int j=(int)log2(r-l+1);
        return (min(table[l][j],table[r-(1<<j)+1][j]));
    }


};
