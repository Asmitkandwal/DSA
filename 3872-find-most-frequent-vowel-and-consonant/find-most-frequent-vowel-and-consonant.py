class Solution(object):
    def maxFreqSum(self, s):

        freq = {}
        vowel = 0
        consonent = 0

        for ch in s:

            # Update frequency of current character
            freq[ch] = freq.get(ch, 0) + 1

            temp = freq[ch]   # current character frequency

            # Track highest frequency among vowels
            if ch in "aeiou":
                vowel = max(vowel, temp)

            # Track highest frequency among consonants
            else:
                consonent = max(consonent, temp)

        # Required answer = max vowel freq + max consonant freq
        return vowel + consonent