#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int priority(char cOperator);
string convertInfixToPostfix(string strInfix);
int evaluatePostfix(string strPostfix);

int main() {
	string strInfix;
	getline(cin, strInfix);
	cout << convertInfixToPostfix(strInfix) << endl;
	//cout << evaluatePostfix(convertInfixToPostfix(strInfix));
}

int priority(char cOperator) {
	if (cOperator == '+' || cOperator == '-')
		return 1;
	if (cOperator == '*' || cOperator == '/')
		return 2;
	if (cOperator == '^')
		return 3;
	return 0;
}

string convertInfixToPostfix(string strInfix) {
	stack<char> stackOperator;
	string strPostfix = "";
	for (int i = 0; i < strInfix.size(); i++) {
		for (; strInfix.at(i) == ' '; i++);
		if (isalnum(strInfix.at(i))) {
			strPostfix = strPostfix + " " + strInfix.at(i);
			for (; isalnum(strInfix.at(i + 1)); i++) {
				strPostfix += strInfix.at(i + 1);
			}
		}
		else if (strInfix.at(i) == '(')
			stackOperator.push('(');
		else if (strInfix.at(i) == ')') {
			while (stackOperator.top() != '(') {
				strPostfix = strPostfix + " " + stackOperator.top();
				stackOperator.pop();
			}
			stackOperator.pop();
		}
		else {
			while (!stackOperator.empty() && priority(strInfix.at(i)) <= priority(stackOperator.top())) {
				strPostfix = strPostfix + " " + stackOperator.top();
				stackOperator.pop();
			}
			stackOperator.push(strInfix[i]);
		}
	}
	while (!stackOperator.empty()) {
		strPostfix = strPostfix + " " + stackOperator.top();
		stackOperator.pop();
	}
	return strPostfix.erase(0, 1);
}
int evaluatePostfix(string strPostfix) {
	stack<int> stackTemp;
	for (int i = 0; i < strPostfix.size(); i++) {
		for (; strPostfix.at(i) == ' '; i++);
		if (isdigit(strPostfix.at(i))) {
			int iNumTemp = 0;
			for (; isdigit(strPostfix.at(i)); i++) {
				iNumTemp = iNumTemp * 10 + (strPostfix.at(i) - '0');
			}
			stackTemp.push(iNumTemp);
		}
		else {
			int od1 = stackTemp.top();
			stackTemp.pop();
			int od2 = stackTemp.top();
			stackTemp.pop();
			switch (strPostfix.at(i)) {
			case '+': stackTemp.push(od2 + od1); break;
			case '-': stackTemp.push(od2 - od1); break;
			case '*': stackTemp.push(od2 * od1); break;
			case '/': stackTemp.push(od2 / od1); break;
			case '^': stackTemp.push(pow(od2, od1)); break;
			}
		}
	}
	return stackTemp.top();
}
