class Solution:
    def armstrongNumber(self, n):

        digits = len(str(n))   # power depends on number of digits
        temp = n
        arm = 0

        while temp != 0:
            t = temp % 10
            arm += t ** digits   # core logic: digit^digits
            temp //= 10

        return arm == n   # compare with original