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
// */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define endl '\n'
int ans ;

void f(int p1, int p2, vector<int> arr, vector<int> vis)
{

    if(p1==p2)
    {
        ans= max(ans,p1);
    }
    for(int i=0;i<arr.size();i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            f(p1+arr[i],p2,arr,vis);
            f(p1,p2+arr[i],arr,vis);
            vis[i]=0;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ans = 0;
        vector<int> vis(n,0);
        f(0,0,arr,vis);
        cout<<ans<<endl;

    }
}



// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define all(v) v.begin(), v.end()
// #define endl '\n'

// int ans;
// int n;
// void f(int n, int p1, int p2, int arr[], vector<int> vis)
// {
//     if (p1 == p2)
//     {
//         ans = max(ans, p1);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             vis[i] = 1;
//             f(n, p1 + arr[i], p2, arr, vis);
//             f(n, p1, p2 + arr[i], arr, vis);
//             vis[i] = 0;
//         }
//     }
//     return;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {

//         cin >> n;
//         int arr[n + 1];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         ans = 0;
//         vector<int> vis(n, 0);
//         f(n, 0, 0, arr, vis);
//         cout << ans << endl;
//     }
// }