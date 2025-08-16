class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =matrix.size() , m=matrix[0].size();
        int start=0,end=(n*m)-1,mid;
        while(start<=end){
            mid=start+(end-start)/2;
           int  rowindex=mid/m;
           int colindex=mid%m;
           if(matrix[rowindex][colindex]==target)
           return 1;
           else if(matrix[rowindex][colindex]<target)
           start=mid+1;
           else
           end=mid-1;
        }
        return 0;
    }
};