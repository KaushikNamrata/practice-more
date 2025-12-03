class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long >st;
       for(int i=0;i<tokens.size();i++){
        string t=tokens[i];
        if(t=="+"|| t=="-" || t=="*" || t=="/"){
            long long b=st.top();
            st.pop();
            long long a =st.top();
            st.pop();

            long long result;
            if(t=="+"){
                result= a+b;
            }
            else if(t=="-"){
                result= a-b;
            }
            else if(t=="*"){
                result= a*b;
            }
            else {
                result= a/b;
            }
            st.push(result);
        }
        else{
            st.push(stoll(t));// It is a number → convert string to long long and push

        }

       } 
        // Final answer in the stack top
        return st.top();
    }
};