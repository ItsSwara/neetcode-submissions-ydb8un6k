class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);     // answer array, default 0
        stack<int> st;             // stores indices of waiting days

        // go day by day
        for (int i = 0; i < n; i++) {

            // while there is a previous day waiting
            // and today is warmer than that day
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();

                // calculate waiting days
                ans[prevDay] = i - prevDay;
            }

            // today is now waiting for a warmer future day
            st.push(i);
        }

        // remaining days in stack have no warmer day
        // ans already has 0 for them

        return ans;
    }
};
