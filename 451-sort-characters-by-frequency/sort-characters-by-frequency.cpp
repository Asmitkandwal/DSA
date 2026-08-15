// BRUTE FORCE APPROACH

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mpp;
        string ans = "";
        vector<pair<char, int>> freq;

        // Count how many times each character appears
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
        }

        // Convert map into a vector so we can sort
        // characters according to their frequencies
        for (auto it : mpp) {
            freq.push_back({it.first, it.second});
        }

        // Sort characters from highest frequency to lowest
        sort(freq.begin(), freq.end(), [](auto a, auto b) {
            return a.second > b.second;
        });

        // Add each character according to its frequency
        // so characters with higher frequency come first
        for (auto it : freq) {

            for (int i = 0; i < it.second; i++) {
                ans += it.first;
            }
        }

        return ans;
    }
};