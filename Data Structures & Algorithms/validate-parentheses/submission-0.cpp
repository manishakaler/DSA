class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();

        if(n== 0) return true;

        for(int i = 0; i < n; i++ ){
            if(s[i]== ')' || s[i]== '}' || s[i]== ']'){
                switch(s[i]){
                    case ')': if(!st.empty() && st.top() == '('){
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                    case ']': if(!st.empty() && st.top() == '['){
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                    case '}': if(!st.empty() && st.top() == '{'){
                        st.pop();
                    } else {
                        return false;
                    }
                    break;
                }
            }else{
                st.push(s[i]);
            }
        }

       

        return st.empty();
    }
};
