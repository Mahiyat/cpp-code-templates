/*
***Queries***
1 s: Insert string s in dictionary
2 s: Find the occurrence of s in dictionary
3 s: Delete s from dictionary
*/

#include<bits/stdc++.h>
using namespace std;

struct trienode
{
    trienode* child[30];
    int wordend;
    trienode()
    {
        int i;
        for(i=0;i<26;i++)child[i]=NULL;
        wordend=0;
    }
} *root;

void Insert(string s)
{
    int i,n=s.size(),id;
    trienode *curr=root;
    for(i=0;i<n;i++)
    {
        id=s[i]-'a';
        if(curr->child[id]==NULL)curr->child[id]=new trienode();
        curr=curr->child[id];
    }
    curr->wordend=curr->wordend+1;
}

int Search(string s)
{
    int i,n=s.size(),id;
    trienode *curr=root;
    for(i=0;i<n;i++)
    {
        id=s[i]-'a';
        if(curr->child[id]==NULL)return 0;
        curr=curr->child[id];
    }
    return curr->wordend;
}

void DeleteNode(string s)
{
    int i,n=s.size(),id;
    trienode *curr=root;
    for(i=0;i<n;i++)
    {
        id=s[i]-'a';
        if(curr->child[id]==NULL)return;
        curr=curr->child[id];
    }
    if(curr->wordend)curr->wordend=curr->wordend-1;
}

void del(trienode* curr)
{
    int i;
    for(i=0;i<26;i++)if(curr->child[i])del(curr->child[i]);
    delete(curr);
}

int main()
{
    root=new trienode();
    int i,n,f,t;
    string s;
    cout<<"***Queries***\n";
    cout<<"1 s: Insert string s in dictionary\n";
    cout<<"2 s: Find the occurrence of s in dictionary\n";
    cout<<"3 s: Delete s from dictionary\n";
    cout<<"Enter the number of queries: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the query type and string: ";
        cin>>t>>s;
        if(t==1)Insert(s);
        else if(t==2)
        {
            f=Search(s);
            cout<<"Number of occurrences of "<<s<<": "<<f<<"\n";
        }
        else DeleteNode(s);
    }
    del(root);
    return 0;
}
