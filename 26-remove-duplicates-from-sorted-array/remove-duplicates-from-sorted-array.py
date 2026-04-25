class Solution(object):
    def removeDuplicates(self, nums):
        writer = 0 
        
        for scout in range(1, len(nums)):
            # If the scout finds a new number
            if nums[scout] != nums[writer]:
                writer += 1        # Move writer to the next empty slot
                nums[writer] = nums[scout] # Write the new number there
        
        return writer + 1