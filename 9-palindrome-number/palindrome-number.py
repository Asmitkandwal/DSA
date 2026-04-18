class Solution(object):
    def isPalindrome(self, x):
        if x<0 :
            return False
        temp = x
        rev = 0
        while(temp != 0):
            t = temp%10
            rev = (rev*10)+t
            temp = temp/10

        if rev==x:
            return True
        return False    
        