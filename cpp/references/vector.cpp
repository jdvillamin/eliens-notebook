// declaration
vector<T> v;
vector<T> v = {v0, v1, v2, ...};
vector<T> v(size, initial);
// functions
v.begin();
v.end();
v.size();
v.empty();
v.push_back(x);
v.pop_back();
v.insert();
v.erase(x);
v.clear();
// algorithms
lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);
binary_search(v.begin(), v.end(), x);
// sort
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend()); // reverse iterators
sort(v.begin(), v.end(), greater<T>); // using functor
bool comp(T a, T b) {
  if (cond) {
    return true; // do not swap
  }
  return false;
}
sort(v.begin(), v.end(), comp); // using custom sort
sort(v.begin(), v.end(), [](const T a, const T b) {
  if (cond) {
    return true;
  }
  return false;
}); // using lambda function
