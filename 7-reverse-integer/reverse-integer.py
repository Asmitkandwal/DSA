class Solution(object):
    def reverse(self, x):
        INT_MAX = 2**31-1
        INT_MIN = -2**31

        sign = 0
        if x < 0:
            sign = -1
        else:
            sign = 1

        answer = 0
        x = abs(x)


        while(x != 0):
            temp = x%10
            answer  = (answer*10)+temp
            x = x//10
        


        if answer>INT_MAX or answer<INT_MIN:
            return 0
        else:
            answer = answer*sign
            return answer    
        