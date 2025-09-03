class Solution {
public:

void permute(vector<int>& nums,vector<vector<int>>&ans,int index){

if(index==nums.size()){
    ans.push_back(nums);
    return;
}

  vector<bool>check(21,0);
  for(int i=index;i<nums.size();i++){
    if(check[nums[i]+10]==0){
        swap(nums[index],nums[i]);  //little doubt
        permute(nums,ans,index+1);
        swap(nums[index],nums[i]);
        check[nums[i]+10]=1;

    }
  }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permute(nums,ans,0);
        return ans;
    }
};