#ifndef PREP_BINARY_TREE_H
#define PREP_BINARY_TREE_H

struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;

    BTNode(int v) : val(v), left(nullptr), right(nullptr) {}
    BTNode(int v, BTNode *l, BTNode *r) : val(v), left(l), right(r) {}
};

inline BTNode *make_sample_btree()
{
    return new BTNode(
        42,
        new BTNode(
            13,
            new BTNode(55),
            new BTNode(11)
        ),
        new BTNode(
            21,
            new BTNode(94),
            new BTNode(31)
        )
    );
}

#endif // PREP_BINARY_TREE_H
