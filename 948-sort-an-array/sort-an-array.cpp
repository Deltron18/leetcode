class Solution {
public:


void merge(vector<int>& arr, int start, int mid, int end){
  int i=start;
  int j=mid+1;
  int k=0;
  vector<int> temp(end-start+1);
  while(i<=mid && j<=end){
    if(arr[i]<arr[j]){
      temp[k++]=arr[i++];
    }
    else{
      temp[k++]=arr[j++];
    }
  }
  while(i<=mid){
    temp[k++]=arr[i++];
  }
  while(j<=end){
    temp[k++]=arr[j++];
  }
  k=0;
  for(int i=start;i<=end;i++){
    arr[i]=temp[k++];
  }
}

void mergesort(vector<int>& arr, int start,int end){
     if(start>=end)
         return;

  int mid=start+(end-start)/2;
  mergesort(arr,start,mid);
  mergesort(arr,mid+1,end);
  merge(arr,start,mid,end);
}
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};