class Solution {
public:
    string largestOddNumber(string num) {
        int lastodd = -1;
        for(int i = 0;i<num.size();i++){
            if((num[i]-'0')%2 != 0){
                lastodd = i;
            }
        }
        if(lastodd == -1){
            return "";
        }
        return num.substr(0,lastodd+1);

    }
};