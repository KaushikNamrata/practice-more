class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        if(intervals.size()==0){
            return result;
        }
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);


        for(int i=1;i<intervals.size();i++){
            int currstart=intervals[i][0];
            int currend=intervals[i][1];

            int laststart=result.back()[0];
            int lastend= result.back()[1];

            if(currstart<=lastend){
                result.back()[1]=max(lastend,currend);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};