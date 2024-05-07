/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/


#include <bits/stdc++.h>
using namespace std;
int ans;

void calScore(vector<int> balls, int temp)
{
    vector<int> tempballs = balls;
    if (balls.size() == 1)
    {
        ans = max(ans, temp + balls[0]);
        return;
    }
    int m = balls.size();
    for (int i = 0; i < m; i++)
    {
        // left and right both
        if (i - 1 >= 0 && i + 1 < m)
        {
            int left = balls[i - 1];
            int right = balls[i + 1];
            int balloon = balls[i];
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + left * right* balloon);
            balls = tempballs;
        }

        else if (i - 1 >= 0 && i + 1 >= m)
        {
            int left = balls[i - 1];
            int balloon = balls[i];
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + left* balloon);
            balls = tempballs;
        }

        else if (i - 1 < 0 && i + 1 < m)
        {
            int right = balls[i + 1];
            int balloon = balls[i];
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + right* balloon);
            balls = tempballs;
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> balls;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            balls.push_back(a);
        }
        ans = 0;

        calScore(balls, 0);
        cout << ans << endl;
    }
    return 0;
}
