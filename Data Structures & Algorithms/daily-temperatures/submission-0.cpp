class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute force - O(n^2)
        int n = temperatures.size();

        stack<int>st;
        st.push(n-1);
        vector<int>res(n);
        res[n-1]=0;
        
        for(int i = n-2; i>=0; i--){
           int pos=0;
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
               
            }

            if(!st.empty()){
                pos = st.top() - i;
            }else{
                pos=0;
            }

            st.push(i);

            res[i]=pos;
        }

        return res;
    }
};
