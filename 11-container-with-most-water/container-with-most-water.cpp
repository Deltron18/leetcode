class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int right=n-1,left=0;
        long long best=0;
        while(left<right){
            int high=min(height[left],height[right]);
            int width=right-left;
            best = max(best,1ll*high*width);
            if(height[left]<height[right])
            left++;
            else
            right--;
        }
        return best;
    }
};