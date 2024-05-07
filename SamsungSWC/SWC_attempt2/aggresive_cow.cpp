/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
1 3 5 8 10
c=3
Output: 4
1 5 10
*/

// #include<bits/stdc++.h>
// using namespace std;

// bool Comperator(int x,int a[],int n,int k){// We want to know if we can get at least x distance with k cows
//     int currentCows = 1;
//     int leftmost = 0;
    
//     for(int i=1;i<n;++i){
//         if(a[i] - a[leftmost] >= x){
//             leftmost = i;
//             ++currentCows;
//             if(currentCows == k)
//             	return 1;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     int t;	cin >> t;
//     for(int i=0;i<t;++i){
//         int n,k;cin >> n >> k;
//         int a[100000];
//         for(int j=0;j<n;++j){
//             cin >> a[j];
//         }

//         sort(a,a+n);
        
//         int l = 0;
//         int r = a[n-1] - a[0] + 1;
//         while(r - l > 0){
//             int m = (l + r + 1) /2;
            
//             if(Comperator(m,a,n,k)==true){
//                 l = m; // l is true now
//             }  
//             else 
//             	r = m-1; // R is false now
//         }

//         cout << l << '\n';
//     }
// }

#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool check(int mid, int n, int c, vector<int>& arr, vector<int> temp)
{
    int leftmost=0;
    int curr=1;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[leftmost]>=mid){
            temp.push_back(arr[i]);
            leftmost=i;
            curr++;
            if(curr==c){
                ans=temp;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int lo=0;
        int hi= arr[n-1]-arr[0]+1;
        int mid=0;
        while(hi-lo>0)
        {
            mid = (hi+lo+1)/2;
            vector<int> temp;
            if(check(mid,n,c,arr,temp)){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }
        cout<<lo<<endl;
        for(auto it: ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}