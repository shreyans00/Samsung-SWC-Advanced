/*
There are N Balloons marked with value Bi (where B(i…N)). User will be given Gun with N Bullets and user must shot N times. When any balloon explodes then its adjacent balloons becomes next to each other. User has to score highest points to get the prize and score starts at 0. Below is the condition to calculate the score. When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-1 * Bi+1). When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1. When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1. When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi. Write a program to score maximum points.

Input 4 1 2 3 4

Output

20

Input Format

First line N Next line array of N integers

Constraints

1 < N < 10

Output Format

Single integer
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
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + left * right);
            balls = tempballs;
        }

        else if (i - 1 >= 0 && i + 1 >= m)
        {
            int left = balls[i - 1];
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + left);
            balls = tempballs;
        }

        else if (i - 1 < 0 && i + 1 < m)
        {
            int right = balls[i + 1];
            auto it = balls.begin() + i;
            balls.erase(it);
            calScore(balls, temp + right);
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
