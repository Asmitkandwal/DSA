class Solution(object):
    def rotate(self, nums, k):

        n = len(nums)

        # We create list with size n because elements will be placed
        # directly at specific indexes.
        # Empty list works with append(), but here we need demo[index].
        # So indexes must already exist.
        demo = [0] * n

        for i in range(n):

            # Calculate rotated position for current element
            index = (i + k) % n

            demo[index] = nums[i]

        # nums = demo would only change local reference.
        # nums[:] = demo replaces contents of original list,
        # so changes reflect outside the function too.
        nums[:] = demo