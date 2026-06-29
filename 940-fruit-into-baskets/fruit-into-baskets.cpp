class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0,high=0,res=0;
        map<int,int>mp;
        for(high=0;high<fruits.size();high++){
            mp[fruits[high]]++;
            while(mp.size()>2){
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0)
                mp.erase(fruits[low]);
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        return res;
    }
};