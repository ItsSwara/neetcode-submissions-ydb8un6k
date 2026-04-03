#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;      // stores actual values
    stack<int> minSt;   // stores minimum at each level

public:
    MinStack() {
        // constructor
    }

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        } else {
            // repeat current minimum
            minSt.push(minSt.top());
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

