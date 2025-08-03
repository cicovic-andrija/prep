// #my-easy-5

#include "markers.h"
#include "binary_tree.h"

#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>

void preorder(BTNode *root);
void preorder_iterative(BTNode *root);
void postorder(BTNode *root);
void postorder_iterative(BTNode *root);
void inorder(BTNode *root);
void inorder_iterative(BTNode *root);
void level(BTNode *root); // also demonstrates BFS
void reverse(BTNode *root);
BTNode *find_dfs(BTNode *root, int key); // demonstrates DFS

int main()
{
    __BEGIN

    BTNode *root = make_sample_btree();

    std::cout << "PREORDER" << std::endl;
    preorder(root);
    std::cout << "PREORDER (iterative)" << std::endl;
    preorder_iterative(root);
    std::cout << "POSTORDER" << std::endl;
    postorder(root);
    std::cout << "POSTORDER (iterative)" << std::endl;
    postorder_iterative(root);
    std::cout << "INORDER" << std::endl;
    inorder(root);
    std::cout << "INORDER (iterative)" << std::endl;
    inorder_iterative(root);
    std::cout << "LEVEL" << std::endl;
    level(root);
    std::cout << "DFS" << std::endl;
    find_dfs(root, 101);
    std::cout << "PREORDER after REVERSE" << std::endl;
    reverse(root);
    preorder(root);

    __END
}

void preorder(BTNode *root)
{
    if (root == nullptr) return;
    std::cout << root->val << std::endl;
    preorder(root->left);
    preorder(root->right);
}

void preorder_iterative(BTNode *root)
{
    if (root == nullptr) return;

    std::stack<BTNode *> s;
    s.push(root);
    while (!s.empty()) {
        BTNode *curr = s.top();
        s.pop();
        while (curr != nullptr) {
            std::cout << curr->val << std::endl;
            if (curr->right) s.push(curr->right);
            curr = curr->left;
        }
    }
}

void postorder(BTNode *root)
{
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << std::endl;
}

void postorder_iterative(BTNode *root)
{
    std::stack<std::tuple<BTNode *, bool>> s;
    BTNode *next = root;
    while (next) {
        s.push({ next, false });
        next = next->left;
    }
    while (!s.empty()) {
        next = std::get<0>(s.top());
        bool right_subtree_done = std::get<1>(s.top());
        s.pop();
        if (!right_subtree_done) {
            s.push({ next, true });
            next = next->right;
            while (next) {
                s.push({ next, false });
                next = next->left;
            }
        } else {
            // right subtree processing is completed
            std::cout << next->val << std::endl;
        }
    }
}

void inorder(BTNode *root)
{
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << std::endl;
    inorder(root->right);
}

void inorder_iterative(BTNode *root)
{
    std::stack<BTNode *> s;
    BTNode *next = root;
    while (true) {
        while (next != nullptr) {
            s.push(next);
            next = next->left;
        }
        if (s.empty()) return;
        next = s.top();
        s.pop();
        std::cout << next->val << std::endl;
        next = next->right;
    }
}

void level(BTNode *root)
{
    if (root == nullptr) return;

    std::queue<BTNode *> q;
    q.push(root);
    while (!q.empty()) {
        BTNode *curr = q.front();
        std::cout << curr->val << std::endl;
        q.pop();
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

BTNode *find_dfs(BTNode *root, int key)
{
    if (root == nullptr) return nullptr;
    std::stack<BTNode *> s;
    s.push(root);
    while (!s.empty()) {
        BTNode *curr = s.top();
        s.pop();
        if (curr->val == key) return curr;
        std::cout << "Value " << key << " not found at (" << curr->val << ")" << std::endl;
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
    return nullptr;
}

void reverse(BTNode *root)
{
    if (root == nullptr) return;

    std::queue<BTNode *> q;
    q.push(root);
    while (!q.empty()) {
        BTNode *curr = q.front();
        q.pop();
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
        std::swap(curr->left, curr->right);
    }
}
