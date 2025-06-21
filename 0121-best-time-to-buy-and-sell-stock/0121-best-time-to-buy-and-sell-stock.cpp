class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= prices[0];
        int ans = INT_MIN;
        for(int i=1;i<prices.size();i++){
            mini = min(mini,prices[i-1]);
            int cal = prices[i] - mini;
            ans = max(ans,cal);
        }
        if(ans<=0) return 0;
        return ans;
    }
};