class Node{
    public:
        Node* links[26];
        int cntChildren = 0;
        bool end = false;

        bool containsKey(char ch){
            return links[ch-'a'] != NULL;
        }

        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void incChildren(){
            cntChildren++;
        }

        void setEnd(){
            end = true;
        }

        bool isEnd(){
            return end;
        }
};

class Trie{
    Node* root;

    public: 
        Trie(){
            root = new Node();
        }

        void insert(string& word){
            Node* node = root;
            for(int i = 0 ; i < word.length() ; i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i],new Node());
                    node->incChildren();
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }


        string preficLCP(string& word) {
            Node* node = root;
            string ans = "";

            for(int i = 0 ; i < word.length() ; i++) {
                char ch = word[i];

                if(node->cntChildren == 1 && !node->isEnd()){
                    ans += ch;
                } else {
                    break;
                }
                node = node->get(ch);
            }
            return ans;
        }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for(auto str: strs){
            trie.insert(str);
        }

        string first = strs[0];
        
        return trie.preficLCP(first);
    }
};
