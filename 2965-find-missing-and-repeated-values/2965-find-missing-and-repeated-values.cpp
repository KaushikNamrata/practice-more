class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        long long N= n*n;

        long long gridsum=0;
        long long gridsqsum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridsum+=grid[i][j];
                gridsqsum+=grid[i][j]*grid[i][j];
            }
        }
        long long sum=(N*(N+1))/2;
        long long sqsum=(N* (N+1)* (2*N+1))/6;
        
        int sqdiff=gridsqsum-sqsum;
        int sumdiff=gridsum-sum;

        int a=(sqdiff/sumdiff+sumdiff)/2;
        int b=(sqdiff/sumdiff-sumdiff)/2;

        return {a,b};

    }
};