class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, maxw=INT_MIN;
        while(left<right){
            int w=right-left;
            int h=min(height[left],height[right]);
            int curw=w*h;
            maxw=max(maxw,curw);
            height[left]<height[right] ? left++ : right--;
        }
        return maxw;

    }
};