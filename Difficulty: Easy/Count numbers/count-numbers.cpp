class Solution {
  public:
    int count(int N) {
        int c = 0;
        
        for (int i = 1;i<=N;i++){
            bool isthree = false;
            int temp = i;
            
            while(temp!=0){
                int digit = 0;
                digit = temp%10;
                if(digit == 3){
                    isthree = true;
                    break;
                }
                temp = temp/10;
                
            }
            if(!isthree)
            c++;
        }
        
        return c;
        
    }
};