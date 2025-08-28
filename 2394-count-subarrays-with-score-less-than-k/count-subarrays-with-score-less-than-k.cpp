class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long start = 0, sum = 0, count = 0;
        for (long long end = 0; end < nums.size(); end++) {
            sum += nums[end];

            // shrink window if score >= k
            while (sum * (end - start + 1) >= k) {
                sum -= nums[start];
                start++;
            }

            // number of subarrays ending at 'end' = window length
            count += (end - start + 1);
        }
        return count;
    }
};
