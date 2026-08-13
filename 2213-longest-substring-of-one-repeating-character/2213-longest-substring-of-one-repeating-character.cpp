class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char lc;
        char rc;
    };

    vector<Node> tree;
    string s;

    Node merge(Node A, Node B) {

        Node C;

        C.len = A.len + B.len;
        C.lc = A.lc;
        C.rc = B.rc;

        C.best = max(A.best, B.best);

        C.pref = A.pref;
        C.suff = B.suff;

        if (A.rc == B.lc) {

            C.best = max(
                C.best,
                A.suff + B.pref
            );

            if (A.pref == A.len) {
                C.pref = A.len + B.pref;
            }

            if (B.suff == B.len) {
                C.suff = A.suff + B.len;
            }
        }

        return C;
    }

    void build(int node, int l, int r) {

        if (l == r) {

            tree[node] = {
                1, 1, 1, 1,
                s[l], s[l]
            };

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {

            tree[node] = {
                1, 1, 1, 1,
                c, c
            };

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};