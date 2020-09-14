#include <iostream>
#include <stack>

bool isVaild(const std::string& brackets) {
	std::stack<char> s;
	for(int i = 0; i < brackets.length(); i++) {
		if (brackets[i] == ')'){
			if (!s.empty() && s.top() == '(') s.pop();
			else return false;
		}
		else if (brackets[i] == ']' ) {
			if (!s.empty() && s.top() == '[') s.pop();
			else return false;
		}
		else 
			s.push(brackets[i]);
	}
	return true;
}

int main(){
	std::string brackets = "([]())";
	if(isVaild(brackets)) 
		std::cout << "brackets is vaild." << std::endl;
	else
		std::cout << "brackets is invaild. " << std::endl; 
	return 0;
}
