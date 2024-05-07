// // /*
// // https://www.careercup.com/question?id=5680648437104640

// // You are given an old touch smartphone numbers having dial pad and calculator app.
// // Aim: The goal is to type a number on dialpad.

// // But as phone is old, some of the numbers and some operations can't be touched.
// // For eg. 2,3,5,9 keys are not responding , i.e you cannot use them
// // But you can always make a number using other numbers and operations in Calculator. There could be multiple ways of making a number

// // Calculator have 1-9 and +,-,*,/,= as operations. Once you have made the number in Calculator you can copy the number and use it.

// // You have to find minimum number to touches required to obtain a number.

// // #Input:#
// // There will be multiple Test cases .Each test case will consist of 4 lines
// // 1) First line will consist of N,M,O
// //     N: no of keys working in Dialpad (out of 0,1,2,3,4,5,6,7,8,9)
// //     M:types of operations supported (+,-,*,/)
// //     O: Max no of touches allowed
// // 2) second line of input contains the digits that are working e.g 0,2,3,4,6.
// // 3) Third line contains the valued describing operations, 1(+),2(-),3(*),4(/)
// // 4) fourth line contains the number that we want to make .

// // #Output:#
// // Output contains 1 line printing the number of touches required to make the number


// // #Sample Test Case:#
// // 5
// // 5 3 5
// // 1 2 4 6 0
// // 1 2 3
// // 5
// // 6 4 5
// // 1 2 4 6 9 8
// // 1 2 3 4
// // 91
// // 6 2 4
// // 0 1 3 5 7 9
// // 1 2 4
// // 28
// // 5 2 10
// // 1 2 6 7 8
// // 2 3
// // 981
// // 6 3 5
// // 1 4 6 7 8 9
// // 1 2 3
// // 18

// // #Output:#
// // 4
// // 2
// // -1
// // 7
// // 2

// // If you have to type 18-> 2 operations. (Each touch is considered an operation),br> If you have to type 5 -> '1+4=' that requires 4 operations. There could be other ways to make '5'.
// // */
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define mod 1000000007
// #define all(v) v.begin(), v.end()
// #define endl '\n'
// int ans;

// bool isHave(vector<int>num_digits, int n)
// {
//     for(int i=0;i<num_digits.size();i++)
//     {
//         if(num_digits[i]==n)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void func(int n, int m, int o, vector<int> digits, vector<int> operators, int num, int curr, int touch, vector<int>num_digits)
// {
//     if (curr == num)
//     {
//         ans = min(ans, touch);
//         return;
//     }

//     if (touch > o)
//     {
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {

//         if (curr == 0)
//         {
//             func(n, m, o, digits, operators, num, digits[i], touch + 1,num_digits);
//         }
//         else
//         {
            
//             if (operators[0])
//             {
//                 func(n, m, o, digits, operators, num, curr + digits[i], touch + 3,num_digits);
//             }
//             if (operators[1])
//             {
//                 func(n, m, o, digits, operators, num, curr - digits[i], touch + 3,num_digits);
//             }
//             if (operators[2])
//             {
//                 func(n, m, o, digits, operators, num, curr * digits[i], touch + 3,num_digits);
//             }
//             if (operators[3])
//             {
//                 if(digits[i]!=0)
//                 {
//                     func(n, m, o, digits, operators, num, curr / digits[i], touch + 3,num_digits);
//                 }
//             }

//             if(isHave(num_digits,digits[i])){
//                 func(n, m, o, digits, operators, num, curr*10 + digits[i], touch + 1,num_digits);
//             }
//         }
//     }
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
//         int n, m, o;
//         cin >> n >> m >> o;

//         vector<int> digits(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> digits[i];
//         }
//         sort(digits.begin(),digits.end());
//         vector<int> operators(4, 0);
//         for (int i = 0; i < m; i++)
//         {
//             int a;
//             cin >> a;
//             operators[a] = 1;
//         }
//         int num;
//         cin >> num;
//         int tempNum = num;
//         vector<int> num_digits;
//         while(num>0)
//         {
//             int temp = num%10;
//             num_digits.push_back(temp);
//             num = num/10;
//         }
//         ans = INT_MAX;

//         func(n, m, o, digits, operators, tempNum, 0, 0, num_digits);
//         cout<<ans<<endl;
//     }
// }


