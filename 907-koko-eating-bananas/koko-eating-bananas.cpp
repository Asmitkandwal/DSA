class Solution {
public:

    long long cal_hours(vector<int>& piles, int mid){
        long long result = 0;
        for(int i = 0;i<piles.size();i++){
            result += ceil((double)piles[i]/(double)mid);
        }
        return result;
    } 


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long total_hours = cal_hours(piles,mid);
            if(total_hours <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};