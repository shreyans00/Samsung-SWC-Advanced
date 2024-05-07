/*
https://www.geeksforgeeks.org/samsung-competency-test-25-aug-19/
*/
/*
	----IIT(ISM) Dhanbad----
	Author: Siddhant Choudhary
	
	--samsumg coding test--
	
	Q.There is a large plot with various sinkholes present. 
	Since one sinkhole can combine with another sinkhole, it is required to get
	at most one sinkhole while occupying the plot. You have to find the maximum 
	square-area formed with at most one sinkhole present.
	If there are two plots with the same area then print the one with 
	lesser sinkhole present otherwise if the sinkholes are also same then print
	anyone. For each case, you have to print the bottom leftmost coordinate and 
	top rightmost point. Please keep in mind that the plot starts with (1, 1).

	Time limit= 1sec and Memory limit– 256Mb

	Input: First line will give the number of test cases. For each test case, we
	will be given the size of the plot matrix N x M (where 1<=N, M<=1000). Next
	line will give the number of sinkholes present in the matrix K (1<=K<=N+M). 
	Next, K-lines will give the coordinates of the sinkholes.

	Output: For each test case, you have to print the number of the test case
	and the coordinates of the resultant square.
	i.e. #i xb yb xt yt (ith test case, xb=bottomost left x-coordinate, 
	yb=bottomost  left y-coordinate, xt= topmost right x-coordinate,
	yt= topmost right y-coordinate)
	
  *	time complexity of my approach = O(n*m*log(min(m,n))) *
  t
  n m
  k
  k lines...
*/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    for(int tcase = 1;tcase<=t;tcase++){
        int n,m;
        cin>>n>>m;
        vector<vector<bool>> grid(n,vector<bool>(m,0));

        int k;
        for(int i=0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            grid[a][b]=1;
        }

    }
}