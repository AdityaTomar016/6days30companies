class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        vector<char>v = {'A','C','G','T'};
        unordered_set<string>set;
        unordered_set<string>vis;
        
        for(auto it: bank){
            set.insert(it);
        }
        set.insert(startGene);
        
        if(set.find(endGene) == set.end()) 
            return -1;
        
        queue<string>q;
        q.push(startGene);
        
        int dis=0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string s = q.front();
                q.pop();
                
                if(s == endGene){
                    return dis;
                }
                
                if(vis.find(s) != vis.end()){
                    continue;
                }
                
                vis.insert(s);
                
                for(int i=0;i<s.size();i++){
                    char temp = s[i];
                    
                    for(auto ch: v){
                        s[i] = ch;
                        
                        if(set.find(s) != set.end()){
                            q.push(s);
                        }
                    }
                    
                    s[i] = temp;
                }
            }
            dis++;
        }
        
        return -1;
    }
};
