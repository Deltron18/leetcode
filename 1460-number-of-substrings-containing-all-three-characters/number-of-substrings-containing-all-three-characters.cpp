class Solution {
public:
    int numberOfSubstrings(string s) {
        int low=0,high=0,count=0;
        map<char,int>mp;
        for(high=0;high<s.size();high++){
            mp[s[high]]++;
            while(mp.size()==3){
                count+=s.size()-high;
                mp[s[low]]--;
                if(mp[s[low]]==0){
                    mp.erase(s[low]);  
                }
                low++;
            }
        }
        return count;
    }
};