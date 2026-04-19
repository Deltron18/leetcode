class Solution {
public:
bool isfreqsame(int freq1[26],int freq2[26]){
    for(int i=0;i<26;i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        int winsize=s1.length();
        for(int i=0;i<s2.length();i++){
           int winind=0,idx=i;
           int winfreq[26]={0};
           while(winind < winsize && idx<s2.length()){
            winfreq[s2[idx]-'a']++;
            winind++,idx++;
           }
           if(isfreqsame(freq,winfreq)){
            return true;
           }
        }
        return false;
    }
};