class Solution {
   public:
    string minWindow(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        string res = "";

        if (ns < nt) return "";

        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        for (int i = 0; i < nt; ++i) {
            ft[t[i]]++;
        }

        int left = 0;
        int minlen = ns + 1;
        int start = 0;
        int formed = 0;

        for (int right = 0; right < ns; ++right) {
            char c = s[right];
            fs[c]++;

            if (ft.count(c) && ft[c] == fs[c]) {
                formed++;
            }

            while (formed == ft.size()) {
                int windowLen = right - left + 1;

                if (minlen > windowLen) {
                    minlen = windowLen;
                    start = left;
                }

                char outgoing = s[left];
                fs[outgoing]--;
                if (ft.count(outgoing) && ft[outgoing] > fs[outgoing]) {
                    formed--;
                }
                left++;
            }
        }

        if (minlen == ns + 1) return "";

        return s.substr(start,minlen);
    }
};
