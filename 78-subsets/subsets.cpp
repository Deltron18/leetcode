class Solution {
public:
   

   void subset(vector<int>& nums,int index,int n,vector<vector<int>>&ans,vector<int>temp){


    if(index == n){
        ans.push_back(temp);
        return;
    }



     subset(nums,index+1,n,ans ,temp);

     temp.push_back(nums[index]);
     subset(nums,index+1,n,ans ,temp);

   }



    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        subset(nums,0,nums.size(),ans,temp);
        return ans;
    }
    
};