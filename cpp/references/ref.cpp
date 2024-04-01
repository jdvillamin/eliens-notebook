st.insert(4);
st.erase(4);
st.empty();
// permutations
do {
for (int num : nums) {
cout << num << " ";
}
cout << endl;
} while (next_permutation(nums.begin(), nums.end()));
// bitset
int num = 27; // Binary representation: 11011
bitset<10> s(string("0010011010")); // from right to left
bitset<sizeof(int) * 8> bits(num);
int setBits = bits.count();
// sort
sort(v.begin(),v.end());
sort(v.rbegin(),v.rend());
// custom sort
bool comp(string a, string b) {
if (a.size() != b.size()) return a.size() < b.size();
return a < b;
}
sort(v.begin(), v.end(), comp);
// binary search
int a = 0, b = n-1;
while (a <= b) { int k = (a+b)/2; if (array[k] == x) {
// x found at index k
} if (array[k] > x) b = k-1; else a = k+1;}
// iterator
for (auto it = s.begin(); it != s.end(); it++) {
cout << *it << "\n";
}
// hamming distance
int hamming(int a, int b) {
return __builtin_popcount(a^b);
}
// custom comparator for pq
class Compare {
public:
bool operator()(T a, T b){
if(cond) return true; // do not swap
return false;
}
};
priority_queue<PII, vector<PII>, Compare> ds;