class Solution {
public:
void findlps(vector<int>&lps,string s){
    int pre=0,suf=1;
    while(suf<s.size()){
        if(s[pre]==s[suf]){
            lps[suf]=pre+1;
            pre++,suf++;
        }
        else{
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre=lps[pre-1];
            }
        }
    }
}
    int kmpmatch(string haystack, string needle) {
        vector<int>lps(needle.size(),0);
        findlps(lps,needle);
        int f=0,s=0;
        while(f<haystack.size() && s<needle.size()){
           if( haystack[f]==needle[s]){
            s++,f++;
           }
           else{
            if(s==0){
                f++;
            }
            else{
                s=lps[s-1];
            }
           }
        }
        if(s==needle.size()){
            return 1;
        }
        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        if(a==b)
        return 1;
        int repeat=1;
        string temp=a;
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
        }
        if(kmpmatch(temp,b)==1)
        return repeat;
        if(kmpmatch(temp+=a,b)==1)
        return repeat+1;
        return -1;
    }
};