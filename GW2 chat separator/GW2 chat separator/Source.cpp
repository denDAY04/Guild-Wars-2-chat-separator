#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;


/*
Segmentation rules for index 199:

* if char is white-space, backtrack to previous white-space, push next char
  to new segment, and end current segment with '-'.

* If char is punctuation, backtrack to previous white-space, push next char
  to new segment, and end current segment with '-'.

* Else push next char to new segment and end current segment with '-'.

*/
int main() {
	unsigned chatLimit = 199;
	
	string msgIn = "";


	// Get message from console and print blank line
	getline(cin, msgIn);
	cout << endl;

	// Don't process empty input
	if (msgIn.empty()) {
		cout << "Input was empty." << endl;
		return -1;
	}

	if (msgIn.size() <= chatLimit) {		
	// long enough to be in one mesage.
		cout << msgIn << endl;
	} else {
		
		// Store prefix chat-command, e.g. /e or /emote
		string prefix = "";
		decltype(msgIn.size()) prefixLength = 0;

		for (auto &c : msgIn) {
			if (!isspace(c)) {
			// Store each char until white-space
				prefix += c;
			} else {
			// Add the white-space and exit loop
				prefix += c;
				prefixLength = prefix.size();
				break;
			}
		}
		
		// If no destinct prefix (no white-space encountered above) length will be 0
		if (!prefixLength) {
			cout << "Missing prefix. Prefix must be seperated from message by a white-space ' '." << endl;
			return -1;
		}

		// Proccess the input message into segments and output them
		auto msgSize = msgIn.size();
		unsigned charCount = prefixLength;
		string segment = prefix;

		for (unsigned i = charCount; i != msgSize; ++i) {
			// Just copy values until 199th char
			if (charCount % (chatLimit - 1) != 0) {
				segment += msgIn[i];
				++charCount;
			} else {
				// Char is space or punctuation
				if (isspace(msgIn[i]) || ispunct(msgIn[i])) {
					// Backtrack to last whitespace (or index 0) and blank the passing chars in segment
					--charCount; --i;
					while (!isspace(msgIn[i]) && charCount > 0) {
						segment[charCount] = ' ';
						--charCount; --i;		// Backtrack indeces both for global input and segment output
					}
					// Insert '-' and leave next char for new segment
					segment[charCount + 1] = '-';
				} else {
					// Decrement index so that the current char is posted to next segment
					// Replace last char in segment with '-'
					--i;
					segment += '-';
				}

				// Output segment and prepare new segement and counter
				cout << segment << endl << endl;
				segment = prefix;
				charCount = prefixLength;
			}
		}
		// Flush the remaining segment that is not the length of chat limit
		cout << segment << endl;	
	}
	return 0;
}