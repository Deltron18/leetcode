class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
int count=0,start=0,end=0,product=1;
while(end<nums.size()){
    product*=nums[end];
    while(product>=k&&start<=end){
        product/=nums[start];
        start++;
    }
    count+=(end-start)+1;
    end++;
}
return count;
    }
};