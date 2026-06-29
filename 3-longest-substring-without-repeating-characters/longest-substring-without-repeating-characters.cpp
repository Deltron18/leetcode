class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0,high=0,res=INT_MIN;
        map<char,int>mp;
        for(high=0;high<s.size();high++){
        mp[s[high]]++;
        int k=high-low+1;
        while(mp.size()<k){
            mp[s[low]]--;
            if(mp[s[low]]==0)
            mp.erase(s[low]);
            low++;
            k=high-low+1;
        }
        int len=high-low+1;
        res=max(len,res);

        }
        return (res==INT_MIN) ? 0 : res;
    }
};