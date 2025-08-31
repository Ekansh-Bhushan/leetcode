class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        long long scorce = 0;
        int index = 0;
        vector<bool> visited(n,false);

        while(index >= 0 && index < n && !visited[index]){
            visited[index] = true;
            if(instructions[index] == "add") {
                scorce += values[index];
                index++;
            } else if(instructions[index] == "jump"){
                index += values[index];
            }
        }
        return scorce;
    }
};