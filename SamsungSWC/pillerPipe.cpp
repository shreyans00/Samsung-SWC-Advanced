/*
https://www.geeksforgeeks.org/samsung-r-d-noida-question-september-2018/
https://code.hackerearth.com/8ca41dM?key=54591adea7ca921ac55169b10f163508

You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner 
standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height
of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.
In case, there is no combination possible, print 0.

INPUT :
1
5
1 2 3 4 6
Output :
8
*/

#include<bits/stdc++.h>
using namespace std;
int n;
void calHeight(int ind, vector<int>arr, int p1, int p2, int& ans)
{
    if(p1==p2){
        if(ans<p1){
            ans=p1;
        }
    }
    if(ind==n){
        return;
    }

    calHeight(ind+1,arr,p1+arr[ind],p2, ans);
    calHeight(ind+1,arr,p1,p2+arr[ind], ans);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        cin>>n;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            arr.push_back(t);
        }
        int p1=0, p2=0;
        int ans=0;
        calHeight(0,arr,p1, p2,ans);
        if(ans==0) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}