class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char, int> mpp;
        int vowel = 0;
        int consonent = 0;

        for (int i = 0; i < s.length(); i++) {

            // Update frequency of current character
            mpp[s[i]]++;

            int temp = mpp[s[i]];   // current character frequency

            // Track highest frequency among vowels
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {

                vowel = max(temp, vowel);
            }

            // Track highest frequency among consonants
            else {
                consonent = max(temp, consonent);
            }
        }

        // Required answer = max vowel freq + max consonant freq
        return vowel + consonent;
    }
};