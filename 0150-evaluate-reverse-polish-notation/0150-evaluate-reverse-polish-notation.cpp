// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<string> st;
//         //if operation like +-*... then take last 2 numbers from stack and apply that operation
//         //if number then push in stack
//         int size=tokens.size();
//         for(int i=0;i<size;i++){
//             if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
//                 int number1=stoi(st.top());
//                 st.pop();
//                 int number2=stoi(st.top());
//                 st.pop();
//                 int res=0;
//                 if(tokens[i]=="+"){
//                     res=number2+number1;
//                 }
//                 else if(tokens[i]=="-"){
//                     res=number2-number1;        // doing numbers 2 first because stack if lifo
//                 }
//                 else if(tokens[i]=="*"){
//                     res=number2*number1;
//                 }
//                 else if(tokens[i]=="/"){
//                     res=number2/number1;
//                 }
//                 st.push(to_string(res));
//             }
//             else{
//                 st.push(tokens[i]);
//             }
//         }
//         return stoi(st.top());
//     }
// };



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = st.top(); st.pop();
                int left  = st.top(); st.pop();

                if (token == "+") st.push(left + right);
                else if (token == "-") st.push(left - right);
                else if (token == "*") st.push(left * right);
                else st.push(left / right);
            } 
            // If token is a number
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
