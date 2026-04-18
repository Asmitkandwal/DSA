// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
       int temp = n;
       int sum = 0;
       while(temp != 0){
           int t = temp %10;
           sum += pow(t,3);
           temp = temp/10;
       }
       
       if(sum == n) return true;
       return false;
        
    }
};