class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;

        if(arr.size() == 1){
            return 0;
        }

        if(arr[low] > arr[low+1]) return low;
        if(arr[high] > arr[high-1]) return high;
        low++;
        high--;

        while(low  <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }else if(mid == low && mid == high){
                return mid;
            }else if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};