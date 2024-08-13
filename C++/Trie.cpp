#include <iostream>
using namespace std;

class Node {
public:
    Node* links[26];  // Array to store references to the next nodes
    int EW = 0;  // To indicate the end of a word
    int cPre = 0; // To count words with the same prefix

    // Check if the current node has a reference to a child node corresponding to a character
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Add a reference to a child node for a given character
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the reference to a child node for a given character
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Mark the end of a word
    void setEnd() {
        EW++;
    }

    // Decrease the end word count
    void decreaseEnd() {
        if (EW > 0) EW--;
    }

    // Check if this node marks the end of a word
    bool isEnd() {
        return EW > 0;
    }

    // Increase prefix count
    void increasePrefix() {
        cPre++;
    }

    // Decrease prefix count
    void decreasePrefix() {
        if (cPre > 0) cPre--;
    }

    // Get the count of words with this prefix
    int getPrefixCount() {
        return cPre;
    }

    int getendswith() {
        return EW;
    }
};

class Trie {
private:
    Node* root;
    int countNodes;

public:
    // Initializing data structure
    Trie() {
        root = new Node();
        countNodes = 1;
    }

    // Inserting a word into the Trie
    void insert(string word) {
        Node* node = root;  // Start from the root
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
                countNodes++;
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd();  // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;  // If the word is not found
            }
            node = node->get(word[i]);
        }
        return node->isEnd();  // Check if it is a complete word
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;  // If the prefix is not found
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

    // Count how many times a word is in the Trie
    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;  // Word does not exist
            }
            node = node->get(word[i]);
        }
        return node->getendswith();
    }

    // Count how many words start with a given prefix
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return 0;  // Prefix does not exist
            }
            node = node->get(prefix[i]);
        }
        return node->getPrefixCount();
    }

    // Erase a word from the Trie
    void erase(string word) {
        if (search(word)) {  // Ensure the word exists in the Trie
            Node* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (node->containsKey(word[i])) {
                    Node* nextNode = node->get(word[i]);
                    nextNode->decreasePrefix();  // Decrease prefix count
                    node = nextNode;
                }
            }
            node->decreaseEnd();  // Decrease the end word count
        }
    }

    // Check if all prefixes of the word are complete in the Trie
    bool findCompleteString(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;  // Prefix not found
            }
            node = node->get(word[i]);
            if (!node->isEnd()) {
                return false;  // Current prefix is not a complete word
            }
        }
        return true;  // All prefixes are complete words
    }

    // Count distinct substrings of a word using Trie
    int countDistinctSubstrings1(string word) {
        Trie tempTrie; // Temporary Trie to count distinct substrings
        int cnt = 0;

        for (int i = 0; i < word.size(); i++) {
            Node* node = tempTrie.root; // Start from the temporary Trie root

            for (int j = i; j < word.size(); j++) {
                if (!node->containsKey(word[j])) {
                    node->put(word[j], new Node());
                    cnt++;
                }
                node = node->get(word[j]);
            }
        }
        return cnt+1;
    }

    // Count distinct substrings of a word using Trie
    //very in-efficient the time complexity is quadratic, should be avoided 
    int countDistinctSubstrings2(string word) {
    // Insert all suffixes of the word into the Trie
    for (int i = 0; i < word.size(); i++) {
        insert(word.substr(i));
    }
    return countNodes ;  // Adding 1 to count the empty substring
}

};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("appl");
    trie.insert("app");
    trie.insert("ap");
    trie.insert("a");

    cout << trie.countWordsEqualTo("apple") << endl;   
    cout << trie.countWordsStartingWith("app") << endl; 
    trie.erase("apple");
    cout << trie.countWordsEqualTo("apple") << endl;   
    cout << trie.countWordsEqualTo("app") << endl; 
    cout << trie.countWordsEqualTo("orange") << endl; 
    cout << trie.countWordsStartingWith("app") << endl; 

    cout << trie.search("app") << endl; 

    // Check for complete string
    cout << (trie.findCompleteString("apple") ? "Complete String" : "Not a Complete String") << endl; // returns Not a Complete String
    cout << (trie.findCompleteString("ap") ? "Complete String" : "Not a Complete String") << endl;  // returns Complete String

    cout << trie.countDistinctSubstrings1("apple") << endl;
    cout << trie.countDistinctSubstrings2("apple") << endl;

    return 0;
}
