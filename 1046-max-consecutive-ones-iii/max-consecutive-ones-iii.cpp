class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=0,res=0;
        vector<int>arr(2,0);
        for(high=0;high<nums.size();high++){
            arr[nums[high]]++;
            while(arr[0]>k){
                arr[nums[low]]--;
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        return res;
    }
};