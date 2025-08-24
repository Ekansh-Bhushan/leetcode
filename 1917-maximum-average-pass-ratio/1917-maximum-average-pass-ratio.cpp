class Solution {
    typedef pair<double,int> P;
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> passRatio(n);

        priority_queue<P> pq;

        for(int i =0 ; i < n ;i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double ratio = (double)pass / total;
            passRatio[i] = ratio;


            int passUpdated = classes[i][0]+1;
            int totalUpdated = classes[i][1]+1;
            double updateRatio = (double)passUpdated / totalUpdated;

            double delta = updateRatio - ratio;
            pq.push({delta,i});
        }

        while(extraStudents--) {
            double delta = pq.top().first;
            int index = pq.top().second;

            pq.pop();

            classes[index][0]++;
            classes[index][1]++;

            passRatio[index] = (double)classes[index][0] / classes[index][1];

            int pass = classes[index][0];
            int total = classes[index][1];
            double ratio = (double)pass / total;


            int passUpdated = classes[index][0]+1;
            int totalUpdated = classes[index][1]+1;
            double updateRatio = (double)passUpdated / totalUpdated;

            double updateddelta = updateRatio - ratio;
            pq.push({updateddelta,index});
        }


        double sum = 0.0;

        for(int i = 0 ; i < n ;i++) {
            sum += passRatio[i];
        }

        return sum/n;
    }
};