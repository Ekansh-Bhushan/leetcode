class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](const vector<int>& v1,const vector<int>& v2){
            return v1[1] > v2[1];
        });

        int maxUnits = 0;

        for(auto box : boxTypes) {
            int size = box[0];
            int val = box[1];
            if(truckSize >= size) {
                maxUnits += size*val;
                truckSize -= size;
            } else if(truckSize < size) {
                int unitput = truckSize;
                maxUnits += unitput*val;
                truckSize -= unitput;
            } else if(truckSize == 0){
                break;
            }
        }

        return maxUnits;
    }
};