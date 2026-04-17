#User function Template for python3

class Solution:
    def count (self, N):
        c = 0
        
        for i in range(1,N+1):
            temp = i
            isthree = False
            while temp!=0 :
                digit = 0
                digit = temp%10
                if digit == 3:
                    isthree = True
                    break
                temp = temp//10
            
            if isthree==False :
                c += 1
                
        
        return c        