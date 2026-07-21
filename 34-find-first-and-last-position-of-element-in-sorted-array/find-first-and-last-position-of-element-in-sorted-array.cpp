class Solution {
public:

    int firstoccurence(vector<int> &nums , int target){
        int low = 0, high = nums.size()-1;
        int First = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                First = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }  
        }
        return First;
    }

    int lastoccurence(vector<int> &nums, int target){
         int low = 0, high = nums.size()-1;
        int Last = -1;
        while(low <= high){
            int mid = (high+low)/2;
            if(nums[mid] == target){
                Last = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }  
        }
        return Last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstoccurence(nums,target);
        if(first == -1) return {-1,-1};
        int last = lastoccurence(nums,target);

        return{first,last};

    }
};