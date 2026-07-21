class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;   // Stack banayi

        // Expression ke har character ko traverse karo
        for (char ch : expression) {

            // Comma ka koi use nahi hai
            if (ch == ',')
                continue;

            // Agar ')' nahi hai to simply push kar do
            if (ch != ')') {
                st.push(ch);
            }

            // Agar ')' mil gaya
            else {

                // True aur False count karne ke liye
                int trueCount = 0;
                int falseCount = 0;

                // '(' tak jitni values hain unhe pop karo
                while (st.top() != '(') {

                    char curr = st.top();
                    st.pop();

                    if (curr == 't')
                        trueCount++;

                    else if (curr == 'f')
                        falseCount++;
                }

                // '(' ko bhi remove kar do
                st.pop();

                // '(' ke just pehle operator hoga (&, |, !)
                char op = st.top();
                st.pop();

                // ---------------- AND ----------------
                if (op == '&') {

                    // Agar ek bhi false hai to answer false
                    if (falseCount > 0)
                        st.push('f');

                    // Warna sab true hain
                    else
                        st.push('t');
                }

                // ---------------- OR ----------------
                else if (op == '|') {

                    // Agar ek bhi true hai to answer true
                    if (trueCount > 0)
                        st.push('t');

                    // Warna sab false hain
                    else
                        st.push('f');
                }

                // ---------------- NOT ----------------
                else { // op == '!'

                    // NOT me sirf ek operand hota hai

                    if (trueCount == 1)
                        st.push('f');   // !(t) = f

                    else
                        st.push('t');   // !(f) = t
                }
            }
        }

        // Last me stack me sirf ek hi value bachegi
        return st.top() == 't';
    }
};