// PROBLEM: Beauty Sum of all substrings
// Beauty = (max frequency in substring) - (min frequency in substring, excluding zero counts)

class Solution {
public:
    int beautySum(string s) {

        int ans = 0;
        int n = s.length();

        // Fix starting index i
        for (int i = 0; i < n; i++) {

            // Frequency map for substring s[i...j]
            unordered_map<char, int> mpp;

            

            // Extend substring to the right
            for (int j = i; j < n; j++) {

                // Include current character in the window
                mpp[s[j]]++;

                
                int maxval = -1;
                int minval = INT_MAX;


                // Recompute max and min frequency among PRESENT characters
                // (map only stores chars that have appeared → no zero counts)
                for (auto it : mpp) {
                    maxval = max(maxval, it.second);
                    minval = min(minval, it.second);
                }

                // Add beauty of current substring
                ans += (maxval - minval);
            }
        }

        return ans;
    }
};