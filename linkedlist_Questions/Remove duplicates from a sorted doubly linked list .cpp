//
// Created by Gaurav Kesh Roushan on 15/12/24.
//
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node * next;
	Node * prev;
	Node (int x)
	{
		data=x;
		next=NULL;
		prev=NULL;
	}

};

Node *newNode(int data)
{
	Node *temp=new Node(data);

	return temp;
}




void displayList(Node *head)
{
	//Head to Tail
	while(head->next)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<head->data;



}


int getLength(Node * head)
{
	Node *temp=head;

	int count=0;
	while(temp->next!=head)
	{
		count++;
		temp=temp->next;
	}
	return count+1;
}




bool verify(Node* head)
{
	int fl=0;
	int bl=0;

	Node *temp=head;

	while(temp->next)
	{
		temp=temp->next;
		fl++;
	}

	while(temp->prev)
	{
		temp=temp->prev;
		bl++;
	}

	return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution
{
public:

	Node * removeDuplicates(struct Node *head){
		if (head == NULL || head->next == NULL)
			return head;

		unordered_set<int> seen;
		Node* current = head;

		while (current != NULL)
		{

			if (seen.find(current->data) != seen.end())
			{
				Node* toDelete = current;
				if (current->prev)
					current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;

				// Move to the next node
				current = current->next;
				if (toDelete == head)
					head = current;

				delete toDelete;
			}
			else
			{
				seen.insert(current->data);
				current = current->next;
			}
		}

		return head;
	}

};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Node *head=NULL, *tail=NULL;
		int x;
		cin>>x;
		head = newNode(x);
		tail = head;

		for(int i=0;i<n - 1;i++)
		{
			cin>>x;
			Node* temp=newNode(x);
			tail->next=temp;
			temp->prev= tail;
			tail = temp;
		}
		Solution obj;
		head=obj.removeDuplicates(head);


		if(verify(head))
			displayList(head);
		else
			cout<<"Your pointers are not correctly connected";

		cout<<endl;

		cout << "~" << "\n";
	}
	return 0;
}
// } Driver Code Ends