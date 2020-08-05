// Design a data structure that supports the following two operations:
//         void addWord(word)
//         bool search(word)
                
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
    
//     Example:
//         addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true













class WordDictionary {
        struct TrieNode
        {
            struct TrieNode* val[26];
            bool IsEnd;
        };
    struct TrieNode* root;
public:
    
    struct TrieNode *getnode(void)
    {
        struct TrieNode *pNode =  new TrieNode; 
        pNode->IsEnd=false;
        for(int i=0;i<26;i++)
        {
            pNode->val[i]=NULL;
         }
        return pNode;
    }
    WordDictionary() {
        root=getnode();
    }
    
    
    void addWord(string word) {
       struct TrieNode* p = root;
         for(int i=0;i<word.length();i++)
         {
             int index=word[i]-'a';
             if(!p->val[index])
             {
                 p->val[index]=getnode();
             }
             p=p->val[index];
         }
        p->IsEnd=true;
    }
    bool check(struct TrieNode* p,string word,int v)
    {
        if(v==word.length())return (p != NULL && p->IsEnd);
      
        if(word[v]!='.')
        {
           int index=word[v]-'a';
            if(p->val[index])
            {
                return check(p->val[index],word,v+1);
            }
        }
        else
        {
            for(int i=0;i<26;i++)
            {
                if(p->val[i])
                {
                    if(check(p->val[i],word,v+1))return true;
                }
            }
        }
        return 0;
    }
    bool search(string word) {
        struct TrieNode* p = root;
        
        return check(p,word,0);
        
    }
};

