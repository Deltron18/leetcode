class Solution {
public:
    int compress(vector<char>& chars) {
        int ind=0;
        for(int i=0;i<chars.size();i++){
            char ch=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==ch){
                count++;
                i++;
            }
            if(count==1){
                chars[ind++]=ch;
            }
            else{
                chars[ind++]=ch;
                string st=to_string(count);
                for(char dig : st){
                    chars[ind++]=dig;
                }
            }
            i--;
        }
        return ind;
    }
};