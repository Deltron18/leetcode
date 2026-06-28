class Solution {
public:

    int helper(int start,int end,vector<int>& nums){
       
        int prev=0;
        int curr=0;

        for(int i=start;i<=end;i++)
            {
                int next=max(prev+nums[i],curr);
                prev=curr;
                curr=next;
            }
        
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
      if(n==1)
      return nums[0];


          int case1=helper(0,n-2,nums);
        int case2=helper(1,n-1,nums);

        return max(case1,case2);
    }
        
      
    
};