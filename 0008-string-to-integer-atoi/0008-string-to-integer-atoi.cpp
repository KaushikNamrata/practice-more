class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;  // store the number temporarily

        // Step 1: skip spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: read digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: overflow check
            if (result > (INT_MAX - digit) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            i++;
        }

        // Step 5: apply sign and return
        return (int)(sign * result);
    }
};