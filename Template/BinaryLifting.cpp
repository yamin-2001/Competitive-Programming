#include<bits/stdc++.h>
using namespace std;
class BinaryLifting{
private:
    vector<vector<int>>G;
    int n;
    int lg;
    vector<vector<int>>ancestor;
public:
    BinaryLifting(vector<vector<int>>Graph)
    {
        G=Graph;
        n=G.size();
        lg=log2(n)+1;
        ancestor.resize(n+1,vector<int>(lg+1,-1));
        dfs(1);//root can be changed
    }
    void dfs(int node){
        for(auto u:G[node])
        {
            if(u==ancestor[node][0])continue;
            ancestor[u][0]=node;
            for(int j=1;j<lg;j++)
            {
                if(ancestor[u][j-1]==-1)break;
                ancestor[u][j]=ancestor[ancestor[u][j-1]][j-1];
            }
            dfs(u);
        }
    }
    long long get(int k,int node)
    {

        for(int j=0;j<lg;j++)
        {
            if(k& (1LL<<j)){

                node=ancestor[node][j];
            }
        }
        return node;
    }

};
