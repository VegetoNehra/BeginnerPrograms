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
        return  EW>0;// IF EW>0 returns bool value
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
    
    int getendswith(){
        return EW;
    }
};

class Trie {
private:
    Node* root;

public:
    // Initializing data structure
    Trie() {
        root = new Node();
    }

    // Inserting a word into the Trie
    void insert(string word) {
        Node* node = root;  // Start from the root
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
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
        //return node->isEnd() ? node->EW:0;  // Returns EW if isend true else 0 if isend false.
        //?: This is the ternary conditional operator, which is a shorthand for an if-else statement.
    }

    // Count how many words start with a given prefix
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;  // Prefix does not exist
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
    trie.insert("apple"); 

    // Check for complete string
    cout << (trie.findCompleteString("apple") ? "Complete String" : "Not a Complete String") << endl; // returns Not a Complete String
    cout << (trie.findCompleteString("ap") ? "Complete String" : "Not a Complete String") << endl;  // returns Complete String

    return 0;
}
