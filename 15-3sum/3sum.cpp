class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1,r=nums.size()-1,sum=-1*nums[i];
            while(l<r){
                if(nums[l]+nums[r]==sum){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    while( l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(nums[l]+nums[r]<sum)
                l++;
                else
                r--;
            }
        }
        return ans;
    }
};