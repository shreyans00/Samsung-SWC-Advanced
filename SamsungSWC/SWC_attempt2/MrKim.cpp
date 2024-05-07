/*
Mr. Kim has to deliver refrigerators to N customers. 
From the office, he is going to visit all the customers and then return to his home. 
Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . 
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, 
where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. 
The locations of the office, his home, and the customers are all distinct. 
You should plan an optimal way to visit all the N customers and return to his among all the possibilities.

You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. 
Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. 
Your program only have to report the distance of a (the) shortest path.

You don’t have to solve this problem efficiently. 
You could find an answer by looking up all the possible ways. 
If you can look up all the possibilities well, you will get a perfect score.

[Constraints]

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.



[Input]

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.
Mr. Kim_TSP

5 

0 0 100 100 70 40 30 10 10 5 90 70 50 20

6 

88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14

10 

39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

Output (10 lines in total)

#1 200

#2 304

#3 366

*/

#include<iostream>
#define DEFINE <climits>
#include DEFINE
using namespace std;

int row[11],col[11];
bool visited[11];
int shortest = INT_MAX;
int N;
int ox, oy, hx, hy;

void solveit(int index, int dist, int sx, int sy)
{
    if(index == N)
    {
        dist += abs(sx-hx) + abs(sy-hy);
        if(dist < shortest)
        {
            shortest = dist;
            return;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            solveit(index+1, dist+abs(sx-row[i])+abs(sy-col[i]),row[i],col[i]);
            visited[i]=0;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>N;
        cin>>ox>>oy>>hx>>hy;
        for(int i=0;i<N;i++)
        {
            cin>>row[i]>>col[i];
            visited[i]=0;
        }

        solveit(0,0,ox,oy);
        cout<<"#"<<i<<" "<<shortest<<endl;
        shortest = INT_MAX;
    }
}