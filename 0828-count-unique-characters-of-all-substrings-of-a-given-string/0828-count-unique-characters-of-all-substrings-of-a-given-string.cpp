class Solution {
public:
    int uniqueLetterString(string s) {
         vector<vector<int>> idx(26);
        int n = s.length();

        for (int i = 0; i < s.length(); i++) {
            idx[s[i] - 'A'].push_back(i);
        }

        int ans = 0;
        for (int c = 0; c < 26; c++) {
            if (idx[c].empty())
                continue;
            // setting boundary for each character in the idx array
            // for eg for A  we have -> [0,2] -> so we add boundaries
            // so that we can have prev and next values for both 0 , 2 indices
            idx[c].insert(idx[c].begin(), -1); //[-1 , 0 , 2]
            idx[c].push_back(n);               // [-1 , 0 , 2 , 3]
            // now if we see for 0 prev = -1 and next = 2
            // for 2 prev = 0 and next = 3

            auto& v = idx[c]; // v = [-1 , 0 , 2 , 3]
            for (int i = 1; i < v.size() - 1; i++) {
                int prev = v[i - 1]; // for 0 prev is -1
                int curr = v[i];     // 0
                int next = v[i + 1]; // for 0 next is 2

                ans += (curr - prev) *
                       (next - curr); 
            }
        }

        return ans;
    }
};