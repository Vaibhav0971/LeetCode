class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        data = d;
        isTerminal = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }    
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(ch);
            root -> children[index] = child;
        }

        insertHelper(child, word.substr(1));
    }

    void insert(string word){
        insertHelper(root, word);
    }
    
    string replaceHelper(TrieNode* root, string word, string temp){
        if(root -> isTerminal){
            temp.push_back(root -> data);
            return temp;
        }
        if(word.length() == 0) return "";
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        
        if(root -> children[index] != NULL){
            if(root -> data != '\0') temp.push_back(root -> data);
            
            child = root -> children[index];
        }
        else{
            return "";
        } 
        
        return replaceHelper(child, word.substr(1), temp);
    }
    
    string replace(string word){
        string ans = replaceHelper(root, word, "");
        
        return ans.length() == 0 ? word : ans;
    }
};




class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie();
        
        for(auto i : dictionary){
            t -> insert(i);
        }
        
        vector<string> words;
        string temp = "";
        
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' '){
                words.push_back(temp);
                temp = "";
            }
            else{
                temp += sentence[i];            
            }
        }
        words.push_back(temp);
        
        string ans = "";
        for(int i=0; i<words.size(); i++){
            ans += t -> replace(words[i]); 
            
            if(i != words.size() - 1){
                ans += " ";
            }
            
        }
        
        return ans;
    }
};