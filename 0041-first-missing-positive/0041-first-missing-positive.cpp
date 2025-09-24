class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        long long i=0;
        while(i<n){
            long long rightIdx = arr[i]-1LL;
            if(rightIdx<0 || rightIdx>=n) i++;
            else if(arr[i]<0)i++;
            else if(arr[i] == i+1)i++;
            else{
                if(arr[rightIdx]==arr[i]) i++;
                else swap(arr[i],arr[rightIdx]);
            }
        }
        long long ele=1;
        for(int i=0;i<n;i++){
            if(arr[i]!=ele) return ele;
            ele++;
        }
        return ele;
    }
};