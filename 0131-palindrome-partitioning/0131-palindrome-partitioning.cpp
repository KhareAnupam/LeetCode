class Solution {
public:
    bool isPalindrome(string &temp){
        int i=0;
        int j = temp.length()-1;
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void partition(int pointer,vector<string> & v, string & s,vector<vector<string>> &ans){
        if(pointer==s.size()){
            ans.push_back(v);
        }
        for(int i=pointer;i<s.length();i++){
            string temp="";
            for(int j=pointer;j<=i;j++){
                temp+=s[j];
            }
            if(isPalindrome(temp)){
                v.push_back(temp);
                partition(i+1,v,s,ans);
                v.pop_back();
            }
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        string temp="";
        partition(0,v,s,ans);
        return ans;
    }
};