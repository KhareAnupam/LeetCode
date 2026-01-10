class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        if(n>m){
            int i=0;
            int j=0;
            while(j<m && i<n){
                if(nums1[i]==nums2[j]){
                    if(ans.size()==0) {
                        ans.push_back(nums2[j]);
                    }
                    else{
                        int ele = ans.back();
                        if(ele==nums2[j]){
                            i++;
                            j++;
                            continue;
                        }
                        ans.push_back(nums2[j]);
                    }
                    j++;
                    i++;
                }
                else if(nums1[i]<nums2[j]) i++;
                else j++;
            }
        }
        else{
            int i=0;
            int j=0;
            while(i<n && j<m){
                if(nums1[i]==nums2[j]){
                    if(ans.size()==0) {
                        ans.push_back(nums2[j]);
                        continue;
                    }
                    else{
                        int ele = ans.back();
                        if(ele==nums1[i]){
                            i++;
                            j++;
                            continue;
                        }
                        ans.push_back(nums1[i]);
                    }
                    i++;
                    j++;
                }
                else if(nums1[i]<nums2[j]) i++;
                else j++;
            }
        }
        return ans;
    }
};