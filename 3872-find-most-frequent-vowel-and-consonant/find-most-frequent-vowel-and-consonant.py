class Solution(object):
    def maxFreqSum(self, s):
        freq = {}
        vowel = 0
        consonent = 0

        for ch in s:
            freq[ch] = freq.get(ch,0)+1
            temp = freq[ch]
            if ch in "aeiou":
                vowel = max(vowel,temp)
            else:
                consonent = max(consonent , temp)

        return vowel+consonent                    


        