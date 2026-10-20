class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //note to self : O(26) is O(1) space complexity

        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n2 < n1) return false;

        vector<int>fs1(26,0);
        vector<int>fs2(26,0);

        for(int i = 0; i< n1; ++i){
            fs1[s1[i] - 'a']++;
            fs2[s2[i] - 'a']++;
        }
         if(fs1 == fs2) return true;

        int l = 0;
        
        for(int r = n1; r < n2 ; ++r){
            fs2[s2[r] - 'a']++;
            fs2[s2[l] - 'a']--;
            l++;
            if(fs1 == fs2) return true;

        }


        return false;
    }
};
