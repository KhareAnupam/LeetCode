class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        int i=0;
        while(i<n){
            while(q.size()>0 && q.front()<i-k+1) q.pop_front();
            while(q.size()>0 && nums[q.back()]<nums[i])
            q.pop_back();
            q.push_back(i);
            if(i>=k-1) ans.push_back(nums[q.front()]);
            i++;
        }
        return ans;
    }
};