class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10); // allow up to 100 words
        string temp;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){ // end of a word
                int pos = temp.back()-'0'; // last char is number
                temp.pop_back();           // remove number
                ans[pos]=temp;
                temp.clear();
            }
            else{
                temp += s[i];
            }
        }
        
        // handle the last word (not followed by space)
        int pos = temp.back()-'0';
        temp.pop_back();
        ans[pos]=temp;
        
        // construct the result
        string result;
        for(int i=1;i<ans.size();i++){
            if(ans[i].empty()) break;
            if(!result.empty()) result += " ";
            result += ans[i];
        }
        
        return result;
    }
};
