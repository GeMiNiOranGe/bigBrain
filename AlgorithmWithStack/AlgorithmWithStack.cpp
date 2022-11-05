#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string strPostfix);

int main() {
	string strPostfix;
	getline(cin, strPostfix);
	cout << evaluatePostfix(strPostfix);
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
			}
		}
	}
	return stackTemp.top();
}
