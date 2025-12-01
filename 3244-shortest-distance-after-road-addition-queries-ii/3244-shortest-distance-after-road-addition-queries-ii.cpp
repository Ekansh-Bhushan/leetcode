class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         // Distance array to keep track of the initial distances from city 0 to city i
    vector<int> distances(n, 0);
    vector<int> result;
    set<int> validCities;
    
    // Set to keep track of valid positions (cities) to be checked after queries
    
    for (int i = 0; i < n; ++i) {
        validCities.insert(i);
    }
    
    
    for (const auto& query : queries) {
        int startCity = query[0];
        int endCity = query[1];
        
        // Find the lower bound (first element not less than startCity + 1)
        auto lowerBound = validCities.lower_bound(startCity + 1);
        // Find the upper bound (first element not less than endCity)
        auto upperBound = validCities.lower_bound(endCity);
        
        // Remove the range of cities from lowerBound to upperBound (not inclusive)
        validCities.erase(lowerBound, upperBound);
        
        // The size of validCities set minus one gives the length of the shortest path
        result.push_back(validCities.size() - 1);
    }
    
    return result;
    }
};