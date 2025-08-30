struct Node {
    Node* links[26];
    bool flag = false;

    bool containKeys(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKeys(word[i])) {
                node->putKey(word[i], new Node());
            }
            node = node->get(word[i]); // update node
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKeys(word[i])) {
                return false;
            }
            node = node->get(word[i]); // update node
        }
        return node->isEnd();
    }

    bool startWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKeys(word[i])) {
                return false;
            }
            node = node->get(word[i]); // update node
        }
        return true;
    }

    // Helper: longest common prefix
    string getLCP() {
        string prefix = "";
        Node* node = root;

        while (true) {
            int count = 0;
            char ch;
            Node* nextNode = nullptr;

            for (int i = 0; i < 26; i++) {
                if (node->links[i] != NULL) {
                    count++;
                    ch = 'a' + i;
                    nextNode = node->links[i];
                }
            }

            // If more than one branch OR end of word → stop
            if (count != 1 || node->isEnd()) break;

            prefix.push_back(ch);
            node = nextNode;
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for (auto& word : strs) {
            trie.insert(word);
        }
        return trie.getLCP();
    }
};
