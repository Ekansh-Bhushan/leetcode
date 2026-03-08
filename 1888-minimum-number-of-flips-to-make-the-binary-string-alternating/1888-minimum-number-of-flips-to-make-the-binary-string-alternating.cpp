class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;
        while( j < 2*n) {
            if(s[j%n] != ((j%2==1) ? '0' : '1')) {
                flip1++;
            }

            if(s[j%n] != ((j%2==1) ? '1' : '0')) {
                flip2++;
            }

            if(j-i+1 > n) {
                //shrink the window

                if(s[i%n] != ((i%2==1) ? '0' : '1')) {
                    flip1--;
                }

                if(s[i%n] != ((i%2==1) ? '1' : '0')) {
                    flip2--;
                }
                i++;
            }

            if(j-i+1 == n) {
                result = min({result , flip1, flip2});
            }
            j++;
        }

        return result;
    }
};