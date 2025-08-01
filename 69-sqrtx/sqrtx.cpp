class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
        return x;
        int start=0, end=x , mid , ans;
        while(start<=end){
            mid= start+(end-start)/2;
            if(mid==x/mid){
                ans=mid;
                break;
            }
            else if(mid<x/mid){
                start=mid+1;
                ans=mid;
            }
            else
            end=mid-1;
        }
        return ans;
    }
};