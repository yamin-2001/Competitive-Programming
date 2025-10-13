#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* links[26*2];
    bool isEnd;
    int cnt;
    Node(){
        isEnd=false;
        cnt=0;
        for(int i=0;i<2*26;i++)links[i]=nullptr;
    }
    Node* get(char c)
    {
        int g=(c>'Z');
        int x=c-'a'*(g) - 'A'*(!g) +26* (g);
        // d_bug((x));
        return links[c-'a'*(g) - 'A'*(!g) +26* (g)];
    }
    void put(char c,Node * node)
    {
        int g=(c>'Z');
        int x=c-'a'*(g) - 'A'*(!g) +26* (g);
        // d_bug((x));
        links[c-'a'*(g) - 'A'*(!g) +26* (g)]=node;
    }
    void finish()
    {
        isEnd=true;
    }
    void increase()
    {
        cnt++;
    }
    ~Node() {
    for (int i = 0; i < 2 * 26; i++) {
        if (links[i]) delete links[i];
        links[i] = nullptr;
    }
}
};
class Trie{
    public:
    Node * root;
    Trie()
    {
        root=new Node();
    }
    void insert(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(node->get(s[i])==nullptr)
            {
                // d_bug(s[i]);
                node->put(s[i],new Node());
            }
            int g=(s[i]>'Z');
            node=node->links[s[i]-'a'*(g) - 'A'*(!g) +26* (g)];
        }
        node->finish();
        node->increase();
    }
    int search(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(node->get(s[i])==nullptr)
            {
                return 1;
            }
            int g=(s[i]>'Z');
            node=node->links[s[i]-'a'*(g) - 'A'*(!g) +26* (g)];
        }
        if(node->isEnd){
            return node->cnt;
        }
        else {
            return 1;
        }
    }
    ~Trie()
    {
        delete root;
    }
};
