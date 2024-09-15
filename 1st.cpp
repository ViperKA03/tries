#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag = 0;
    bool containsKey(char ch) {
        if (links[ch - 'a'] != NULL)
            return 1;
        return 0;
    }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void end() { flag = 1; }
    bool isEnd() { return flag; }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->end();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i]))
                return 0;
            node = node->get(prefix[i]);
        }
        return 1;
    }
};
int main()
{
    Trie *node=new Trie();
    node->insert("Lund Samarth");
   cout<< node->search("Lund Samarth");
   return 0;
}