class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int s=0,e=0,len=0;
        while(e<nums.size()){
            m[nums[e]]++;
            while(m[nums[e]]>k){
                m[nums[s]]--;
                s++;
            }
            len=max(len,(e-s+1));
            e++;
        }
        return len;
    }
};