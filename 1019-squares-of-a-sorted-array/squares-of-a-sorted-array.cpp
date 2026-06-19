class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>neg , pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        if (neg.size()==0){
             for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        return pos;
        }
        if(pos.size()==0){
            reverse(neg.begin(),neg.end());
        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }
        return neg;
        }

        reverse(neg.begin(),neg.end());
        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }
        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        int i=0,j=0;
        vector<int>ans;
        while(i<neg.size() && j<pos.size()){
            if(neg[i]<pos[j]){
                ans.push_back(neg[i]);
                i++;
            }else{
                ans.push_back(pos[j]);
                j++;
            }
        }
        while(i<neg.size()){
            ans.push_back(neg[i]);
            i++;
        }
         while(j<pos.size()){
            ans.push_back(pos[j]);
            j++;
        }
return ans;
        
     }
};