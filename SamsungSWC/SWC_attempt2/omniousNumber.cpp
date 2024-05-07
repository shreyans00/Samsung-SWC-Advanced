// /*
// Company  A  is discarding product numbers that contain few specific digits a specific number of time or
// more than that. You are given a range and you need to find product numbers that are possible.

// Example-

// Range: 24 to 12943

// Numbers that should not come: 1, 3, 5
// Number of times these number should not occur: 3 or more

// In above case all two digit numbers are valid.

// In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.

// In four digit: All the numbers containing above 3 digit numbers are not valid.

// Eg: 11223 is not valid, 11222 is valid.
// */


// #include <bits/stdc++.h>
// using namespace std;

// int calDelnos(int num, vector<int> delnos, int n)
// {
//     int cnt = 0;

//     // if (num / 1000 > 0)
//     // {
//         map<int, int> mp;
//         for (int i = 0; i < 10; i++)
//         {
//             mp[i] = 0;
//         }
//         while (num)
//         {
//             int rem = num % 10;
//             mp[rem]++;
//             num = num / 10;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cnt += mp[delnos[i]];
//         }
//             // cout << cnt << endl;
//     // }

//     return cnt;
// }
// int numberOminous(int a, int b, int k, vector<int> delnos, int n)
// {
//     int ans = 0;
//     for (int i = a; i <= b; i++)
//     {
//         int cntdelnos = calDelnos(i, delnos, n);
//         if (cntdelnos >= k)
//         {   
//             cout<<i<<endl;
//             ans++;
//         }
//     }
//     return ans;
// }

// int main()
// {

//     int a, b, k;
//     cin >> a >> b >> k;
//     int n;
//     cin >> n;
//     vector<int> delNos;
//     for (int i = 0; i < n; i++)
//     {
//         int p;
//         cin>>p;
//         // cout<<p<<endl;
//         delNos.push_back(p);
//     }

//     int ans = numberOminous(a, b, k, delNos, n);
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int numberOminous(int a, int b, int k, int *delNos, int n){
    int count = 0;
    for(int i = a; i <= b; i++){
        int temp = i;
        int digitArray[10] = {0};

        while(temp){
            digitArray[temp%10]++;
            temp /= 10;
        }
        
        int rougeK = 0;
        for(int i=0; i<n; i++){
            rougeK += digitArray[delNos[i]];
        }

        if(rougeK >= k){
            count++;
        }

    }
    return count;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int *delNos = new int[n];
    for(int i=0; i<n; i++){
        cin >> delNos[i];
    }

    cout << numberOminous(a, b, k, delNos, n) << "\n";

    return 0;
}