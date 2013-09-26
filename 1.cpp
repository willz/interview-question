#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int input_a[] = {1, 2, 4, 5};
    int input_b[] = {3, 9};
    // sum of A (volume of pack)
    int total_v = 0;
    int len_a = sizeof(input_a) / sizeof(int);
    for (int i = 0; i < len_a; ++i) {
        total_v += input_a[i];
    }
    // all elements of A and B (object weight)
    vector<int> w(input_a, input_a + len_a);
    w.insert(w.begin(), input_b, input_b + sizeof(input_b) / sizeof(int));

    // init table's value
    const unsigned int INF = 0xffffffff;
    vector<unsigned int> f(total_v + 1, INF);
    vector<unsigned int> tags(total_v + 1, 0);
    cout << f[total_v] << endl;
    for (size_t i = 0; i < w.size(); ++i) {
        if (w[i] <= total_v) {
            f[w[i]] = 1;
            tags[w[i]] = w[i];
        }
    }
    cout << f[1] << endl;
    for (size_t i = 0; i < w.size(); ++i) {
        for (int v = total_v; v >= 0; --v) {
            if (w[i] <= v) {
                // if f[v - w[i]] is INF, then f[v] := f[v]
                if (f[v - w[i]] != INF) {
                    f[v] = min(f[v], f[v - w[i]] + 1);
                    if (f[v] == f[v - w[i]] + 1) {
                        // record to find the path to get this optimal value
                        tags[v] = w[i];
                    }
                }
            }
        }
    }
    // output answer
    int v = total_v;
    while (tags[v] != v) {
        cout << tags[v] << " ";
        v -= tags[v];
    }
    cout << tags[v] << endl;
    cout << f[total_v] << endl;
    return 0;
}
