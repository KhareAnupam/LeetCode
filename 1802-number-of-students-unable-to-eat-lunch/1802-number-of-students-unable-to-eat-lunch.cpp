class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int m = students.size();
        int n = students.size();
        // int i=0;
        int j=0;
        queue<int>q;
        for(int i=0;i<m;i++){
            q.push(students[i]);
        }
        int idx=0;
        int count = 0;
        while(true){
            int choice = q.front();q.pop();
            int sw = sandwiches[idx];
            if(sw==choice){
                idx++;
                if(idx>=n) return 0;
                count =0;
            }
            else{
                q.push(choice);
                count++;
            }
            if(count>m) break;
        }
        return q.size();

    }
};