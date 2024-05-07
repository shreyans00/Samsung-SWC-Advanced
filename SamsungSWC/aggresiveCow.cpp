/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls,
such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?
Input

t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
bool isValid(int mid, vector<int> arr, int n, int c, vector<int>& temp)
{
    // int mx = arr[n-1];
    // temp.push_back(arr[0]);
    c--;
    int i = 0;
    vector<int>::iterator upper;
    while (i < n)
    {
        temp.push_back(arr[i]);
        upper = upper_bound(arr.begin(), arr.end(), arr[i] + mid);
        if (upper != arr.end())
        {
            c--;
            i = (upper - arr.begin());
        }
        else break;
    }
    if(c==0) ans=temp;
    if (c > 0)
        return false;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        if (c > n)
        {
            cout << -1 << endl;
            continue;
        }

        int lo = 0;
        int hi = arr[n - 1] - arr[0];
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            vector<int> temp;
            if (isValid(mid, arr, n, c,temp))
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        cout << lo << endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}