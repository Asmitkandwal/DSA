class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(), weights.end());
         int high = accumulate(weights.begin(), weights.end(), 0);
        
         int ans = INT_MAX;

         while(low<=high){

         int mid = low + (high-low)/2;
         int load = 0;
         int d=1;

            for(int w : weights){
                if(load + w <= mid){
                    load+= w;
                }else{
                    d++;
                    load = w;
                }
            }
            if(d <= days){
            ans = min(mid,ans);
            high = mid-1;
         }else{
            low = mid+1;
         }
         }
         

         return ans;
    }
};