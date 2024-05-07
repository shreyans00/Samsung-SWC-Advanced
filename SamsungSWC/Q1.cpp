#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define endl '\n'
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int D,E,F,d,e;
        cin>>D>>E>>F>>d>>e;
        int N;
        cin>>N;
        vector<int>a,b,c,p;
        for(int i=0;i<N;i++){
            int ai,bi,ci,pi;
            cin>>ai>>bi>>ci>>pi;
            a.push_back(ai);
            b.push_back(bi);
            c.push_back(ci);
            p.push_back(pi);
        }
        if(N<=3){
            int spareProfit = D*d + E*e;
            int profit=0;
            profit= accumulate(p.begin(),p.end(),0);
            // cout<<profit<<endl;
            if(spareProfit > profit){
                cout<<spareProfit<<endl;
            }
            else{
                cout<<profit<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
}