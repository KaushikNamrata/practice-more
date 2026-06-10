class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> mp;

        int i = 0;
        int count = 0;

        for(int j = 0; j < fruits.size(); j++) {

            // include current fruit
            mp[fruits[j]]++;

            // shrink until at most 2 fruit types remain
            while(mp.size() > 2) {

                mp[fruits[i]]--;

                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);

                i++;
            }

            // valid window
            count = max(count, j - i + 1);
        }

        return count;
    }
};