class Solution {
  public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        
        // Merge the two halves in sorted order by picking the smaller element
        while(left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        // Append any remaining elements from the left half
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        // Append any remaining elements from the right half
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        // Copy the sorted segment from 'temp' back to the original array
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // Base case: A sub-array of size 1 or 0 is already sorted
        if (l >= r) return; 
        
        int mid = (l + r) / 2;
        
        // Recursively divide and sort the left and right halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        
        // Merge the two sorted halves back together
        merge(arr, l, mid, r);
    }
};