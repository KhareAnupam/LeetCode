class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l=0;
        int r=0;
        int maxLen=0;
        unordered_map<int,int> mp;
        while(r<n){
            char c = s[r];
            if(mp.find(c)==mp.end()){
                int len = r-l+1;
                maxLen = max(maxLen,len);
            }
            else{
                int ll = mp[c];
                if(ll<l){
                    int len = r-l+1;
                    maxLen = max(maxLen,len);
                }
                else{
                    l=ll+1;
                    // mp[c]=r;
                }

            }
            mp[c]=r;
            r++;
        }
        return maxLen;
    }
};