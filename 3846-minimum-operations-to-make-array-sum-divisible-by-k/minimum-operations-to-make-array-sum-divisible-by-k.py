class Solution(object):
    def minOperations(self, nums, k):
       sum = 0
       for i in nums:
         sum += i
       return sum%k; 