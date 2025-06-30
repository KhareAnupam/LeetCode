class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int mxLen = 1;
        for(auto it: st){
            int ele = it-1;
            if(st.find(ele)==st.end()){
                int cur = it;
                int len=1;
                while(true){
                    int newEl = cur+1;
                    if(st.find(newEl)!=st.end()){
                        len++;
                        cur++;
                        mxLen = max(mxLen,len);
                    }
                    else{
                        mxLen = max(mxLen,len);
                        break;
                    }
                }
                
            }
        }
        return mxLen;
    }
};