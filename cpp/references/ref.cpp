// vector 
push_back()
pop_back()
size()
clear()
erase()
empty()
Iterator lower_bound(Iterator first, Iterator last, const val)
Iterator upper_bound(Iterator first, Iterator last, const val)
// stack
push()
pop()
top()
empty()
size()
// queue
push()
pop()
front()
empty()
back()
size()
// priority_queue
push()
pop()
size()
empty()
top()
// set
insert()
begin()
end()
size()
find()
count()
empty()
// multiset
begin()
end()
size()
max_size()
empty()
insert(x) // O(log n)
clear()
erase(x)
// map
begin()
end()
size()
max_size()
empty()
pair insert(keyvalue, mapvalue)
erase(iterator position)
erase(const g)
clear()
// ordered_set
find_by_order(k)
order_of_key(k)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
// tuple
get<i>(tuple)
make_tuple(a1, a2, ...)
tuple_size<decltype(tuple)>::value
tuple1.swap(tuple2)
tie(a1, a2, ...) = tuple
tuple_cat(tuple1, tuple2)
// iterator
for (auto it = s.begin(); it != s.end(); it++) cout << *it << "\n";
begin()
end()
advance(ptr, k)
next(ptr, k)
prev(ptr, k)
// permutations
do {} while (next_permutation(nums.begin(), nums.end()));
// bitset
int num = 27; // Binary representation: 11011
bitset<10> s(string("0010011010")); // from right to left
bitset<sizeof(int) * 8> bits(num);
int setBits = bits.count();
bits.set(index, val);
bits.reset();
bits.flip();
bits.all();
bits.any();
bits.none();
bits.test();
to_string();
to_ulong();
to_ullong();
[], &, |, !, >>=, <<=, &=, |=, ^=, ~;
// sort
sort(v.begin(),v.end());
sort(v.rbegin(),v.rend());
// custom sort
bool comp(string a, string b) {
  if (a.size() != b.size()) return a.size() < b.size(); 
  return a < b; }
sort(v.begin(), v.end(), comp);
// hamming distance
int hamming(int a, int b) { return __builtin_popcount(a ^ b); }
// custom comparator for pq
class Compare {
public:
bool operator() (T a, T b) {
if(cond) return true; // do not swap
return false; } };
priority_queue<PII, vector<PII>, Compare> ds;
// gcc compiler
__builtin_popcount(x)
__builtin_parity(x)
__builtin_clz(x) // leading
__builtin_ctz(x) // trailing