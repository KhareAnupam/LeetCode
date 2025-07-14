class Solution {
    public:
    void fullcombination(int ind,vector<int>& arr,int target,vector<vector<int>> &ans,vector<int> &ds){
        if(ind>= arr.size() || target==0){
            if(target==0){
                ans.push_back(ds);
                return;
            }
            else return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) continue;
            ds.push_back(arr[i]);
            fullcombination(i+1,arr,target-arr[i],ans,ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        fullcombination(0,arr, target,ans,ds);
        return ans;
    }
};