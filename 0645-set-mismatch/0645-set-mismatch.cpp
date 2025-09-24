class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n= arr.size();
        int missing;
        int twice;
        int i=0;
        while(i<n){
            int rightIdx = arr[i] -1;
            if(arr[i] == i+1)i++;
            else{
                // if(rightIdx<i){
                //     twice = arr[i];
                //     missing = i+1;
                //     break;
                // }
                if(arr[rightIdx] == arr[i]){
                    twice = arr[i];
                    i++;
                    // missing = i+1;
                    // break;
                }
                else swap(arr[i],arr[rightIdx]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                missing = i+1;
                break;
            }
        }
        return {twice,missing};
    }
};