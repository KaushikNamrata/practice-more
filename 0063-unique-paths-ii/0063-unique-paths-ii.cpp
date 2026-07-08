class Solution {
public:
///using recursion and memoization
    int m,n;
    int t[101][101];
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1){
        return 0;
        }
        if(i==m-1 && j==n-1){
        return 1;
        }
        if(t[i][j]!=-1){
        return t[i][j];
        }

        int right= solve(i,j+1,grid);
        int down = solve(i+1,j,grid);
        t[i][j]=right+down;
        return t[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        m=grid.size();
        n=grid[0].size();
        return solve(0,0,grid);
    }
};