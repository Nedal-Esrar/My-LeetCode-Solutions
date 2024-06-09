

class Solution {
private:
  struct TrieNode {
    TrieNode* children[26]{};
    bool is_terminal = false;
  };
  
  class Trie {
  private:
    TrieNode* root = new TrieNode();
  public:
    void insert(const string& word) {
      TrieNode* cur = root;
      
      for (char c : word) {
        if (cur->children[c - 'a'] == nullptr) {
          cur->children[c - 'a'] = new TrieNode();
        }
        
        cur = cur->children[c - 'a'];
      }
      
      cur->is_terminal = true;
    }
    
    string find_prefix(const string& word) {
      TrieNode* cur = root;
      
      string ret;
      
      for (char c : word) {
        if (cur->children[c - 'a'] == nullptr) {
          return word;
        }
        
        ret += c;
        
        if (cur->children[c - 'a']->is_terminal) {
          return ret;
        }
        
        cur = cur->children[c - 'a'];
      }
      
      return word;
    }
  };
public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trie;
    
    for (const string& word : dictionary) {
      trie.insert(word);
    }
    
    stringstream ss(sentence);
    
    string cur_word, ret;
    
    ss >> ret;
    
    ret = trie.find_prefix(ret);
    
    while (ss >> cur_word) {
      ret += " ";
      
      ret += trie.find_prefix(cur_word);
    }
    
    return ret;
  }
};