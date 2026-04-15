class Solution {
public:
    int trap(vector<int>& height) {
    stack<int>st;
    int n = height.size();
    int water=0;
    for(int i = 0;i<n;i++){
        while(!st.empty() && height[i]>height[st.top()]){
            int bottom = st.top();
            st.pop();
            if(st.empty()) break;
            int left = st.top();
            int distance = i - left -1;
            int boundedheight= min(height[i],height[left])-height[bottom];
            water+=distance*boundedheight;
        }
        st.push(i);
    }
    return water;
    }
};