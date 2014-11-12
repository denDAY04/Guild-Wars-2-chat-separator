#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	unsigned chatLimit = 199;
	string prefix = "";
	string msgIn = "";


	// Get message from console
	getline(cin, msgIn);
	cout << endl;


	// long enough to be in one mesage.
	if (msgIn.size() < chatLimit) {		
		cout << msgIn << endl;
	} else {
		// Three first characts are chat command, e.g. "/e "
		auto msgSize = msgIn.size();
		prefix = msgIn.substr(0, 3);
		string msgOut = "";
		unsigned charCount = 0;

		for (int i = 2; i != msgSize; ++i) {
			// Add prefix is first char
			if (charCount == 0) {
				msgOut += prefix;
				charCount = 3;
			} else if (charCount != chatLimit) {
			// Add char if not at limit-1 (need to add '-') and incement counter
				msgOut += msgIn[i];
				++charCount;
			} else {
			// Add '-', reset char counter, and print message
				msgOut += '-';
				charCount = 3;
				cout << msgOut << endl << endl;
				msgOut = prefix + msgIn[i];
			}
		}
		// Flush the remaining message
		cout << msgOut << endl << endl;
	}

	return 0;
}