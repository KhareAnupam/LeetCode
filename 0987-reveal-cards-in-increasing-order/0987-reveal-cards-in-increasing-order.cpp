class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        vector<int>ans(n);
        int i=0;
        while(q.size()>0){
            // ans.push_back(deck[q.front()]); q.pop();
            int idx = q.front();
            ans[idx]= deck[i++]; q.pop();
            q.push(q.front()); q.pop();
        }
        return ans;
    }
};