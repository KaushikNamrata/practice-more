class Solution {
public:
    int maxDepth(string s) {
        int curr = 0;
        int maxdepth = 0;
        for(int i = 0 ; i < s.length();i++){
            char ch = s[i];
            if(ch == '('){
                curr++;
                maxdepth =  max(maxdepth, curr);
            }
            else if(ch==')'){
                curr--;
            }
        }
        return maxdepth;
    }
};