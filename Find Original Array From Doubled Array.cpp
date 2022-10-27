 class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
		// size of the array
        vector<int> ans;
		// answer storing array
        vector<int> vacans;
		// when we need to return vacant array
         unordered_map<int, int> um;
		 // for storing the frequencies of each input
        if (n % 2 !=0) return ans;
		// when we will have odd number of integer in our input(double array can't be in odd number)
        sort(changed.begin(), changed.end());
		// sorting in increasing order
        for(auto x: changed){
            um[x]++;
			// storing the frequencies
        }
        for (auto y: changed) {
          if (um[y] == 0) continue;
		  // if we have already decreased it's value when we were checking y/2 value, like 2,4 we will remove 4 also when we will check 2 but our iteration will come again on 4.
          if (um[y * 2] == 0) return vacans;
		  // if we have y but not y*2 return vacant array
          ans.push_back(y);
		  // if we have both y and y*2, store in our ans array
          um[y]--;
		  // decrease the frequency of y and y*2
          um[y * 2]--;
        }
        return ans;
    }
};
