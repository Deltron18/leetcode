class Solution {
public:
    int reverse(int x) {
        int revnum=0;
        int dig=0;
        while(x!=0){
            dig=x%10;
            x=x/10;
            if(revnum>INT_MAX/10 || revnum<INT_MIN/10){
                return 0;
            }
            else
            {revnum=(revnum*10)+dig;}
        }
        return revnum;
    }
};