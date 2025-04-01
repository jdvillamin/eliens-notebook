// declaration
set<T> st;
set<T, greater<T>> st;
// custom comparator
class Compare {
public:
  bool operator() (T a, T b) {
    if (cond) return true; // do not swap
    return false;
  }
}
set<T, Compare> st; 
// functions
st.insert(x);
st.erase(x);
st.size();
st.empty();
st.begin();
st.end();
st.clear();
st.count(x);
st.find(x);
st.lower_bound(x); // first element not less than x
st.upper_bound(x); // first element greater than x
