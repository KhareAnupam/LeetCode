class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        int x=n/3;
        vector<int> ans;
        for(int i=0;i<n;i++){

            mp[nums[i]]++;
            if(mp[nums[i]]==x+1) ans.push_back(nums[i]);
        }
        return ans;

        // int n= nums.size();
        // sort(nums.begin(),nums.end());
        // int x=n/3;
        // int cnt=0;
        // int ele=nums[0];
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==ele) cnt++;
        //     else{
        //         ele=nums[i];
        //         cnt=1;
        //     }
        //     if(cnt>x){
        //         if(ans.size()==0)ans.push_back(ele);
        //         else if(ans.back()!=ele) ans.push_back(ele);
        //     }
        // }
        // return ans;
    }
};