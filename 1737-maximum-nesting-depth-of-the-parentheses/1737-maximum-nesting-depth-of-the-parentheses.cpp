class Solution {
public:
    int maxDepth(string s) {

        int maxLevel = 0;
        int level = 0;

        for(char ch : s) {
            if(ch == '(') {
                level++;
            } else if(ch == ')') {
                level--;
            }

            maxLevel = max(maxLevel,level);
        }
        return maxLevel;
        
    }
};