#include <bits/stdc++.h>
using namespace std;

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp){
    // Create a stack of capacity equal to expression size
	stack<int> st;
	int i;

    // Scan all characters one by one
	for (i = 0; exp[i]; ++i) {
        // If the character is blank space then continue
		if (exp[i] == ' ')
			continue;

        // If the scanned character is an
		// operand (number here),extract the full number
		// Push it to the stack.
		else if (isdigit(exp[i])) {
			int num = 0;

			// Extract full number
			while (isdigit(exp[i])) {
				num = num * 10 + (int)(exp[i] - '0');
				i++;
			}
			i--;

			// Push the element in the stack
			st.push(num);
		}

        // If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();

			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}
	}
	return st.top();
}

// Driver code
int main(){
	// char exp[] = "100 200 + 2 / 5 * 7 +";
	char exp[] = "2 3 1 * + 9 -";

	// Function call
	cout << evaluatePostfix(exp);
	return 0;
}


