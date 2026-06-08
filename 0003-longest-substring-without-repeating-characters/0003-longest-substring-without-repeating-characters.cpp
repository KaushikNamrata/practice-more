class Solution {
public:
    int lengthOfLongestSubstring(string s) {

       unordered_map<char,int>freq;

       int left = 0;
       int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            // 1. include s[right]
            freq[s[right]]++;
            // 2. while window invalid
            while( freq[s[right]]>1 ) {

                // remove s[left]
                freq[s[left]]--;
                left++;

                // left++
            }

            // 3. update answer
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};