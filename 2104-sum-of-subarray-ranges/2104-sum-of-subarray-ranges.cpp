class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        vector<int> pse(n), nse(n), pge(n), nge(n);

        // 🔹 PSE (Previous Smaller or Equal)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // 🔹 NSE (Next Smaller)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // 🔹 PGE (Previous Greater or Equal)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // 🔹 NGE (Next Greater)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // 🔥 Calculate result
        long long sumMin = 0, sumMax = 0;

        for(int i = 0; i < n; i++) {
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            sumMin += (long long)nums[i] * leftMin * rightMin;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            sumMax += (long long)nums[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};