class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        for(int i = s.length()-1;i>=0;i--){
            if(s[i] == 'I'){
                val += 1;
            }else if(i>0 && s[i] == 'V' && s[i-1] == 'I'){
                val += 4;
                i--;
            }else if(s[i] == 'V'){
                val += 5;
            }
            else if(i>0 && s[i] == 'X' && s[i-1] == 'I'){
                val += 9;
                i--;
            }else if(s[i] == 'X'){
                val += 10;
            }else if(i>0 && s[i] == 'L' && s[i-1] == 'X'){
                val += 40;
                i--;
            }else if(s[i] == 'L'){
                val += 50;
            }else if(i>0 && s[i] == 'C' && s[i-1] == 'X'){
                val += 90;
                i--;
            }else if(s[i] == 'C'){
                val += 100;
            }else if(i>0 && s[i] == 'D' && s[i-1] == 'C'){
                val += 400;
                i--;
            }else if(s[i] == 'D'){
                val += 500;
            }else if( i>0 && s[i] == 'M' && s[i-1] == 'C'){
                val += 900;
                i--;
            }else{
                val += 1000;
            }
        }
        return val;
    }
};