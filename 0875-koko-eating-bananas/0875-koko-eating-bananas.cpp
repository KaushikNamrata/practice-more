class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 'low' = minimum possible eating speed
        // Koko kam se kam 1 banana per hour to kha hi sakti hai
        int low = 1;
        // 'high' = maximum possible eating speed
        // Agar Koko sabse badi pile ko ek hour me khatam kare,
        // to usse zyada speed ki zarurat nahi hogi
        int high = *max_element(piles.begin(), piles.end());
        // 'ans' me hum best (minimum) valid answer store karenge
        int ans = high;
        // Binary Search jab tak range valid hai
        while (low <= high) {

            // 'mid' = ek possible eating speed (bananas per hour)
            int mid = low + (high - low) / 2;

            // Total hours jo Koko ko sab piles khane me lagenge
            long long hours = 0;

            // Har pile ke liye time calculate kar rahe hain
            for (int i = 0; i < piles.size(); i++) {

                // piles[i] = current pile ke bananas
                int bananas = piles[i];

                // Ceiling division:
                // ceil(bananas / mid)
                //
                // Formula:
                // (bananas + mid - 1) / mid
                //
                // Example:
                // bananas = 7, mid = 5
                // (7 + 5 - 1) / 5 = 11 / 5 = 2 hours
                //
                // Matlab:
                // 1st hour: 5 bananas
                // 2nd hour: remaining 2 bananas
                hours += (bananas + mid - 1) / mid;
            }

            // Agar is speed par total hours <= h
            // matlab Koko time ke andar sab kha sakti hai
            if (hours <= h) {

                // Ye speed valid hai, answer update karo
                ans = mid;

                // Ab aur chhoti speed try karo
                // kyunki hume minimum k chahiye
                high = mid - 1;
            }
            else {
                // Agar total hours > h
                // matlab ye speed slow hai
                // Koko ko zyada fast khana padega
                low = mid + 1;
            }
        }

        // Sabse chhota valid k return karo
        return ans;
    
    }
};