class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1;
        while(i>=0){
            int digit = num[i]-'0';
            if(digit % 2 !=0){
                string answer = num.substr(0,i+1);
                return answer;
            }
            i=i-1;
        }
        return "";
    }
};