class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int leftknownsum = 0;
        int rightknownsum = 0;

        int leftqnmarkcount = 0;
        int rightqnmarkcount = 0;

        for (int i = 0; i < n; i++) {

            if (num[i] == '?') {

                if (i < n / 2) {
                    leftqnmarkcount++;
                }
                else {
                    rightqnmarkcount++;
                }

            }
            else {

                if (i < n / 2) {
                    leftknownsum += num[i] - '0';
                }
                else {
                    rightknownsum += num[i] - '0';
                }
            }
        }

        int totalqnmark = leftqnmarkcount + rightqnmarkcount;

        if (totalqnmark % 2 == 1) {
            return true;
        }

        int left = 2 * leftknownsum + 9 * leftqnmarkcount;
        int right = 2 * rightknownsum + 9 * rightqnmarkcount;

        if (left == right)
            return false;

        return true;
    }
};