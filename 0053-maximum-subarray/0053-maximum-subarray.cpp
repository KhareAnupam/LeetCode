class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans = max(sum,ans);
            if(sum<0) sum=0;
        }
        if(ans==0){
            int newSum=INT_MIN;
            for(int i=0;i<nums.size();i++)
            newSum = max(nums[i],newSum);
            return newSum;
        }
        return ans;
    }
};