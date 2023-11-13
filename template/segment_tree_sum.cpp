#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class segment_tree {
    vector<int> list;

public:
    segment_tree(vector<int> &v) {
        int n = v.size();
        if (n > 0) {
            list.resize(4 * n);
            make_tree(v, 0, 0, n - 1);
        }
    }

    int make_tree(vector<int> &v, int node, int start, int end) {
        if (start > end)
            return 0;
        if (start == end) {
            list[node] = v[start];
            return v[start];
        }
        int mid = (start + end) / 2;
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        list[node] = (make_tree(v, left, start, mid) + make_tree(v, right, mid + 1, end));
        return list[node];
    }

    int get_sum(int cur, int start, int end, int start_t, int end_t) {
        if (start_t <= start && end_t >= end)
            return list[cur];
        if (end_t < start || start_t > end)
            return 0;
        int mid = (start + end) / 2;
        return (get_sum(2 * cur + 1, start, mid, start_t, end_t) +
                get_sum(2 * cur + 2, mid + 1, end, start_t, end_t));
    }

    int sum_in_range(int left, int right) {
        int n = list.size() / 4;
        return get_sum(0, 0, n - 1, left, right);
    }

    int update_val(int node, int start, int end, int i, int new_val) {
        if (start == end) {
            int dif = new_val - list[node];
            list[node] = new_val;
            return dif;
        }
        int mid = (start + end) / 2;
        if (i <= mid) {
            int dif = update_val(2 * node + 1, start, mid, i, new_val);
            list[node] += dif;
            return dif;
        } else {
            int dif = update_val(2 * node + 2, mid + 1, end, i, new_val);
            list[node] += dif;
            return dif;
        }
    }

    void update(int i, int new_val) {
        int n = list.size() / 4;
        update_val(0, 0, n - 1, i, new_val);
    }
};

int main() {
    vector<int> v = {2, 44, 9, 29, -1, 30, 4, 66, 2, 6};
    segment_tree tree(v);
    cout << tree.sum_in_range(0,v.size()-1)<<endl;
    tree.update(2,11);
    cout << tree.sum_in_range(0,v.size()-1)<<endl;
    return 0;
}
