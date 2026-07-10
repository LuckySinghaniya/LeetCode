class MinStack {
public:
    stack<long long> st;
    long long minimum;

    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minimum = value;
        }
        else if (value >= minimum) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minimum);
            minimum = value;
        }
    }

    void pop() {
        if (st.top() >= minimum) {
            st.pop();
        }
        else {
            long long x = st.top();
            st.pop();
            minimum = 2LL * minimum - x;
        }

        if (st.empty())
            minimum = 0;
    }

    int top() {
        if (st.top() >= minimum)
            return (int)st.top();
        return (int)minimum;
    }

    int getMin() {
        return (int)minimum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna