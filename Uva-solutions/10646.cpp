#include<bits/stdc++.h>
using namespace std;
int main()
{

    int tc;
    cin>>tc;
    int cs=0;
    while(tc--)
    {
        vector<string>v(52);
        for(auto &i:v)cin>>i;
        int i=26;
        int cnt=0;
        int y=0;
//        cout<<v[i]<<endl;
        while(cnt!=3)
        {

            int r=min(10,v[i][0]-'0');
            for(int j=i;j>i-1-10+r && j>=0;j--)
                v[j]="nai";
            i-=(1+10-r);
            y+=r;
            cnt++;
        }
        cnt=0;
        i=0;
//        cout<<y<<endl;
        while(cnt<y-1)
        {
            if(v[i]!="nai")
            {
                i++;cnt++;
            }
            else i++;

        }
        cout<< "Case "<<++cs<< ": ";
        cout<<v[i]<<endl;


    }

}
