class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int left = (sum-k);
            if(left==0){
                count++;
                if(mp.find(left)!=mp.end()){
                    count+= mp[left];
                    // len = max(len,l);
                }
            }
            else{
                if(mp.find(left)!=mp.end()){
                    count+= mp[left];
                    // len = max(len,l);
                }
            }
            mp[sum]++;
        }
        return count;
    }
};