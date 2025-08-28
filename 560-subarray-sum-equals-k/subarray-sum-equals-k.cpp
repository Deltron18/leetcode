class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        

        int total = 0;
        unordered_map<int, int> m;  // prefix sum -> count
        int presum = 0;
        m[0] = 1; // to handle subarrays starting from index 0

        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            if (m.count(presum-k)) {
                total += m[presum-k];
                m[presum]++; // add how many times this prefix appeared before
            }
           else m[presum]++;
        }

        return total;




    }
};