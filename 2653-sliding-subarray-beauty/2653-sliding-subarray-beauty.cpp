class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> freq(51,0);
    vector<int> ans;

    int i=0;

    for(int j=0;j<nums.size();j++)
    {
        if(nums[j] < 0)
            freq[-nums[j]]++;

        if(j-i+1 == k)
        {
            int cnt=0;
            int beauty=0;

            for(int v=50; v>=1; v--)
            {
                cnt += freq[v];

                if(cnt >= x)
                {
                    beauty = -v;
                    break;
                }
            }

            ans.push_back(beauty);

            if(nums[i] < 0)
                freq[-nums[i]]--;

            i++;
        }
    }

    return ans;
    }
};