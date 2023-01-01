class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operators ({"+","-","*","/"});
        stack<int> st;

        for(auto idx : tokens){

            if(operators.find(idx) == operators.end()){ // check for operators

                st.push(stoi(idx)); // push and convert string to int
            }
            else{
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(idx == "+") st.push(a+b);
                else if(idx == "-") st.push(a-b);
                else if(idx == "*") st.push(a*b);
                else st.push(a/b);
            }
        }
        return st.top();

    }
};

Time complexity: O(n)
Space complexity: O(n)
