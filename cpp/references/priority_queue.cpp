// declaration
priority_queue<T> pq;
priority_queue<T> pq(v.begin(), v.end());
priority_queue<T, vector<T>, greater<T>> pq;
// custom comparator
class Compare {
public:
  bool operator() (T a, T b) {
    if (cond) {
        return true; // do not swap
    }
    return false;
  } 
};
priority_queue<T, vector<T>, Compare> pq;
// functions
pq.empty();
pq.size();
pq.top();
pq.push(x);
pq.pop();
