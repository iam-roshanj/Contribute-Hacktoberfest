#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
            vector<int> ans(nums.size()*2);
        int k = nums.size()*2 - 1;
        for(int i=0, j = nums.size() - 1;i<nums.size();i++,j--){
            ans[i] = nums[i];
            ans[k--] = nums[j];
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 3 ,4};
    vector<int> b = s.getConcatenation(a);
    for(auto i:b) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
