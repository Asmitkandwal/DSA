class Solution {
  public:
  
    bool ispossible(vector<int>&arr,int k,int mid){
        int sum = 0;
        int partition = 1;
        for(int i = 0;i<arr.size();i++){
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } 
            // Limit exceeded! Start a new subarray with the current number
            else {
                partition++;
                sum = arr[i];
            }
            
            if(partition > k){
                return false;
            }
        }
        
        return true;
    }
  
    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(ispossible(arr,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};