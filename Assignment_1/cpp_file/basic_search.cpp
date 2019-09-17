#include<iostream>
#include<string>

using namespace std;

int main() {
	
	string str;
	string tok;
	size_t found;

	cout << "Line Entry: " << endl;
	getline(cin, str);

	cout << "Token Entry: " << endl;
	getline(cin, tok);
	
	found = str.find(tok);
	if (found != std::string::npos){
		cout << "FOUND" << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}

	return 0;

}
