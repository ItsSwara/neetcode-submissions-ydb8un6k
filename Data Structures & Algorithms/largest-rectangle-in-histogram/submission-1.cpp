#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Treat end as 0 height to flush stack
            int currHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                
                maxArea = max(maxArea, h * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};