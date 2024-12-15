//
// Created by Gaurav Kesh Roushan on 15/12/24.
//
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{

private :
    Node* findTail(Node *head){
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* left = head;
        Node* right =findTail(head);
        vector<pair<int,int>> mm;
        while(left->data<right->data){
            if((left->data+right->data)==target ){
                mm.push_back(make_pair(left->data,right->data));
                left = left->next;
                right = right->prev;
            }else if((left->data+right->data)<target ){
                 left = left->next;
            }else{
                 right = right->prev;
            }

        }
        return mm;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";

cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends