class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long start=0,end=0,sum=0,count=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum*(end-start+1)>=k){
                sum-=nums[start];
                start++;
            }
            
            count+=(end-start+1);
            end++;
        }
        return count;

    }
};

//   long long countSubarrays(vector<int>& nums, long long k) {
//         int n = nums.size();
//         int i=0,j=0;
//         long long sum = 0;
//         long long cnt = 0;
        

//         while(j<n){
//             sum += nums[j];

//             while((long long)sum * (j-i+1) >= k){
//                 //shrink 
//                 sum -= nums[i];
//                 i++;
//             }

//             cnt += (j-i+1);
//             j++;
//         }

//         return cnt;
//     }
// };