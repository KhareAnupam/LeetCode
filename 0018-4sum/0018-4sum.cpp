class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            while(i>0 && i<n && nums[i]==nums[i-1])i++;
            int j=i+1;
            do{
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    sum+= nums[l];
                    if(sum<target){
                        k++;
                        while(k<l && nums[k]==nums[k-1]) k++;
                    }
                    else if(sum>target){
                        l--;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else{
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        l--;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
                j++;
                while(j>1 && j<n && nums[j]==nums[j-1]) j++;
            }while(j<n);
        }
        return ans;
    }
};