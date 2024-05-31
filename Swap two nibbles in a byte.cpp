class Solution {
  public:
    int swapNibbles(int n) {
        string s = bitset<8>(n).to_string();
        string s1 = s.substr(0, 4);
        string s2 = s.substr(4);
        s = s2 + s1;

        return stoi(s,0,2);
    }
};