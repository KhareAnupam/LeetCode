class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int x=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                x=i;
                break;
            }
        }
        if (x == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int prev = x-1;
        int l=x;
        int h=n-1;
        while(l<h){
            int temp=nums[l];
            nums[l] = nums[h];
            nums[h] = temp;
            // swap(nums[l],nums[h]);
            l++;
            h--;
        }
        int ele = nums[prev];
        for(int i=x;i<n;i++){
            if(nums[i]>ele){
                int temp = nums[i];
                nums[i]=nums[prev];
                nums[prev] = temp;
                // swap(nums[i],nums[prev]);
                break;
            }
        }
    }
};