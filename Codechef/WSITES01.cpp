    #include<bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define ALPHABET_SIZE (26)
    #define CHAR_TO_INDEX(c) ((int)c - (int)'a')
    using namespace std;
    int level;
    // trie node
    struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        // isLeaf is true if the node represents
        // end of a word
        bool isLeaf;
    };
     
    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode = NULL;
     
        pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
     
        if (pNode)
        {
            int i;
     
            pNode->isLeaf = false;
     
            for (i = 0; i < ALPHABET_SIZE; i++)
                pNode->children[i] = NULL;
        }
     
        return pNode;
    }
     
    // If not present, inserts key into trie
    // If the key is prefix of trie node, just marks leaf node
    void insert(struct TrieNode *root,string key)
    {
        int level;
        int length=key.length();
        int index;
        struct TrieNode *pCrawl=root;
        for(level=0;level<length;level++)
        {
            index=CHAR_TO_INDEX(key[level]);
            if(!pCrawl->children[index])
            pCrawl->children[index]=getNode();
            pCrawl=pCrawl->children[index];
        }
        // mark last node as leaf
        pCrawl->isLeaf = true;
    }
     
    int search(struct TrieNode *root,string key)
    {
        int length=key.length();
        int index;
        struct TrieNode *pCrawl=root;
        for(level=0;level<length;level++)
        {
            index=CHAR_TO_INDEX(key[level]);
            if(!pCrawl->children[index])
            return 1;
            pCrawl=pCrawl->children[index];
        }
        return 2;
    }
     
    int main()
    {
        struct TrieNode *root=getNode();
        int n;
        cin>>n;
        char c;
        string s;
        vector <string> block,unblock;
        map <string,int> ans;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            cin>>s;
            if(c=='-')
            block.pb(s);
            else
            unblock.pb(s);
        }
        for(int i=0;i<unblock.size();i++)
        insert(root,unblock[i]);
        bool flag=false;
        for(int i=0;i<block.size();i++)
        {
            int check=search(root,block[i]);
            if(check==1)
            {
                ans[block[i].substr(0,level+1)]=1;
            }
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
        cout<<-1<<endl;
        else
        {
            cout<<ans.size()<<endl;
            for(auto m : ans)
            cout<<m.first<<endl;
        }
        return 0;
    } 