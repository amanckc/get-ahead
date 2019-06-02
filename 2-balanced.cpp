#include <iostream>
#include <stack>
#include <string>

int longestBalanced(std::string p) {

	// we could use the length to iterate safely.
	int l = p.length();
	// we need a stack to keep the opening parentheses. 
	std::stack <char> s;
	// length of the maximum substring.
	int max = 0;
	// length of the current substring.
	int cur = 0;

	for (int i=0; i<l; i++){
		// read the character to see if it is a closing parentheses.
		if (p[i] == ')'){
			// if there is an opening parentheses in the stack,
			if (!s.empty() && s.top() == '(') {
				// match the parentheses and increment the count of the substring,
				cur+= 2;
				// pop from the stack.
				s.pop();
			}
			// if the stack is empty, the current substring is over because we cannot match anything.
			else cur = 0;
		}
		// whenever there is an opening parentheses, push it to the stack.
		else s.push(p[i]);
		// if the current substring is longer than the previously found maximum one, update the maximum.
		if (cur > max) max = cur;
	}
	
	return max;
}

// main for testing. some edge & general cases:

// ()()()): 					6
// (((())(())(())(())(()))): 	24
// ((((((((((:					0
// )))))))))):					0
// )(:							0

int main(){
	std::string s;
	std::cin >> s;
	std::cout << longestBalanced(s);
}