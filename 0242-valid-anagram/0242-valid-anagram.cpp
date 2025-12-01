class Solution {
public:
    bool isAnagram(string s, string t) {
       // agar dono string ki length hi same nahi ha 
        //to equal honge hi nahi
        if(s.length()!= t.length()){
            return false;
        }
        // ek array bnaya jo freq count krega alphabets ki
        int freq[26]={0};
        for(int i = 0;i< s.length();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }
        for(int j=0;j< t.length(); j++){
            char ch= t[j];
            freq[ch-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
            
        }
        
            return true; 
    }
};