class Solution(object):
    def containsDuplicate(self, nums):
        new_set = set(nums)
        if len(new_set) == len(nums):
            return False
        else:
            return True
        