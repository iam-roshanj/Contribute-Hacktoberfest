class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int>::iterator cit;
        vector<vector<int>> res;
        map<int, vector<int>> q;
        map<int, int> c;
        int curth = 0;
        c[0] = 1;   
        
        
        for(auto building: buildings){
            q[building[0]].push_back(building[2]);
            q[building[1]].push_back(-building[2]);
        }
        
        for(auto i: q){
            for(auto o: i.second){
                 if(o > 0){
                     c[o]++;
                 }else{
                     o = -o;
                     if(--c[o] == 0){
                         cit = c.find(o);
                         c.erase(cit);
                     }
                 }
            }
            if((*c.rbegin()).first != curth){
                curth =(*c.rbegin()).first;
                res.push_back({i.first, curth});
            }    
        }
        return res;
    }
};
