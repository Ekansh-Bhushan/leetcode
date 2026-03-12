class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0;
        int score = 0;
        int n = tokens.size();
        int i = 0;
        int j = n-1;

        sort(tokens.begin(), tokens.end());

        while(i <= j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                i++;
                maxScore = max(maxScore, score);
            }else if(score > 0 && i < j) {
                power += tokens[j];
                j--;
                score--;
            }else {
                break;
            }
        }
        

        return maxScore;
    }
};