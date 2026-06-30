class Solution {
public:


int find(vector<int>arr){
    int count=0;
    for(int i=0;i<arr.size();i++){
        count=max(count,arr[i]);
    }
    return count;
}

    int characterReplacement(string s, int k) {
        int low=0,high=0,res=0;
        vector <int>arr(26,0);
        for(high=0;high<s.size();high++){
            arr[s[high]-'A']++;
            int maxfre=find(arr);
            int len=high-low+1;
            int diff=len-maxfre;

            while(diff>k){
                arr[s[low]-'A']--;
                low++;
                maxfre=find(arr);
             len=high-low+1;
             diff=len-maxfre;
            }
            int mainlen=high-low+1;
            res=max(res,mainlen);
        }
        return res;
    }
};