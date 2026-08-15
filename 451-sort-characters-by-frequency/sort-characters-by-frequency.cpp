//OPTIMAL APPROACH

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for(char c : s) {
            mp[c]++;
        }

        // Create buckets
        vector<vector<char>> bucket(s.size() + 1);

        // Put each character into its frequency bucket
        for(auto it : mp) {
            char c = it.first;
            int freq = it.second;

            bucket[freq].push_back(c);
        }

        string ans = "";

        // Start from highest frequency
        for(int freq = s.size(); freq >= 1; freq--) {

            for(char c : bucket[freq]) {

                for(int i = 0; i < freq; i++) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};