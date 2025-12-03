class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int n = temperatures.size();
        vector<int> result(n, 0); // by default all zeros
        stack<int> st; // helps to track indexes of pending days

        for (int i = 0; i < n; i++) {
            // When a warmer day is found, resolve previous pending days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = i - idx;
            }
            // Push current day's index to wait for future warmer day
            st.push(i);
        }

        return result;
    }
};