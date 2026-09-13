#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // Step 1: Length must be same
        if (word1.length() != word2.length()) {
            return false;
        }

        // Step 2: Frequency arrays
        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count characters of word1
        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        // Count characters of word2
        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        // Step 3: Both strings must contain the same characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0) != (freq2[i] == 0)) {
                return false;
            }
        }

        // Step 4: Sort frequencies
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);

        // Step 5: Compare frequencies
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    string word1, word2;

    cout << "Enter first string: ";
    cin >> word1;

    cout << "Enter second string: ";
    cin >> word2;

    if (obj.closeStrings(word1, word2)) {
        cout << "The strings are close." << endl;
    }
    else {
        cout << "The strings are not close." << endl;
    }

    return 0;
}