class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            unordered_map<char,int>mpp;
            
            for(int j = i;j<n;j++){
                mpp[s[j]]++;
                int maxval = -1;
                int minval = INT_MAX;
                
                for(auto it : mpp){
                    maxval = max(maxval , it.second);
                    minval = min(minval , it.second);
                }
                ans += maxval-minval;
            }
            
        }
        return ans;
    }
};