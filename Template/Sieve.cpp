#include<bits/stdc++.h>
using namespace std;
class Sieve{
public:
    vector<int>primes;
    vector<int>s_div;
    Sieve()
    {
        s_div.resize(10000001);
        for(int i=1;i<=10000000;i++)s_div[i]=i;
        for(int i=2;i*i<=10000000;i++)
        {
            if(s_div[i]==i)primes.push_back(i);
            for(int j=i*i;j<=10000000;j+=i)
            {
                s_div[j]=min(s_div[j],i);
            }
        }

    }
};
int main()
{
    Sieve sieve=Sieve();


}
