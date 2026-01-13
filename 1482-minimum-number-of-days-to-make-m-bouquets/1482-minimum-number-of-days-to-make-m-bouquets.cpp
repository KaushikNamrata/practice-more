class Solution {
public:
    int canMakeMBouquets(vector<int>& bloomDay, int mid, int k){
        int bouqcount = 0;
        int consecutivecount=0;
        for(int i=0;i<bloomDay.size();i++){
          if(bloomDay[i]<=mid){
            consecutivecount++;
          }
          else{
            consecutivecount=0;
          }
          if(consecutivecount==k){
            bouqcount++;
            consecutivecount=0;
          }
        }
        return bouqcount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start_day=0;
        int end_day = *max_element(begin(bloomDay),end(bloomDay));
        int min_Days=-1;
        while(start_day<=end_day){
            int mid = start_day + (end_day-start_day)/2;
            if(canMakeMBouquets(bloomDay,mid,k)>=m){
                min_Days=mid;
                end_day=mid-1;
            }
            else{
                start_day=mid+1;
            }
        }
        return min_Days;

    }
};