class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;

        for(int i = num.length() - 1 ; i >= 0 ; i--) {
            int val = num[i] - '0';
            if(val % 2 == 1) {
                index = i;
                break;
            }
        }

        int i = 0;
        while(i <= index && num[i] == '0') i++;

        return num.substr(i,index+1-i);
    }
};