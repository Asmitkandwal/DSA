//OPTIMAL SOLUTION

class Solution {
public:
    string frequencySort(string s) {
        // STEP 1: Count frequency of each character
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        // STEP 2: Create buckets where INDEX = FREQUENCY
        // Max possible frequency of any character is s.size()
        // So bucket array size is (s.size() + 1)
        vector<vector<char>> bucket(s.size() + 1);

        // Put each character into the bucket matching its frequency
        // Example: If 'e' appears 2 times, put 'e' into bucket[2]
        for (auto it : mp) {
            char c = it.first;
            int freq = it.second;
            bucket[freq].push_back(c);
        }

        string ans = "";

        // STEP 3: Iterate backwards from highest frequency (s.size()) down to 1
        for (int freq = s.size(); freq >= 1; freq--) {
            // For every character that has this frequency:
            for (char c : bucket[freq]) {
                // Append the character 'freq' times to the result string
                for (int i = 0; i < freq; i++) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};