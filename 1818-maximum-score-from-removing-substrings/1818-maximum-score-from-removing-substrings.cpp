class Solution {
public:
    int maximumGain(string s, int x, int y) {
          auto remove = [](string& s, char a, char b, int val) {
            stack<char> st;
            int points = 0;
            string temp = "";

            for (char ch : s) {
                if (!st.empty() && st.top() == a && ch == b) {
                    st.pop();      // remove the pair
                    points += val; // gain points
                } else {
                    st.push(ch);   // push current character
                }
            }

            // get the remaining string back from stack
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            s = temp;
            return points;
        };

        int total = 0;

        // remove more valuable one first
        if (x > y) {
            total += remove(s, 'a', 'b', x); // remove "ab"
            total += remove(s, 'b', 'a', y); // then "ba"
        } else {
            total += remove(s, 'b', 'a', y); // remove "ba"
            total += remove(s, 'a', 'b', x); // then "ab"
        }

        return total;
    }
};