class Solution:
    def fib(self, n: int) -> int:
        # Base cases
        if n == 0:
            return 0
        if n == 1:
            return 1
            
        # Variables to store the previous two Fibonacci numbers
        prev2 = 0  # F(n-2)
        prev1 = 1  # F(n-1)
        
        # Loop from 2 up to n
        for i in range(2, n + 1):
            # Calculate the current Fibonacci number
            current = prev1 + prev2
            
            # Shift the variables forward for the next iteration
            prev2 = prev1
            prev1 = current
            
        # After the loop finishes, prev1 holds F(n)
        return prev1