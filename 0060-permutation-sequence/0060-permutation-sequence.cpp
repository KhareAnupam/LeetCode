class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        string ans="";
        vector<int> num;
        for(int i=1;i<=n;i++){
            fact*=i;
            num.push_back(i);
        }
        k--;
        fact/=n;
        while(true){
            int ind = k/fact;
            ans+=num[ind] + '0';
            num.erase(num.begin() + ind);
            if(num.size()==0) break;
            k%=fact;
            fact/=num.size();
            
        }
        // n--;
        // while(true){
        //     int ind = k/fact;
        //     ans+=num[ind] + '0';
        //     num.erase(num.begin() + ind);
        //     if(num.size()==0) break;
        //     k%=fact;
        //     fact/=num.size();
        //     n--;
        // }
        return ans;
    }
};