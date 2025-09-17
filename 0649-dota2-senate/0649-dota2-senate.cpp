class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q;
        queue<int>r;
        queue<int>d;
        int n = senate.size();
        
        for(int i=0;i<n;i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
            q.push(i);
        }
        while(q.size()>0){
            int cur = q.front();q.pop();
            if(senate[cur]=='X'){
                continue;
            }
            else if(senate[cur]=='R'){
                if(d.size()==0) return "Radiant";
                int del = d.front();d.pop();
                senate[del] = 'X';
                r.push(r.front()); r.pop();

            }
            else{
                if(r.size()==0) return "Dire";
                int del = r.front();r.pop();
                senate[del] = 'X';
                d.push(d.front()); d.pop();
            }
            q.push(cur);
        }
        return "ANUPAM";
    }
};