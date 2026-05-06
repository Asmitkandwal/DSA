class Solution(object):
    def singleNumber(self, nums):
        xor_val = 0
        for i in nums:
            xor_val = xor_val ^ i

        return xor_val
        