class Solution(object):
    def reverse(self, x):
        INT_MAX = 2**31 - 1   # max 32-bit int

        sign = -1 if x < 0 else 1   # store sign
        x = abs(x)                  # work with positive

        rev = 0

        while x:
            rev = rev * 10 + x % 10   # shift + add last digit
            x //= 10                  # remove last digit

        rev *= sign   # restore sign

        # check 32-bit range
        if rev < -2**31 or rev > INT_MAX:
            return 0

        return rev