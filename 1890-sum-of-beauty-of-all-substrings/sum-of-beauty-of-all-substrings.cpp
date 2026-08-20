class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            int freq[26] = {0};
            
            for(int j = i;j<n;j++){
                freq[s[j] - 'a']++;
                int maxval = -1;
                int minval = INT_MAX;


                for(auto it : freq){
                    if(it>0){
                    maxval = max(maxval , it);
                    minval = min(minval , it);
                    }
                }
                ans += maxval-minval;
            }
            
        }
        return ans;
    }
};