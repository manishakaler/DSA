#include<cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        if(n == 1) return true;
        string filteredStr = "";
        for(auto& c: s){
            if(!isalnum(c)){
                continue;
            }
            c = tolower(c);
            filteredStr+=c;
        }
        cout<<"fs: "<<filteredStr<<endl;
        int left = 0;
        int right = filteredStr.size()-1;

        while(left < right){
            
            if(filteredStr[left] != filteredStr[right]){
                return false;
            } else{
                left++;
                right--;
            }
        }

        return true;
    }
};
