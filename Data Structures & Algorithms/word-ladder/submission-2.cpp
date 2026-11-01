class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int bwl = beginWord.length();
        int ewl = endWord.length();

        if(ewl == 0 || find(wordList.begin(), wordList.end(), endWord) == wordList.end()|| bwl != ewl) return 0;

        int res = 1;

        unordered_map<string, vector<string>>wordCombMap;

        //O(n*m*m) - m for for loop, m for substr
        for(int i = 0; i < n; ++i){
            string curr = wordList[i];

            for(int j = 0; j < curr.length(); ++j){
                string comb = curr.substr(0,j) + '*' + curr.substr(j+1);

                wordCombMap[comb].push_back(curr); 
            }

        }

        unordered_set<string>visited; 
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return res;
                }
                for(int j = 0; j < word.length(); ++j){
                    string comb = word.substr(0,j)+"*"+word.substr(j+1);
                    for(const string& neighbor : wordCombMap[comb]){
                        if(!visited.count(neighbor)){
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            ++res;
        }

        return 0;
        //time and space complexity - time : O(n)- O(n*m*m)- no of 
        //SC: 
    }
};
