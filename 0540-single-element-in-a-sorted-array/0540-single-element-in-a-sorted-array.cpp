class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-2;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==nums[mid^1]){ // check if left half or not  ( even and odd)=> left half
                lo=mid+1;
            }
            else hi=mid-1; // right half (odd and even) => right half
        }
        return nums[lo];
    }
};

// same method. (better understanding)  ---------->>>> Left half || Right half
// while(lo<=hi){
//     int mid = lo + (hi-lo)/2;
//     if(mid%2==0){
//         if(nums[mid]==nums[mid+1]){
//             lo=mid+1;
//         }
//         else hi=mid-1;
//     }
//     else if(mid%2!=0){
//         if(nums[mid]==nums[mid-1]) lo=mid+1;
//         else hi=mid-1;
//     }
// }