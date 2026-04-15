class Solution(object):
    def containsDuplicate(self, nums):
        new_set = set(nums)
        size = len(new_set)
        if size == len(nums):
            return False
        else:
            return True
        