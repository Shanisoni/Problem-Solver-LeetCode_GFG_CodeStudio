class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLength = words[0].length();
        int totalLength = wordLength * words.size();
ṇ
        // Check if the input string is long enough for the concatenated words
        if (s.length() < totalLength) {
            return result;  // Return an empty result if not enough characters in s
        }

        // Create a frequency map for the words
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Iterate through each potential starting index for the substring
        for (int i = 0; i < wordLength; ++i) {


            
            int left = i;
            int right = i;
            unordered_map<string, int> currentFreq;

            while (right + wordLength <= s.length()) {
                string currentWord = s.substr(right, wordLength);
                right += wordLength;

                // If the word is not in the frequency map, reset the window
                if (wordFreq.find(currentWord) == wordFreq.end()) {
                    currentFreq.clear();
                    left = right;
                } else {
                    currentFreq[currentWord]++;
                    while (currentFreq[currentWord] > wordFreq[currentWord]) {
                        string leftWord = s.substr(left, wordLength);
                        currentFreq[leftWord]--;
                        left += wordLength;
                    }

                    // Check if the window size matches the total length of concatenated words
                    if (right - left == totalLength) {
                        result.push_back(left);
                    }
                }
            }
        }

        return result; 
    }
};